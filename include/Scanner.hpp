#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "Token.hpp"
#include "TokenType.hpp"
#include "Obj.hpp"

using namespace std;

class Scanner
{
public:
    Scanner(const std::string *);
    vector<Token> *scanTokens();

private:
    void scanToken();
    char advance();
    bool match(char);
    char peek();
    char peekNext();
    char peekPrev();
    bool isAlpha(char);
    bool isDigit(char);
    bool isAlphaNumeric(char);
    bool isBinaryDigit(char);
    bool isOctDigit(char);
    bool isHexaDigit(char);

    void addToken(TokenType);
    void addToken(TokenType, Obj);

    void number(char);
    void valuable();

    bool isAtEnd();

private:
    const std::string *source;
    std::vector<Token> tokens;
    int start = 0;
    int current = 0;
    int line = 0;
};
