#include <algorithm>
#include "Scanner.hpp"

using namespace std;

std::vector<Token> *Scanner::scanTokens()
{
    std::cout << "Scanning ... " << endl;
    std::cout << *this->source << endl;
    while (!isAtEnd())
    {
        start = current;
        scanToken();
    }

    this->tokens.push_back(Token{TokenType::TOKEN_EOF, "", Obj{}, this->line});
    return &this->tokens;
}

Scanner::Scanner(const std::string *source)
{
    this->source = source;
    this->tokens = std::vector<Token>{};
}

void Scanner::scanToken()
{
    char c = advance();
    switch (c)
    {
    case '(':
        addToken(TokenType::LEFT_PAREN);
        break;
    case ')':
        addToken(TokenType::RIGHT_PAREN);
        break;
    case '{':
        addToken(TokenType::LEFT_BRACE);
        break;
    case '}':
        addToken(TokenType::RIGHT_BRACE);
        break;
    case '[':
        addToken(TokenType::LEFT_BRACKET);
        break;
    case ']':
        addToken(TokenType::RIGHT_BRACKET);
        break;
    case '_':
    case '$':
    case '@':
    case '%':
        valuable();
        break;
    default:
        if (isDigit(c))
            number(c);
        break;
    }
}

char Scanner::advance()
{
    current++;
    char c = this->source->at(current - 1);
    return c;
}

bool Scanner::match(char expected)
{
    if (isAtEnd())
        return false;
    if (this->source->at(current) != expected)
        return false;

    current++;
    return true;
}

char Scanner::peek()
{
    if (isAtEnd())
        return '\0';
    return this->source->at(current);
}

char Scanner::peekNext()
{
    if (this->current + 1 >= this->source->size())
        return '\0';
    return this->source->at(current + 1);
}

char Scanner::peekPrev()
{
    if (this->current = 0)
        return '\0';
    return this->source->at(current - 1);
}

bool Scanner::isAlpha(char c)
{
    return (c >= 'a' && c <= 'z') ||
           (c >= 'A' && c <= 'Z') ||
           c == '_';
}

bool Scanner::isDigit(char c)
{
    return c >= '0' && c <= '9';
}

bool Scanner::isBinaryDigit(char c)
{
    return c == '0' || c == '1';
}
bool Scanner::isOctDigit(char c)
{
    return c >= '0' && c <= '7';
}

bool Scanner::isHexaDigit(char c)
{
    return isDigit(c) || (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F');
}

bool Scanner::isAlphaNumeric(char c)
{
    return isAlpha(c) || isDigit(c);
}

void Scanner::addToken(TokenType type)
{
    Obj obj = Obj{};
    addToken(type, obj);
}

void Scanner::addToken(TokenType type, Obj literal)
{
    std::string text = this->source->substr(start, current);
    if (type == TokenType::NUMBER)
    {
        text.erase(remove(text.begin(), text.end(), '_'), text.end()); // remove '_' from string
    }

    Token tk = Token{type, text, literal, this->line};
    this->tokens.push_back(tk);
}

void Scanner::number(char c)
{
    TokenType type;
    // Binary, Octal, Hexadecimal number
    if (c == '0')
    {
        if (match('b') || match('B'))
        {
            while (isBinaryDigit(peek()))
                advance();
        }
        else if (match('x') || match('X'))
        {
            while (isHexaDigit(peek()))
                advance();
        }
        else
        {
            while (isOctDigit(peek()))
                advance();
        }
    }
    else
    {
        while (isDigit(peek()) || peek() == '_' || peek() == '.' || peek() == 'e' || peek() == '-')
            advance();
    }

    addToken(TokenType::NUMBER);
}

void Scanner::valuable()
{
    while (isAlphaNumeric(peek()) || peek() == '_')
        advance();

    addToken(TokenType::IDENTIFIER);
}

bool Scanner::isAtEnd()
{
    return current >= this->source->size();
}