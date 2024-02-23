#pragma once

#include <iostream>
#include <string>

#include "Obj.hpp"
#include "TokenType.hpp"

class Token
{
public:
    Token(TokenType type, std::string lexeme, Obj literal, int line);
    friend std::ostream &operator<<(std::ostream &s, const Token &token);

private:
    TokenType type;
    std::string lexeme;
    Obj literal;
    int line;
};