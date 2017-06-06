//
// Created by gritukan on 6/6/17.
//

#ifndef COMPILER_PARSERSTATE_H
#define COMPILER_PARSERSTATE_H


#include "../Token.h"

class ParserState {
private:
    std::vector<Token> tokens;
    size_t next_token_id;
public:
    ParserState(const std::vector<Token> &tokens);
    bool have_tokens() const;
    Token next_token();
    size_t get_state() const;
    void set_state(size_t state);
};


#endif //COMPILER_PARSERSTATE_H
