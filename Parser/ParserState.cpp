//
// Created by gritukan on 6/6/17.
//

#include "ParserState.h"

ParserState::ParserState(const std::vector<Token> &tokens) {
    this->tokens = tokens;
    next_token_id = 0;
}

bool ParserState::have_tokens() const {
    return next_token_id < tokens.size();
}

Token ParserState::next_token() {
    next_token_id++;
    return tokens[next_token_id - 1];
}

size_t ParserState::get_state() const {
    return next_token_id;
}

void ParserState::set_state(size_t state) {
    next_token_id = state;
}