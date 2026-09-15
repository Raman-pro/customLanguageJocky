#include "ast.h"
#include "codegen.h"
#include "lexer.h"
#include "obfuscate.h"
#include "parser.h"
#include "postprocess.h"
#include "sema.h"

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

// ---- AST dump (for --ast) ------------------------------------------------

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

// ---- helpers ----------------------------------------------------------------

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
        "JOCKY compiler (v0.1)\n"
        "usage: jocky [options] <file.jk>\n"
        "  --tokens          dump token stream\n"
        "  --ast             dump AST\n"
        "  --check           semantic check only (no output)\n"
        "  --emit-c          print generated C to stdout\n"
        "  -o <file.c>       write generated C to a file\n"
        "  --build           write C and invoke a C compiler\n"
        "  --target <t>      for --build: linux (default) | mingw (Windows exe)\n"
        "  --seed <n>        polymorphism seed (-1 = no renaming, default = random)\n"
        "  --obf-level <0-3> CFG obfuscation level (default: 2 when --seed used, else 0)\n"
        "                      0 none | 1 opaque preds + dead code\n"
        "                      2 + CFG flattening + bogus CF + string encryption\n"
        "                      3 + constant noise + trampolines + junk functions\n";
}

int main(int argc, char** argv) {
    bool dumpTokens = false, dumpAst = false, checkOnly = false, emitC = false;
    bool doBuild = false;
    std::string inFile, outFile, target = "linux";
    int64_t seed = -2;  // -2 => random (choose at codegen)
    int obfLevel = -1;  // -1 => auto (2 when --seed used, else 0)

    for (int i = 1; i < argc; ++i) {
        std::string a = argv[i];
        if (a == "--tokens") dumpTokens = true;
        else if (a == "--ast") dumpAst = true;
        else if (a == "--check") checkOnly = true;
        else if (a == "--emit-c") emitC = true;
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
        }

        Parser parser(tokens);
        Program prog = parser.parse();

        if (dumpAst) {
            for (auto& s : prog.stmts) dumpStmt(*s, 0);
        }

        Sema sema;
        sema.check(prog);
        if (checkOnly) { std::cout << "OK\n"; return 0; }

        // AST-level obfuscation passes run after sema (so injected nodes never
        // need a type check) and before codegen.
        if (obfLevel >= 1) {
            std::mt19937_64 obfRng(seed >= 0 ? static_cast<uint64_t>(seed) : std::random_device{}());
            obfuscate::run(prog, obfRng, obfLevel);
        }

        Codegen codegen(sema, seed, obfLevel);
        std::string c = codegen.emit(prog);

        // C-level post-processing on the emitted source.
        if (obfLevel >= 2) {
            std::mt19937_64 postRng(seed >= 0 ? static_cast<uint64_t>(seed) + 1 : std::random_device{}());
            c = postprocess::run(std::move(c), postRng, obfLevel);
        }

        if (emitC) { std::cout << c; return 0; }

        if (!outFile.empty()) {
            writeFile(outFile, c);
            std::cout << "wrote " << outFile << "\n";
            return 0;
        }

        if (doBuild) {
            // <file>.jk -> <file>.c -> <file> (or .exe)
            std::string base = inFile.substr(0, inFile.find_last_of('.'));
            std::string cfile = base + ".c";
            writeFile(cfile, c);

            std::string compiler = "cc";
            std::string exe = base;
            std::string libs;
            if (target == "mingw") {
                compiler = "x86_64-w64-mingw32-gcc";
                exe += ".exe";
                libs = " -lws2_32 -liphlpapi -ladvapi32";
            } else if (target != "linux") {
                throw std::runtime_error("unknown --target '" + target + "' (use linux or mingw)");
            }
            std::string cmd = compiler + " -O2 -o " + exe + " " + cfile + libs;
            std::cout << "$ " << cmd << "\n";
            int rc = std::system(cmd.c_str());
            if (rc != 0) { std::cout << "compilation failed\n"; return 1; }
            std::cout << "built " << exe << "\n";
            return 0;
        }

        // default: emit to stdout
        std::cout << c;
        return 0;
    } catch (const std::exception& e) {
        std::cerr << e.what() << "\n";
        return 1;
    }
}