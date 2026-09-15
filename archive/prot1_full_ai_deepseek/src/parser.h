#pragma once

#include "ast.h"

#include <vector>

// Recursive-descent parser: token stream -> AST.
class Parser {
public:
    explicit Parser(std::vector<Token> tokens);

    // Parses the whole program. Throws std::runtime_error on syntax errors.
    Program parse();

private:
    // Helpers
    const Token& peek() const;
    const Token& previous() const;
    const Token& advance();
    bool check(Tok k) const;
    bool match(Tok k);
    const Token& expect(Tok k, const std::string& what);
    [[noreturn]] void error(const std::string& msg) const;
    [[noreturn]] void errorAt(const Token& t, const std::string& msg) const;

    // Grammar
    StmtPtr parseTopLevel();
    StmtPtr parseFnDecl();
    StmtPtr parseDeclOrStmt();
    StmtPtr parseStmt();
    StmtPtr parseLet();
    StmtPtr parseIf();
    StmtPtr parseWhile();
    StmtPtr parseFor();
    StmtPtr parseReturn();
    ExprPtr parseExpr();
    ExprPtr parseAssign();
    ExprPtr parseLogicalOr();
    ExprPtr parseLogicalAnd();
    ExprPtr parseEquality();
    ExprPtr parseRelational();
    ExprPtr parseAdditive();
    ExprPtr parseMultiplicative();
    ExprPtr parseUnary();
    ExprPtr parseCall();
    ExprPtr parsePrimary();
    std::string parseTypeName();

    std::vector<Token> tokens_;
    size_t cur_ = 0;
};