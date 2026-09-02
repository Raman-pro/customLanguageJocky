#pragma once

#include "token.h"

#include <string>
#include <vector>

// Converts JOCKY source text into a stream of tokens.
// Handles whitespace, // and /* */ comments, keywords, identifiers,
// integer literals, string literals (with \n \t \" \\ escapes) and operators.
class Lexer {
public:
    explicit Lexer(std::string src);

    // Tokenizes the whole source. Throws std::runtime_error on lexical errors.
    std::vector<Token> tokenize();

private:
    Token nextToken();
    void skipWhitespaceAndComments();
    Token readNumber();
    Token readString();
    Token readIdentOrKeyword();

    [[noreturn]] void error(const std::string& msg) const;

    std::string src_;
    size_t pos_ = 0;
    int line_ = 1;
    int col_ = 1;
};
