#include "ast.h"
#include "codegen.h"
#include "lexer.h"
#include "obfuscate.h"
#include "parser.h"
#include "sema.h"

#include <llvm/IR/LegacyPassManager.h>
#include <llvm/IR/PassManager.h>
#include <llvm/MC/TargetRegistry.h>
#include <llvm/Passes/PassBuilder.h>
#include <llvm/Passes/StandardInstrumentations.h>
#include <llvm/Support/CodeGen.h>
#include <llvm/Support/FileSystem.h>
#include <llvm/Support/raw_ostream.h>
#include <llvm/Support/TargetSelect.h>
#include <llvm/Target/TargetMachine.h>
#include <llvm/Target/TargetOptions.h>
#include <llvm/TargetParser/Host.h>
#include <llvm/TargetParser/Triple.h>

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

// ---- AST dump (same shape as prot1 so `--ast` output is familiar) ------------

static void dumpExpr(const Expr& e, int depth);
static void dumpStmt(const Stmt& s, int depth) {
    auto pad = [&]() { std::cout << std::string(static_cast<size_t>(depth) * 2, ' '); };
    switch (s.kind) {
        case Stmt::K::Let:
            pad(); std::cout << "Let " << s.varName;
            if (!s.varType.empty()) std::cout << " : " << s.varType;
            if (s.init) { std::cout << " ="; dumpExpr(*s.init, depth + 1); }
            std::cout << "\n"; break;
        case Stmt::K::ExprStmt:
            pad(); std::cout << "ExprStmt\n"; dumpExpr(*s.init, depth + 1); break;
        case Stmt::K::If:
            pad(); std::cout << "If\n"; dumpExpr(*s.cond, depth + 1);
            pad(); std::cout << "  Then:\n";
            for (auto& st : s.thenBody) dumpStmt(*st, depth + 2);
            if (!s.elseBody.empty()) {
                pad(); std::cout << "  Else:\n";
                for (auto& st : s.elseBody) dumpStmt(*st, depth + 2);
            }
            break;
        case Stmt::K::While:
            pad(); std::cout << "While\n"; dumpExpr(*s.loopCond, depth + 1);
            for (auto& st : s.body) dumpStmt(*st, depth + 1);
            break;
        case Stmt::K::For:
            pad(); std::cout << "For\n";
            dumpStmt(*s.forInit, depth + 1);
            pad(); std::cout << "  Cond:"; dumpExpr(*s.forCond, depth + 1);
            pad(); std::cout << "  Step:"; dumpExpr(*s.forStep, depth + 1);
            for (auto& st : s.body) dumpStmt(*st, depth + 1);
            break;
        case Stmt::K::Return:
            pad(); std::cout << "Return";
            if (s.retExpr) dumpExpr(*s.retExpr, depth + 1);
            std::cout << "\n"; break;
        case Stmt::K::Fn:
            pad(); std::cout << "Fn " << s.fnName << " -> " << s.fnRetType << " (";
            for (size_t i = 0; i < s.params.size(); ++i) {
                if (i) std::cout << ", ";
                std::cout << s.params[i].first << ":" << s.params[i].second;
            }
            std::cout << ")\n";
            for (auto& st : s.fnBody) dumpStmt(*st, depth + 1);
            break;
        case Stmt::K::Switch:
            pad(); std::cout << "Switch\n";
            dumpExpr(*s.switchExpr, depth + 1);
            for (auto& c : s.cases) {
                pad(); std::cout << "Case " << c.first << ":\n";
                for (auto& st : c.second) dumpStmt(*st, depth + 2);
            }
            break;
    }
}

static void dumpExpr(const Expr& e, int depth) {
    auto pad = [&]() { std::cout << std::string(static_cast<size_t>(depth) * 2, ' '); };
    switch (e.kind) {
        case Expr::K::IntLit: pad(); std::cout << "IntLit(" << e.iVal << ")\n"; break;
        case Expr::K::StrLit: pad(); std::cout << "StrLit(\"" << e.name << "\")\n"; break;
        case Expr::K::BoolLit: pad(); std::cout << "BoolLit(" << (e.iVal ? "true" : "false") << ")\n"; break;
        case Expr::K::Ident: pad(); std::cout << "Ident(" << e.name << ")\n"; break;
        case Expr::K::Unary:
            pad(); std::cout << "Unary(" << e.op << ")\n"; dumpExpr(*e.lhs, depth + 1); break;
        case Expr::K::Binary:
            pad(); std::cout << "Binary(" << e.op << ")\n";
            dumpExpr(*e.lhs, depth + 1); dumpExpr(*e.rhs, depth + 1); break;
        case Expr::K::Call:
            pad(); std::cout << "Call(" << e.name << ")\n";
            for (auto& a : e.args) dumpExpr(*a, depth + 1);
            break;
    }
}

