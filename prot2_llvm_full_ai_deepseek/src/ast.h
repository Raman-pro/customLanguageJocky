#pragma once

#include "token.h"

#include <memory>
#include <string>
#include <utility>
#include <vector>

// Expressions ---------------------------------------------------------------
struct Expr {
    enum class K { IntLit, StrLit, BoolLit, Ident, Unary, Binary, Call };
    K kind;
    Token tok;

    int64_t iVal = 0;            // IntLit
    std::string name;            // Ident (and Callee name for Call)
    std::string op;              // Unary / Binary operator text ("+", "==", "!")
    std::unique_ptr<Expr> lhs;   // Unary operand / Binary lhs
    std::unique_ptr<Expr> rhs;   // Binary rhs
    std::vector<std::unique_ptr<Expr>> args;  // Call arguments
};

using ExprPtr = std::unique_ptr<Expr>;

// Statements -----------------------------------------------------------------
struct Stmt;
using StmtPtr = std::unique_ptr<Stmt>;

struct Stmt {
    enum class K {
        Let,        // let name [: type] = init;
        If,         // if (cond) then else
        While,      // while (cond) body
        For,        // for (init; cond; step) body
        Return,     // return [expr];
        ExprStmt,   // expr;
        Fn,         // fn name(params) [: ret] { body }
        Switch      // internal only: produced by the CFG-obfuscation pass (flattening)
    };
    K kind;
    Token tok;

    // Let
    std::string varName;
    std::string varType;         // "int" | "str" | "bool" | "" (inferred)
    ExprPtr init;

    // If
    ExprPtr cond;
    std::vector<StmtPtr> thenBody;
    std::vector<StmtPtr> elseBody;

    // While / For / Fn body
    ExprPtr loopCond;
    std::vector<StmtPtr> body;

    // For
    StmtPtr forInit;             // Let
    ExprPtr forCond;
    ExprPtr forStep;

    // Return
    ExprPtr retExpr;

    // Fn
    std::string fnName;
    std::string fnRetType;       // "int" | "str" | "bool" | "void"
    std::vector<std::pair<std::string, std::string>> params;  // (name, type)
    std::vector<StmtPtr> fnBody;

    // Switch (internal, produced by obfuscation flattening)
    ExprPtr switchExpr;                                 // dispatch expression
    std::vector<std::pair<int64_t, std::vector<StmtPtr>>> cases;  // (case value, body)
    std::vector<StmtPtr> defaultCase;                   // default body
};

// Program = list of top-level statements (functions, global lets).
struct Program {
    std::vector<StmtPtr> stmts;
};