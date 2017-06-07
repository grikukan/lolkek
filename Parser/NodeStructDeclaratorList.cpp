//
// Created by gritukan on 6/6/17.
//

#include <algorithm>
#include "NodeStructDeclaratorList.h"

friend NodeStructDeclaratorList *parseNodeStructDeclaratorList(ParserState &state) {
    size_t old_state = state.get_state();
    NodeStructDeclaratorList *result = new NodeStructDeclaratorList();
    result->struct_declarator.push_back(parseNodeStructDeclarator(state));
    if (result->struct_declarator.back() == nullptr) {
        delete(result);
        return nullptr;
    }
    while (true) {
        if (!state.have_tokens()) break;
        size_t near_state = state.get_state();
        if (state.next_token().get_value() != ",") {
            state.set_state(near_state);
            break;
        }
        result->struct_declarator.push_back(parseNodeStructDeclarator(state));
        if (result->struct_declarator.back() == nullptr) {
            state.set_state(old_state);
            delete(result);
            return nullptr;
        }
    }
    std::reverse(result->struct_declarator.begin(), result->struct_declarator.end());
    return result;
}
