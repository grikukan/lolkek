//
// Created by gritukan on 6/6/17.
//

#ifndef COMPILER_TOKENIZER_H
#define COMPILER_TOKENIZER_H

#include <string>
#include <vector>
#include <cassert>
#include <unordered_set>
#include "Token.h"


class Tokenizer {
private:
    bool is_letter(char c);
    bool is_digit(char c);
    bool is_space(char c);
    const static std::vector<std::string> terminal_tokens;
public:
    std::vector<Token> tokenize(const std::string &s);

};


#endif //COMPILER_TOKENIZER_H
