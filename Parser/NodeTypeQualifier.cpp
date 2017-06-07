//
// Created by gritukan on 6/6/17.
//

#include "NodeTypeQualifier.h"

friend NodeTypeQualifier *parseNodeTypeQualifier(ParserState &state) {
    if (!state.have_tokens()) return nullptr;
    size_t old_state = state.get_state();
    std::string token = state.next_token().get_value();
    if (token == "const" || token == "volatile") {
        NodeTypeQualifier *result = new NodeTypeQualifier();
        result->value = token;
        return result;
    }
    state.set_state(old_state);
    return nullptr;
}