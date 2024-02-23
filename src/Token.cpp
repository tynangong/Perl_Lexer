#include <Token.hpp>

Token::Token(TokenType type, std::string lexeme, Obj literal, int line)
{
    this->type = type;
    this->lexeme = lexeme;
    this->literal = literal;
    this->line = line;
}

std::ostream &operator<<(std::ostream &s, const Token &token)
{
    // Todo
    // return s << token.type, token.lexeme, token.literal, token.line;
    return s;
}
