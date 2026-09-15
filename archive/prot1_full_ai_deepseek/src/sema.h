#pragma once

#include "ast.h"

#include <string>
#include <unordered_map>
#include <vector>

// Function signature registry.
struct FnSig {
    std::string retType;
    std::vector<std::string> paramTypes;
};

// Semantic analysis: symbol tables, type checking, expression type resolution.
// It records the resolved type of every expression in exprTypes_ so the
// code generator can query it without recomputing.
class Sema {
public:
    // Runs checks over the whole program. Throws std::runtime_error on the
    // first semantic error. Populates exprTypes_ for use by Codegen.
    void check(Program& prog);

    // Resolved type of an expression ("int" | "str" | "bool" | "void").
    std::string exprType(const Expr& e) const {
        auto it = exprTypes_.find(&e);
        return it != exprTypes_.end() ? it->second : "";
    }

private:
    // Pre-pass: collect all function signatures so calls can be forward-referenced.
    void collectFnSigs(Program& prog);
    void checkStmt(Stmt& s);
    std::string checkExpr(Expr& e);
    std::string lookupVar(const std::string& name) const;
    void declareVar(const std::string& name, const std::string& type);
    void pushScope();
    void popScope();
    void errorAt(const Token& t, const std::string& msg) const;

    std::unordered_map<const Expr*, std::string> exprTypes_;
    std::unordered_map<std::string, FnSig> fns_;
    std::vector<std::unordered_map<std::string, std::string>> scopes_;
    std::string currentRetType_;
};