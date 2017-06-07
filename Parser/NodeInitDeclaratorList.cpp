//
// Created by gritukan on 6/6/17.
//

#include "NodeInitDeclaratorList.h"

friend NodeInitDeclaratorList *parseNodeInitDeclaratorList(ParserState &state) {
    NodeInitDeclaratorList *result = new NodeInitDeclaratorList();
    size_t old_state = state.get_state();
    result->init_declarator.push_back(parseNodeInitDeclarator(state));
    if (result->init_declarator.back() == nullptr) {
        return nullptr;
    }
    while (true) {
        if (!state.have_tokens()) break;
        size_t in_state = state.get_state();
        if (state.next_token().get_value() != ",") {
            state.set_state(in_state);
            return result;
        }
        result->init_declarator.push_back(parseNodeInitDeclarator(state));
        if (result->init_declarator.back() == nullptr) {
            state.set_state(old_state);
            return nullptr;
        }
    }
    std::reverse(result->init_declarator.begin(), result->init_declarator.end());
}