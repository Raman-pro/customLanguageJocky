#pragma once

#include "ast.h"
#include "sema.h"

#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/Module.h>

#include <memory>
#include <random>
#include <string>
#include <unordered_map>
#include <vector>

// LLVM IR code generator.
//
// Translates a sema-checked JOCKY AST directly to LLVM IR in memory (no
// intermediate C). The driver then optimizes the module, emits an object file
// and links it against the forensic runtime (runtime/runtime.c).
//
// `seed` drives the polymorphism story: when >= 0, every user symbol is renamed
// with a seeded RNG and per-build volatile build markers are added, so two
// builds of the same script produce different IR and different binaries.
//
// `obfLevel` mirrors the CLI --obf-level. Levels >= 2 also select IR-level
// string encryption and junk/trampoline passes (src/obfuscate.cpp).
class Codegen {
public:
    Codegen(Sema& sema, int64_t seed, int obfLevel);

    // Builds the module. Throws std::runtime_error on codegen errors.
    std::unique_ptr<llvm::Module> emit(const Program& prog);

private:
    // ---- types -------------------------------------------------------------
    llvm::Type* llvmType(const std::string& t);

    // ---- statements / expressions ------------------------------------------
    void emitStmt(Stmt& s);
    void emitBody(std::vector<StmtPtr>& body);   // terminate-safe body emitter
    llvm::Value* emitExpr(const Expr& e);
    llvm::Value* emitCall(const Expr& e);
    llvm::Value* emitAssign(const Expr& e);
    llvm::Value* emitShortCircuit(const Expr& e, bool isAnd);
    llvm::Value* emitBinary2(const Expr& e);

    // ---- scoping ------------------------------------------------------------
    void pushScope();
    void popScope();
    void declareVar(const std::string& name, llvm::AllocaInst* a);
    llvm::AllocaInst* lookupVar(const std::string& name);
    llvm::AllocaInst* createAlloca(llvm::Type* ty, const std::string& name);
    void emitFnParams(llvm::Function* f, Stmt& fn);

    // ---- runtime / builtins -------------------------------------------------
    llvm::FunctionCallee getRuntimeFn(const std::string& cname, llvm::Type* retTy,
                                      std::vector<llvm::Type*> args, bool vararg = false);
    llvm::Value* getCString(const std::string& s);
    llvm::Value* getPrintFormat(const std::string& type);

    // ---- polymorphism --------------------------------------------------------
    std::string cname(const std::string& name);
    void registerName(const std::string& name);
    std::string randName();
    std::string emitBuildMarker();
    void addBuildMarkersToModule();

    // ---- string encryption (obfLevel >= 2) ----------------------------------
    llvm::Value* emitStringLiteral(const std::string& s);

    // ---- state ---------------------------------------------------------------
    Sema& sema_;
    int64_t seed_;
    int obfLevel_;
    std::mt19937_64 rng_;
    std::unordered_map<std::string, std::string> renames_;
    std::unordered_map<std::string, llvm::AllocaInst*> currentScope_;
    std::vector<std::unordered_map<std::string, llvm::AllocaInst*>> scopes_;
    llvm::LLVMContext ctx_;
    std::unique_ptr<llvm::Module> mod_;
    llvm::IRBuilder<> builder_{ctx_};
    llvm::BasicBlock* entryBlock_ = nullptr;     // alloca insertion point
    llvm::Function* curFn_ = nullptr;
    std::unordered_map<std::string, llvm::Function*> strDecryptors_;  // string -> decryptor fn
    std::unordered_map<std::string, llvm::Value*> cstrings_;          // literal -> global ptr
    std::vector<llvm::GlobalVariable*> markers_;
    bool markersAdded_ = false;
};