// ---- helpers -------------------------------------------------------------------

static std::string readFile(const std::string& path) {
    std::ifstream f(path, std::ios::binary);
    if (!f) throw std::runtime_error("cannot open file: " + path);
    std::ostringstream ss;
    ss << f.rdbuf();
    return ss.str();
}

static void writeFile(const std::string& path, const std::string& text) {
    std::ofstream f(path, std::ios::binary);
    if (!f) throw std::runtime_error("cannot write file: " + path);
    f << text;
}

static void usage() {
    std::cout <<
        "jocky (LLVM backend) v0.1\n"
        "usage: jocky [options] <file.rd>\n"
        "  --tokens          dump token stream\n"
        "  --ast             dump AST\n"
        "  --check           semantic check only (no output)\n"
        "  --emit-ir         print generated LLVM IR to stdout\n"
        "  -o <file.ll>      write generated LLVM IR to a file\n"
        "  --build           optimize + emit object + link against the runtime\n"
        "  --target <t>      for --build: native (default) | mingw (Windows exe)\n"
        "  --seed <n>        polymorphism seed (-1 = no renaming, default = random)\n"
        "  --obf-level <0-3> obfuscation level (default: 2 when --seed used, else 0)\n"
        "                      0 none | 1 opaque predicates\n"
        "                      2 + string encryption + junk functions\n"
        "                      3 + entry-point trampoline\n";
}

// Optimize the module at O2 with the new pass manager, then emit an object file.
static bool emitObject(llvm::Module& M, llvm::TargetMachine& TM, const std::string& path) {
    M.setDataLayout(TM.createDataLayout());
    M.setTargetTriple(TM.getTargetTriple());

    // ---- new pass manager optimization (O2) ----
    llvm::LoopAnalysisManager LAM;
    llvm::FunctionAnalysisManager FAM;
    llvm::CGSCCAnalysisManager CGAM;
    llvm::ModuleAnalysisManager MAM;
    llvm::PassInstrumentationCallbacks PIC;
    llvm::StandardInstrumentations SI(M.getContext(), /*DebugLogging=*/false);
    SI.registerCallbacks(PIC, &MAM);
    llvm::PassBuilder PB(&TM, llvm::PipelineTuningOptions(), std::nullopt, &PIC);
    PB.registerModuleAnalyses(MAM);
    PB.registerCGSCCAnalyses(CGAM);
    PB.registerFunctionAnalyses(FAM);
    PB.registerLoopAnalyses(LAM);
    PB.crossRegisterProxies(LAM, FAM, CGAM, MAM);
    llvm::ModulePassManager MPM = PB.buildPerModuleDefaultPipeline(llvm::OptimizationLevel::O2);
    MPM.run(M, MAM);

    // ---- emit object via legacy codegen pass manager ----
    std::error_code EC;
    llvm::raw_fd_ostream dest(path, EC, llvm::sys::fs::OF_None);
    if (EC) { std::cerr << "cannot open object file " << path << ": " << EC.message() << "\n"; return false; }
    llvm::legacy::PassManager PM;
    if (TM.addPassesToEmitFile(PM, dest, nullptr, llvm::CodeGenFileType::ObjectFile)) {
        std::cerr << "target does not support object emission\n";
        return false;
    }
    PM.run(M);
    return true;
}

