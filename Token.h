//
// Created by gritukan on 6/6/17.
//

#ifndef COMPILER_TOKEN_H
#define COMPILER_TOKEN_H
#include <string>
#include <vector>
#include <cassert>
#include <unordered_set>


enum class TokenType {INT_CONST, CHAR_CONST, FLOAT_CONST, ID, STRING, ENUMERATION_CONST, TERMINAL_TOKEN};
class Token {
    //TODO: exceptions
    //TODO: floats
    //TODO: enumerations
private:
    TokenType type;
    std::string value;
    const static std::unordered_set<std::string> terminals;
public:
    Token(const std::string &value);
    TokenType get_type() const;
    std::string get_value() const;
};


#endif //COMPILER_TOKEN_H
