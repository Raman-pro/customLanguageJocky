#include "parser.h"

#include <stdexcept>

Parser::Parser(std::vector<Token> tokens) : tokens_(std::move(tokens)) {}

const Token& Parser::peek() const { return tokens_[cur_]; }
const Token& Parser::previous() const { return tokens_[cur_ - 1]; }
const Token& Parser::advance() {
    if (!check(Tok::End)) cur_++;
    return previous();
}
bool Parser::check(Tok k) const { return peek().kind == k; }
bool Parser::match(Tok k) {
    if (check(k)) { advance(); return true; }
    return false;
}

const Token& Parser::expect(Tok k, const std::string& what) {
    if (!check(k)) error("expected " + what + ", got '" + peek().text + "'");
    return advance();
}

void Parser::errorAt(const Token& t, const std::string& msg) const {
    throw std::runtime_error("parse error at line " + std::to_string(t.line) + ", col " +
                             std::to_string(t.col) + ": " + msg);
}

void Parser::error(const std::string& msg) const { errorAt(peek(), msg); }

Program Parser::parse() {
    Program prog;
    while (!check(Tok::End)) {
        prog.stmts.push_back(parseTopLevel());
    }
    return prog;
}

StmtPtr Parser::parseTopLevel() {
    if (match(Tok::KwFn)) return parseFnDecl();
    return parseDeclOrStmt();
}

// fn name(params) [: ret] { body }
StmtPtr Parser::parseFnDecl() {
    auto stmt = std::make_unique<Stmt>();
    stmt->kind = Stmt::K::Fn;
    stmt->tok = previous();

    stmt->fnName = expect(Tok::Ident, "function name").text;
    expect(Tok::LParen, "'('");
    if (!check(Tok::RParen)) {
        do {
            std::string pname = expect(Tok::Ident, "parameter name").text;
            expect(Tok::Colon, "':'");
            std::string ptype = parseTypeName();
            stmt->params.emplace_back(pname, ptype);
        } while (match(Tok::Comma));
    }
    expect(Tok::RParen, "')'");

    if (match(Tok::Colon)) stmt->fnRetType = parseTypeName();
    else stmt->fnRetType = "void";

    expect(Tok::LBrace, "'{'");
    while (!check(Tok::RBrace)) {
        if (check(Tok::End)) error("unterminated function body");
        stmt->fnBody.push_back(parseStmt());
    }
    expect(Tok::RBrace, "'}'");
    return stmt;
}

StmtPtr Parser::parseDeclOrStmt() {
    if (check(Tok::KwLet)) return parseLet();
    return parseStmt();
}

StmtPtr Parser::parseStmt() {
    if (match(Tok::KwIf)) return parseIf();
    if (match(Tok::KwWhile)) return parseWhile();
    if (match(Tok::KwFor)) return parseFor();
    if (match(Tok::KwReturn)) return parseReturn();
    if (match(Tok::KwLet)) return parseLet();

    // Expression statement
    auto stmt = std::make_unique<Stmt>();
    stmt->kind = Stmt::K::ExprStmt;
    stmt->tok = peek();
    stmt->init = parseExpr();
    expect(Tok::Semicolon, "';'");
    return stmt;
}

// let name [: type] = expr;
StmtPtr Parser::parseLet() {
    auto stmt = std::make_unique<Stmt>();
    stmt->kind = Stmt::K::Let;
    stmt->tok = previous();
    stmt->varName = expect(Tok::Ident, "variable name").text;
    if (match(Tok::Colon)) stmt->varType = parseTypeName();
    if (match(Tok::Assign)) stmt->init = parseExpr();
    else if (stmt->varType.empty()) error("variable '" + stmt->varName + "' needs a type or initializer");
    expect(Tok::Semicolon, "';'");
    return stmt;
}