int main(int argc, char** argv) {
    bool dumpTokens = false, dumpAst = false, checkOnly = false, emitIR = false;
    bool doBuild = false;
    std::string inFile, outFile, target = "native";
    int64_t seed = -2;   // -2 => random
    int obfLevel = -1;   // -1 => auto (2 when --seed used, else 0)

    for (int i = 1; i < argc; ++i) {
        std::string a = argv[i];
        if (a == "--tokens") dumpTokens = true;
        else if (a == "--ast") dumpAst = true;
        else if (a == "--check") checkOnly = true;
        else if (a == "--emit-ir") emitIR = true;
        else if (a == "--build") doBuild = true;
        else if (a == "-o" && i + 1 < argc) outFile = argv[++i];
        else if (a == "--target" && i + 1 < argc) target = argv[++i];
        else if (a == "--seed" && i + 1 < argc) seed = std::stoll(argv[++i]);
        else if (a == "--obf-level" && i + 1 < argc) obfLevel = std::stoi(argv[++i]);
        else if (!a.empty() && a[0] != '-') inFile = a;
        else { usage(); return 1; }
    }

    if (inFile.empty()) { usage(); return 1; }
    if (obfLevel < 0) obfLevel = (seed >= 0) ? 2 : 0;
    if (obfLevel < 0 || obfLevel > 3) { usage(); return 1; }

    try {
        std::string src = readFile(inFile);

        Lexer lexer(src);
        auto tokens = lexer.tokenize();

        if (dumpTokens) {
            for (auto& t : tokens) {
                std::cout << token_name(t.kind) << "  '" << t.text << "'  [" << t.line << ":" << t.col << "]\n";
            }
            return 0;
        }

        Parser parser(tokens);
        Program prog = parser.parse();

        if (dumpAst) {
            for (auto& s : prog.stmts) dumpStmt(*s, 0);
            return 0;
        }

        Sema sema;
        sema.check(prog);
        if (checkOnly) { std::cout << "OK\n"; return 0; }

        // Codegen -> LLVM IR module.
        Codegen codegen(sema, seed, obfLevel);
        auto mod = codegen.emit(prog);

        // IR-level obfuscation passes (polymorphism).
        if (obfLevel >= 1) {
            std::mt19937_64 obfRng(seed >= 0 ? static_cast<uint64_t>(seed) + 1 : std::random_device{}());
            obfuscate::run(*mod, obfRng, obfLevel);
        }

        if (emitIR) { mod->print(llvm::outs(), nullptr); return 0; }

        if (!outFile.empty()) {
            std::string ir;
            llvm::raw_string_ostream os(ir);
            mod->print(os, nullptr);
            os.flush();
            writeFile(outFile, ir);
            std::cout << "wrote " << outFile << "\n";
            return 0;
        }

        if (doBuild) {
            // Init LLVM codegen for the requested target.
            llvm::InitializeAllTargetInfos();
            llvm::InitializeAllTargets();
            llvm::InitializeAllTargetMCs();
            llvm::InitializeAllAsmPrinters();

            std::string tripleStr;
            std::string compiler, cexe;
            std::string libs;
            if (target == "mingw") {
                tripleStr = "x86_64-pc-windows-gnu";
                compiler = "x86_64-w64-mingw32-gcc";
                cexe = ".exe";
                libs = " -lws2_32 -liphlpapi -ladvapi32";
            } else if (target == "native" || target == "linux") {
                tripleStr = llvm::sys::getDefaultTargetTriple();
                compiler = "cc";
            } else {
                throw std::runtime_error("unknown --target '" + target + "' (use native or mingw)");
            }

            llvm::Triple triple(tripleStr);
            std::string err;
            const llvm::Target* tgt = llvm::TargetRegistry::lookupTarget(triple, err);
            if (!tgt) throw std::runtime_error("LLVM: " + err);

            llvm::TargetOptions topts;
            auto* tm = tgt->createTargetMachine(triple, "generic", "", topts, std::nullopt);
            if (!tm) throw std::runtime_error("cannot create target machine for " + tripleStr);

            std::string base = inFile.substr(0, inFile.find_last_of('.'));
            std::string obj = base + ".o";
            std::string runtimeObj = base + "_rt.o";

            if (!emitObject(*mod, *tm, obj)) return 1;

            // Compile the forensic runtime and link.
            std::string rccmd = compiler + " -O2 -c " + JOCKY_RUNTIME_C + " -o " + runtimeObj;
            std::cout << "$ " << rccmd << "\n";
            if (std::system(rccmd.c_str()) != 0) {
                std::cout << "runtime compilation failed\n";
                return 1;
            }
            std::string exe = base + cexe;
            std::string link = compiler + " -O2 -o " + exe + " " + obj + " " + runtimeObj + libs;
            std::cout << "$ " << link << "\n";
            if (std::system(link.c_str()) != 0) {
                std::cout << "link failed\n";
                return 1;
            }
            std::cout << "built " << exe << "\n";
            return 0;
        }

        // default: print IR
        mod->print(llvm::outs(), nullptr);
        return 0;
    } catch (const std::exception& e) {
        std::cerr << e.what() << "\n";
        return 1;
    }
}