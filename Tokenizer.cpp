//
// Created by gritukan on 6/6/17.
//

#include "Tokenizer.h"

bool Tokenizer::is_letter(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}
bool Tokenizer::is_digit(char c) {
    return c >= '0' && c <= '9';
}
bool Tokenizer::is_space(char c) {
    return c == ' ' || c == '\n' || c == '\t';
}

std::vector<Token> Tokenizer::tokenize(const std::string &s) {
    std::string current_token;
    std::vector<Token> result;
    for (size_t i = 0; i < s.size(); i++) {
        if (is_space(s[i])) {
            if (!current_token.empty()) {
                result.push_back(Token(current_token));
                current_token.clear();
            }
            continue;
        } else if (is_digit(s[i]) || is_letter(s[i])) {
            current_token += s[i];
        } else {
            if (!current_token.empty()) {
                result.push_back(Token(current_token));
                current_token.clear();
            }
            current_token.clear();
            for (size_t j = 0; j < terminal_tokens.size(); j++) {
                if (s.substr(i, terminal_tokens[j].size()) == terminal_tokens[j] && terminal_tokens[j].size() > current_token.size()) {
                    current_token = terminal_tokens[j];
                }
            }
            if (current_token.empty()) {
                assert(0);
            }
            result.push_back(Token(current_token));
            i += current_token.size() - 1;
            current_token.clear();
        }
    }
    return result;
}

const std::vector<std::string> Tokenizer::terminal_tokens  = {";", "auto", "register", "static", "extern", "typedef",
                                                               "void", "char", "short", "int", "long", "float", "double",
                                                               "signed", "unsigned", "const", "volatile", "{", "}", "struct",
                                                               "union", ",", "=", ":", "(", ")", "[", "]", "*", ",", "...",
                                                               "while", "do", "for", "goto", "continue", "break", "return",
                                                               "=", "*=", "/=", "%=", "+=", "-=", "<<=", ">>=", "&=", "^=",
                                                               "|=", "?", "||", "&&", "|", "^", "&", "==", "!=", "<", ">",
                                                               "<=", ">=", "<<", ">>", "+", "-", "*", "/", "%", "++", "--",
                                                               "~", "!", ".", "->"};