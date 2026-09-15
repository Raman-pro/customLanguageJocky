#include "token.h"

std::string token_name(Tok t) {
    switch (t) {
        case Tok::Int: return "INT";
        case Tok::Str: return "STR";
        case Tok::Ident: return "IDENT";
        case Tok::KwLet: return "let";
        case Tok::KwFn: return "fn";
        case Tok::KwIf: return "if";
        case Tok::KwElse: return "else";
        case Tok::KwWhile: return "while";
        case Tok::KwFor: return "for";
        case Tok::KwReturn: return "return";
        case Tok::KwTrue: return "true";
        case Tok::KwFalse: return "false";
        case Tok::TyInt: return "int";
        case Tok::TyStr: return "str";
        case Tok::TyBool: return "bool";
        case Tok::TyVoid: return "void";
        case Tok::LParen: return "(";
        case Tok::RParen: return ")";
        case Tok::LBrace: return "{";
        case Tok::RBrace: return "}";
        case Tok::Comma: return ",";
        case Tok::Semicolon: return ";";
        case Tok::Colon: return ":";
        case Tok::Assign: return "=";
        case Tok::Dot: return ".";
        case Tok::Plus: return "+";
        case Tok::Minus: return "-";
        case Tok::Star: return "*";
        case Tok::Slash: return "/";
        case Tok::Percent: return "%";
        case Tok::EqEq: return "==";
        case Tok::NotEq: return "!=";
        case Tok::Lt: return "<";
        case Tok::Le: return "<=";
        case Tok::Gt: return ">";
        case Tok::Ge: return ">=";
        case Tok::AndAnd: return "&&";
        case Tok::OrOr: return "||";
        case Tok::Bang: return "!";
        case Tok::End: return "EOF";
    }
    return "?";
}
