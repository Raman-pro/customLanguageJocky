#include "lexer.h"

#include <cctype>
#include <stdexcept>
#include <unordered_map>
#include <utility>

Lexer::Lexer(std::string src) : src_(std::move(src)) {}

std::vector<Token> Lexer::tokenize() {
    std::vector<Token> tokens;
    for (;;) {
        skipWhitespaceAndComments();
        if (pos_ >= src_.size()) {
            tokens.push_back(Token{Tok::End, "<eof>", line_, col_, 0});
            return tokens;
        }
        tokens.push_back(nextToken());
    }
}

void Lexer::skipWhitespaceAndComments() {
    for (;;) {
        while (pos_ < src_.size()) {
            char c = src_[pos_];
            if (c == '\n') { line_++; col_ = 1; pos_++; }
            else if (std::isspace(static_cast<unsigned char>(c))) { col_++; pos_++; }
            else break;
        }
        // Line comment: // ...
        if (pos_ + 1 < src_.size() && src_[pos_] == '/' && src_[pos_ + 1] == '/') {
            while (pos_ < src_.size() && src_[pos_] != '\n') { col_++; pos_++; }
            continue;
        }
        // Block comment: /* ... */
        if (pos_ + 1 < src_.size() && src_[pos_] == '/' && src_[pos_ + 1] == '*') {
            pos_ += 2; col_ += 2;
            while (pos_ + 1 < src_.size() && !(src_[pos_] == '*' && src_[pos_ + 1] == '/')) {
                if (src_[pos_] == '\n') { line_++; col_ = 1; } else { col_++; }
                pos_++;
            }
            if (pos_ + 1 >= src_.size()) error("unterminated block comment");
            pos_ += 2; col_ += 2;
            continue;
        }
        break;
    }
}

void Lexer::error(const std::string& msg) const {
    throw std::runtime_error("lex error at line " + std::to_string(line_) + ", col " +
                             std::to_string(col_) + ": " + msg);
}

Token Lexer::nextToken() {
    int line = line_, col = col_;
    char c = src_[pos_];

    if (std::isdigit(static_cast<unsigned char>(c))) return readNumber();
    if (c == '"') return readString();
    if (std::isalpha(static_cast<unsigned char>(c)) || c == '_') return readIdentOrKeyword();

    // Operators / punctuation (longest match first).
    auto two = [&](char a, char b) -> bool {
        return pos_ + 1 < src_.size() && src_[pos_] == a && src_[pos_ + 1] == b;
    };
    Tok kind;
    size_t adv = 1;
    if (two('=', '=')) { kind = Tok::EqEq; adv = 2; }
    else if (two('!', '=')) { kind = Tok::NotEq; adv = 2; }
    else if (two('<', '=')) { kind = Tok::Le; adv = 2; }
    else if (two('>', '=')) { kind = Tok::Ge; adv = 2; }
    else if (two('&', '&')) { kind = Tok::AndAnd; adv = 2; }
    else if (two('|', '|')) { kind = Tok::OrOr; adv = 2; }
    else if (c == '(') kind = Tok::LParen;
    else if (c == ')') kind = Tok::RParen;
    else if (c == '{') kind = Tok::LBrace;
    else if (c == '}') kind = Tok::RBrace;
    else if (c == ',') kind = Tok::Comma;
    else if (c == ';') kind = Tok::Semicolon;
    else if (c == ':') kind = Tok::Colon;
    else if (c == '=') kind = Tok::Assign;
    else if (c == '.') kind = Tok::Dot;
    else if (c == '+') kind = Tok::Plus;
    else if (c == '-') kind = Tok::Minus;
    else if (c == '*') kind = Tok::Star;
    else if (c == '/') kind = Tok::Slash;
    else if (c == '%') kind = Tok::Percent;
    else if (c == '<') kind = Tok::Lt;
    else if (c == '>') kind = Tok::Gt;
    else if (c == '!') kind = Tok::Bang;
    else error(std::string("unexpected character '") + c + "'");

    pos_ += adv;
    col_ += static_cast<int>(adv);
    return Token{kind, src_.substr(pos_ - adv, adv), line, col, 0};
}

Token Lexer::readNumber() {
    int line = line_, col = col_;
    size_t start = pos_;
    while (pos_ < src_.size() && std::isdigit(static_cast<unsigned char>(src_[pos_]))) { pos_++; col_++; }
    std::string text = src_.substr(start, pos_ - start);
    return Token{Tok::Int, text, line, col, std::stoll(text)};
}

Token Lexer::readString() {
    int line = line_, col = col_;
    pos_++; col_++;  // opening quote
    std::string value;
    while (pos_ < src_.size()) {
        char c = src_[pos_];
        if (c == '"') { pos_++; col_++; break; }
        if (c == '\n') error("unterminated string literal");
        if (c == '\\') {
            pos_++; col_++;
            if (pos_ >= src_.size()) error("unterminated escape sequence");
            char e = src_[pos_];
            switch (e) {
                case 'n': value += '\n'; break;
                case 't': value += '\t'; break;
                case 'r': value += '\r'; break;
                case '\\': value += '\\'; break;
                case '"': value += '"'; break;
                case '0': value += '\0'; break;
                default: error(std::string("unknown escape sequence \\") + e);
            }
            pos_++; col_++;
        } else {
            value += c;
            pos_++; col_++;
        }
    }
    return Token{Tok::Str, value, line, col, 0};
}

Token Lexer::readIdentOrKeyword() {
    int line = line_, col = col_;
    size_t start = pos_;
    while (pos_ < src_.size()) {
        char c = src_[pos_];
        if (std::isalnum(static_cast<unsigned char>(c)) || c == '_') { pos_++; col_++; }
        else break;
    }
    std::string text = src_.substr(start, pos_ - start);
    static const std::unordered_map<std::string, Tok> keywords = {
        {"let", Tok::KwLet}, {"fn", Tok::KwFn}, {"if", Tok::KwIf}, {"else", Tok::KwElse},
        {"while", Tok::KwWhile}, {"for", Tok::KwFor}, {"return", Tok::KwReturn},
        {"true", Tok::KwTrue}, {"false", Tok::KwFalse},
        {"int", Tok::TyInt}, {"str", Tok::TyStr}, {"bool", Tok::TyBool}, {"void", Tok::TyVoid},
    };
    auto it = keywords.find(text);
    return Token{it != keywords.end() ? it->second : Tok::Ident, text, line, col, 0};
}