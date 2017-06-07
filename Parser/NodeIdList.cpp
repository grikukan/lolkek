//
// Created by gritukan on 6/6/17.
//

#include <algorithm>
#include "NodeIdList.h"

friend NodeIdList *parseNodeIdList(ParserState &state) {
    if (!state.have_tokens()) return nullptr;
    size_t old_state = state.get_state();
    NodeIdList *result = new NodeIdList();
    Token token = state.next_token();
    if (token.get_type() != TokenType::ID) {
        state.set_state(old_state);
        delete(result);
        return nullptr;
    }
    result->id.push_back(token.get_value());
    while (true) {
        size_t cur_state = state.get_state();
        token = state.next_token();
        if (token.get_value() != ",") {
            state.set_state(cur_state);
            break;
        }
        token = state.next_token();
        if (token.get_type() != TokenType::ID) {
            state.set_state(old_state);
            delete(result);
            return nullptr;
        }
        result->id.push_back(token.get_value());
    }
    std::reverse(result->id.begin(), result->id.end());
    return result;
}