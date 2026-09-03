#include "sema.h"

#include <stdexcept>
#include <utility>

// Builtin (forensics stdlib) signatures. "print"/"len" are special-cased
// because print accepts any non-void type.
static const std::unordered_map<std::string, FnSig> kBuiltins = {
    {"sys.process_list", {"str", {}}},
    {"sys.cwd",          {"str", {}}},
    {"sys.now",          {"str", {}}},
    {"sys.sleep",        {"void", {"int"}}},
    {"env.get",          {"str", {"str"}}},
    {"net.sockets",      {"str", {}}},
    {"fs.read",          {"str", {"str"}}},
    {"fs.write",         {"void", {"str", "str"}}},
    {"fs.list",          {"str", {"str"}}},
    {"fs.exists",        {"bool", {"str"}}},
    {"reg.list",         {"str", {"str"}}},
    {"mem.dump",         {"void", {"int", "str"}}},
};

void Sema::errorAt(const Token& t, const std::string& msg) const {
    throw std::runtime_error("semantic error at line " + std::to_string(t.line) + ", col " +
                             std::to_string(t.col) + ": " + msg);
}

void Sema::pushScope() { scopes_.emplace_back(); }
void Sema::popScope() { scopes_.pop_back(); }

void Sema::declareVar(const std::string& name, const std::string& type) {
    if (scopes_.empty()) scopes_.emplace_back();
    auto& top = scopes_.back();
    if (top.count(name)) {
        throw std::runtime_error("semantic error: variable '" + name + "' already declared in this scope");
    }
    top[name] = type;
}

std::string Sema::lookupVar(const std::string& name) const {
    for (auto it = scopes_.rbegin(); it != scopes_.rend(); ++it) {
        auto f = it->find(name);
        if (f != it->end()) return f->second;
    }
    return "";
}

void Sema::collectFnSigs(Program& prog) {
    for (auto& s : prog.stmts) {
        if (s->kind == Stmt::K::Fn) {
            FnSig sig;
            sig.retType = s->fnRetType;
            for (auto& p : s->params) sig.paramTypes.push_back(p.second);
            fns_[s->fnName] = std::move(sig);
        }
    }
}

void Sema::check(Program& prog) {
    collectFnSigs(prog);
    pushScope();  // global scope

    for (auto& s : prog.stmts) {
        if (s->kind == Stmt::K::Fn) {
            FnSig& sig = fns_[s->fnName];
            currentRetType_ = sig.retType;
            pushScope();
            for (auto& p : s->params) declareVar(p.first, p.second);
            for (auto& body : s->fnBody) checkStmt(*body);
            popScope();
        } else {
            checkStmt(*s);
        }
    }
    popScope();
}

void Sema::checkStmt(Stmt& s) {
    switch (s.kind) {
        case Stmt::K::Let: {
            std::string t;
            if (s.init) t = checkExpr(*s.init);
            if (t == "void") errorAt(s.tok, "cannot initialize a variable with a void expression");
            if (!s.varType.empty() && s.varType != t) {
                errorAt(s.tok, "type mismatch: cannot assign " + t + " to variable '" +
                               s.varName + "' of type " + s.varType);
            }
            std::string resolved = s.varType.empty() ? t : s.varType;
            declareVar(s.varName, resolved);
            break;
        }
        case Stmt::K::ExprStmt: {
            checkExpr(*s.init);
            break;
        }
        case Stmt::K::If: {
            if (checkExpr(*s.cond) != "bool") errorAt(s.cond->tok, "if condition must be a bool");
            pushScope();
            for (auto& st : s.thenBody) checkStmt(*st);
            popScope();
            pushScope();
            for (auto& st : s.elseBody) checkStmt(*st);
            popScope();
            break;
        }
        case Stmt::K::While: {
            if (checkExpr(*s.loopCond) != "bool") errorAt(s.loopCond->tok, "while condition must be a bool");
            pushScope();
            for (auto& st : s.body) checkStmt(*st);
            popScope();
            break;
        }
        case Stmt::K::For: {
            pushScope();
            checkStmt(*s.forInit);
            if (checkExpr(*s.forCond) != "bool") errorAt(s.forCond->tok, "for condition must be a bool");
            checkExpr(*s.forStep);
            pushScope();
            for (auto& st : s.body) checkStmt(*st);
            popScope();
            popScope();
            break;
        }
        case Stmt::K::Return: {
            if (s.retExpr) {
                std::string t = checkExpr(*s.retExpr);
                if (currentRetType_ == "void") {
                    errorAt(s.tok, "cannot return a value from a void function");
                } else if (t != currentRetType_) {
                    errorAt(s.tok, "return type mismatch: expected " + currentRetType_ + ", got " + t);
                }
            } else if (currentRetType_ != "void") {
                errorAt(s.tok, "function of type " + currentRetType_ + " must return a value");
            }
            break;
        }
        case Stmt::K::Fn:
            errorAt(s.tok, "nested function declarations are not allowed");
            break;
        // Switch nodes are synthesized by the obfuscation pass AFTER sema
        // has run, so they never reach this switch. Kept only so the enum
        // stays exhaustively covered.
        case Stmt::K::Switch:
            break;
    }
}

