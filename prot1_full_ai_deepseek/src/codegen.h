#pragma once

#include "ast.h"
#include "sema.h"

#include <random>
#include <string>
#include <unordered_map>

// Transpiles a JOCKY AST into C source text.
// When `polySeed >= 0`, all user identifiers are renamed with a per-build
// RNG, so two builds of the same script emit different C and thus different
// binaries (the "custom tokens" / polymorphism story). Default (-1) = no rename.
class Codegen {
public:
    Codegen(Sema& sema, int64_t polySeed);

    // Returns the generated C program text.
    std::string emit(const Program& prog);

private:
    void emitStmt(Stmt& s);
    std::string emitExpr(const Expr& e);
    std::string emitCall(const Expr& e);

    std::string cname(const std::string& name);        // apply rename map
    void registerName(const std::string& name);        // declare a user identifier
    static std::string typeToC(const std::string& t);
    static std::string escape(const std::string& s);
    std::string randName();                            // fresh random identifier
    void injectOpaquePredicates();                     // unprovable if/else guards
    std::string emitBuildMarker();                     // volatile global with random value

    void line(const std::string& text);
    void openBlock();
    void closeBlock();

    Sema& sema_;
    int64_t polySeed_;
    std::mt19937_64 rng_;
    std::unordered_map<std::string, std::string> renames_;
    std::string out_;
    int indent_ = 0;
    bool emitBuildHeader_ = true;
    std::vector<Stmt*> topLevelStmts_;   // non-function statements for main
    Stmt* mainFn_ = nullptr;
    bool markersEmitted_ = false;
};