StmtPtr Parser::parseIf() {
    auto stmt = std::make_unique<Stmt>();
    stmt->kind = Stmt::K::If;
    stmt->tok = previous();
    expect(Tok::LParen, "'('");
    stmt->cond = parseExpr();
    expect(Tok::RParen, "')'");

    expect(Tok::LBrace, "'{'");
    while (!check(Tok::RBrace)) {
        if (check(Tok::End)) error("unterminated if body");
        stmt->thenBody.push_back(parseStmt());
    }
    expect(Tok::RBrace, "'}'");

    if (match(Tok::KwElse)) {
        expect(Tok::LBrace, "'{'");
        while (!check(Tok::RBrace)) {
            if (check(Tok::End)) error("unterminated else body");
            stmt->elseBody.push_back(parseStmt());
        }
        expect(Tok::RBrace, "'}'");
    }
    return stmt;
}

StmtPtr Parser::parseWhile() {
    auto stmt = std::make_unique<Stmt>();
    stmt->kind = Stmt::K::While;
    stmt->tok = previous();
    expect(Tok::LParen, "'('");
    stmt->loopCond = parseExpr();
    expect(Tok::RParen, "')'");
    expect(Tok::LBrace, "'{'");
    while (!check(Tok::RBrace)) {
        if (check(Tok::End)) error("unterminated while body");
        stmt->body.push_back(parseStmt());
    }
    expect(Tok::RBrace, "'}'");
    return stmt;
}

StmtPtr Parser::parseFor() {
    auto stmt = std::make_unique<Stmt>();
    stmt->kind = Stmt::K::For;
    stmt->tok = previous();
    expect(Tok::LParen, "'('");
    match(Tok::KwLet);  // 'for' always starts with 'let'
    stmt->forInit = parseLet();
    stmt->forCond = parseExpr();
    expect(Tok::Semicolon, "';'");
    stmt->forStep = parseExpr();
    expect(Tok::RParen, "')'");
    expect(Tok::LBrace, "'{'");
    while (!check(Tok::RBrace)) {
        if (check(Tok::End)) error("unterminated for body");
        stmt->body.push_back(parseStmt());
    }
    expect(Tok::RBrace, "'}'");
    return stmt;
}

StmtPtr Parser::parseReturn() {
    auto stmt = std::make_unique<Stmt>();
    stmt->kind = Stmt::K::Return;
    stmt->tok = previous();
    if (!check(Tok::Semicolon)) stmt->retExpr = parseExpr();
    expect(Tok::Semicolon, "';'");
    return stmt;
}

// ---- Expressions (precedence climbing) ----

ExprPtr Parser::parseExpr() { return parseAssign(); }

// Assignment is lowest precedence, right-associative: a = b = c
ExprPtr Parser::parseAssign() {
    ExprPtr lhs = parseLogicalOr();
    if (match(Tok::Assign)) {
        auto e = std::make_unique<Expr>();
        e->kind = Expr::K::Binary;
        e->tok = previous();
        e->op = "=";
        e->lhs = std::move(lhs);
        e->rhs = parseAssign();  // right-assoc
        return e;
    }
    return lhs;
}

ExprPtr Parser::parseLogicalOr() {
    ExprPtr lhs = parseLogicalAnd();
    while (match(Tok::OrOr)) {
        auto e = std::make_unique<Expr>();
        e->kind = Expr::K::Binary;
        e->tok = previous();
        e->op = "||";
        e->lhs = std::move(lhs);
        e->rhs = parseLogicalAnd();
        lhs = std::move(e);
    }
    return lhs;
}

ExprPtr Parser::parseLogicalAnd() {
    ExprPtr lhs = parseEquality();
    while (match(Tok::AndAnd)) {
        auto e = std::make_unique<Expr>();
        e->kind = Expr::K::Binary;
        e->tok = previous();
        e->op = "&&";
        e->lhs = std::move(lhs);
        e->rhs = parseEquality();
        lhs = std::move(e);
    }
    return lhs;
}

ExprPtr Parser::parseEquality() {
    ExprPtr lhs = parseRelational();
    while (check(Tok::EqEq) || check(Tok::NotEq)) {
        Tok opTok = peek().kind;
        advance();
        auto e = std::make_unique<Expr>();
        e->kind = Expr::K::Binary;
        e->tok = previous();
        e->op = token_name(opTok);
        e->lhs = std::move(lhs);
        e->rhs = parseRelational();
        lhs = std::move(e);
    }
    return lhs;
}

