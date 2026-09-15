#pragma once

#include <cstdint>
#include <string>

enum class Tok {
    Int, Str, Ident,
    KwLet, KwFn, KwIf, KwElse, KwWhile, KwFor, KwReturn, KwTrue, KwFalse,
    TyInt, TyStr, TyBool, TyVoid,
    LParen, RParen, LBrace, RBrace, Comma, Semicolon, Colon, Assign, Dot,
    Plus, Minus, Star, Slash, Percent,
    EqEq, NotEq, Lt, Le, Gt, Ge, AndAnd, OrOr, Bang,
    End
};

struct Token {
    Tok kind = Tok::End;
    std::string text;          // raw lexeme (also holds string literal value)
    int line = 1;
    int col = 1;
    int64_t ival = 0;          // integer literal value
};

std::string token_name(Tok t);
