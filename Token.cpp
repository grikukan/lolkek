//
// Created by gritukan on 6/6/17.
//

#include "Token.h"

Token::Token(const std::string &value) {
    this->value = value;
    assert(!value.empty());
    if (value[0] == '\"') {
        assert(value.back() == '\"');
        type = TokenType::STRING;
    } else if (value[0] == '\'') {
        assert(value.back() == '\'');
        type = TokenType::CHAR_CONST;
    } else if (terminals.count(value)) {
        type = TokenType::TERMINAL_TOKEN;
    } else if (value[0] == '-' || (value[0] >= '0' && value[0] <= '9')) {
        type = TokenType::INT_CONST;
    } else {
        type = TokenType::ID;
    }
}

TokenType Token::get_type() const {
    return type;
}

std::string Token::get_value() const {
    return value;
}

const std::unordered_set<std::string> Token::terminals  = {";", "auto", "register", "static", "extern", "typedef",
                                                           "void", "char", "short", "int", "long", "float", "double",
                                                           "signed", "unsigned", "const", "volatile", "{", "}", "struct",
                                                           "union", ",", "=", ":", "(", ")", "[", "]", "*", ",", "...",
                                                           "while", "do", "for", "goto", "continue", "break", "return",
                                                           "=", "*=", "/=", "%=", "+=", "-=", "<<=", ">>=", "&=", "^=",
                                                           "|=", "?", "||", "&&", "|", "^", "&", "==", "!=", "<", ">",
                                                           "<=", ">=", "<<", ">>", "+", "-", "*", "/", "%", "++", "--",
                                                           "~", "!", ".", "->"};