ExprPtr Parser::parseRelational() {
    ExprPtr lhs = parseAdditive();
    while (check(Tok::Lt) || check(Tok::Le) || check(Tok::Gt) || check(Tok::Ge)) {
        Tok opTok = peek().kind;
        advance();
        auto e = std::make_unique<Expr>();
        e->kind = Expr::K::Binary;
        e->tok = previous();
        e->op = token_name(opTok);
        e->lhs = std::move(lhs);
        e->rhs = parseAdditive();
        lhs = std::move(e);
    }
    return lhs;
}

ExprPtr Parser::parseAdditive() {
    ExprPtr lhs = parseMultiplicative();
    while (check(Tok::Plus) || check(Tok::Minus)) {
        Tok opTok = peek().kind;
        advance();
        auto e = std::make_unique<Expr>();
        e->kind = Expr::K::Binary;
        e->tok = previous();
        e->op = token_name(opTok);
        e->lhs = std::move(lhs);
        e->rhs = parseMultiplicative();
        lhs = std::move(e);
    }
    return lhs;
}

ExprPtr Parser::parseMultiplicative() {
    ExprPtr lhs = parseUnary();
    while (check(Tok::Star) || check(Tok::Slash) || check(Tok::Percent)) {
        Tok opTok = peek().kind;
        advance();
        auto e = std::make_unique<Expr>();
        e->kind = Expr::K::Binary;
        e->tok = previous();
        e->op = token_name(opTok);
        e->lhs = std::move(lhs);
        e->rhs = parseUnary();
        lhs = std::move(e);
    }
    return lhs;
}

ExprPtr Parser::parseUnary() {
    if (check(Tok::Bang) || check(Tok::Minus)) {
        Tok opTok = peek().kind;
        advance();
        auto e = std::make_unique<Expr>();
        e->kind = Expr::K::Unary;
        e->tok = previous();
        e->op = token_name(opTok);
        e->lhs = parseUnary();
        return e;
    }
    return parseCall();
}

ExprPtr Parser::parseCall() {
    ExprPtr e = parsePrimary();
    while (match(Tok::LParen)) {
        auto call = std::make_unique<Expr>();
        call->kind = Expr::K::Call;
        call->tok = previous();
        if (e->kind != Expr::K::Ident) error("callee must be a function name");
        call->name = e->name;
        if (!check(Tok::RParen)) {
            do {
                call->args.push_back(parseExpr());
            } while (match(Tok::Comma));
        }
        expect(Tok::RParen, "')'");
        e = std::move(call);
    }
    return e;
}

ExprPtr Parser::parsePrimary() {
    if (match(Tok::Int)) {
        auto e = std::make_unique<Expr>();
        e->kind = Expr::K::IntLit;
        e->tok = previous();
        e->iVal = previous().ival;
        return e;
    }
    if (match(Tok::Str)) {
        auto e = std::make_unique<Expr>();
        e->kind = Expr::K::StrLit;
        e->tok = previous();
        e->name = previous().text;  // reuse name as string payload
        return e;
    }
    if (match(Tok::KwTrue) || match(Tok::KwFalse)) {
        auto e = std::make_unique<Expr>();
        e->kind = Expr::K::BoolLit;
        e->tok = previous();
        e->iVal = previous().kind == Tok::KwTrue ? 1 : 0;
        return e;
    }
    if (match(Tok::Ident)) {
        auto e = std::make_unique<Expr>();
        e->kind = Expr::K::Ident;
        e->tok = previous();
        e->name = previous().text;
        while (match(Tok::Dot)) {  // sys.process_list style names
            e->name += "." + expect(Tok::Ident, "identifier after '.'").text;
        }
        return e;
    }
    if (match(Tok::LParen)) {
        ExprPtr inner = parseExpr();
        expect(Tok::RParen, "')'");
        return inner;
    }
    error("expected an expression, got '" + peek().text + "'");
}

std::string Parser::parseTypeName() {
    Tok k = peek().kind;
    if (k != Tok::TyInt && k != Tok::TyStr && k != Tok::TyBool && k != Tok::TyVoid) {
        error("expected a type (int/str/bool/void), got '" + peek().text + "'");
    }
    return advance().text;
}