std::string Sema::checkExpr(Expr& e) {
    std::string result;
    switch (e.kind) {
        case Expr::K::IntLit: result = "int"; break;
        case Expr::K::StrLit: result = "str"; break;
        case Expr::K::BoolLit: result = "bool"; break;

        case Expr::K::Ident: {
            std::string t = lookupVar(e.name);
            if (t.empty()) errorAt(e.tok, "undefined variable '" + e.name + "'");
            result = t;
            break;
        }

        case Expr::K::Unary: {
            std::string t = checkExpr(*e.lhs);
            if (e.op == "!") {
                if (t != "bool") errorAt(e.tok, "'!' requires a bool operand");
                result = "bool";
            } else if (e.op == "-") {
                if (t != "int") errorAt(e.tok, "unary '-' requires an int operand");
                result = "int";
            } else errorAt(e.tok, "unknown unary operator '" + e.op + "'");
            break;
        }

        case Expr::K::Binary: {
            if (e.op == "=") {
                if (e.lhs->kind != Expr::K::Ident) errorAt(e.tok, "assignment target must be a variable");
                std::string lt = lookupVar(e.lhs->name);
                if (lt.empty()) errorAt(e.lhs->tok, "undefined variable '" + e.lhs->name + "'");
                std::string rt = checkExpr(*e.rhs);
                if (lt != rt) errorAt(e.tok, "cannot assign " + rt + " to variable of type " + lt);
                result = lt;
                break;
            }
            std::string lt = checkExpr(*e.lhs);
            std::string rt = checkExpr(*e.rhs);
            if (e.op == "+" || e.op == "-" || e.op == "*" || e.op == "/" || e.op == "%") {
                if (lt != "int" || rt != "int") errorAt(e.tok, "arithmetic operator '" + e.op + "' requires int operands");
                result = "int";
            } else if (e.op == "==" || e.op == "!=") {
                if (lt != rt) errorAt(e.tok, "cannot compare " + lt + " with " + rt);
                result = "bool";
            } else if (e.op == "<" || e.op == "<=" || e.op == ">" || e.op == ">=") {
                if (lt != "int" || rt != "int") errorAt(e.tok, "relational operator '" + e.op + "' requires int operands");
                result = "bool";
            } else if (e.op == "&&" || e.op == "||") {
                if (lt != "bool" || rt != "bool") errorAt(e.tok, "'" + e.op + "' requires bool operands");
                result = "bool";
            } else errorAt(e.tok, "unknown binary operator '" + e.op + "'");
            break;
        }

        case Expr::K::Call: {
            if (e.name == "print") {
                if (e.args.size() != 1) errorAt(e.tok, "print takes exactly 1 argument");
                std::string at = checkExpr(*e.args[0]);
                if (at == "void") errorAt(e.args[0]->tok, "cannot print a void expression");
                result = "void";
            } else if (e.name == "len") {
                if (e.args.size() != 1) errorAt(e.tok, "len takes exactly 1 argument");
                if (checkExpr(*e.args[0]) != "str") errorAt(e.args[0]->tok, "len requires a str argument");
                result = "int";
            } else {
                auto b = kBuiltins.find(e.name);
                if (b != kBuiltins.end()) {
                    const FnSig& sig = b->second;
                    if (e.args.size() != sig.paramTypes.size()) {
                        errorAt(e.tok, "builtin '" + e.name + "' expects " +
                                       std::to_string(sig.paramTypes.size()) + " arguments, got " +
                                       std::to_string(e.args.size()));
                    }
                    for (size_t i = 0; i < e.args.size(); ++i) {
                        std::string at = checkExpr(*e.args[i]);
                        if (at != sig.paramTypes[i]) {
                            errorAt(e.args[i]->tok, "argument " + std::to_string(i + 1) + " of '" +
                                   e.name + "' expects " + sig.paramTypes[i] + ", got " + at);
                        }
                    }
                    result = sig.retType;
                } else {
                    auto it = fns_.find(e.name);
                    if (it == fns_.end()) errorAt(e.tok, "undefined function '" + e.name + "'");
                    const FnSig& sig = it->second;
                    if (e.args.size() != sig.paramTypes.size()) {
                        errorAt(e.tok, "function '" + e.name + "' expects " +
                                       std::to_string(sig.paramTypes.size()) + " arguments, got " +
                                       std::to_string(e.args.size()));
                    }
                    for (size_t i = 0; i < e.args.size(); ++i) {
                        std::string at = checkExpr(*e.args[i]);
                        if (at != sig.paramTypes[i]) {
                            errorAt(e.args[i]->tok, "argument " + std::to_string(i + 1) + " of '" +
                                   e.name + "' expects " + sig.paramTypes[i] + ", got " + at);
                        }
                    }
                    result = sig.retType;
                }
            }
            break;
        }
    }
    exprTypes_[&e] = result;
    return result;
}