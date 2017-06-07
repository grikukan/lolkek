//
// Created by gritukan on 6/6/17.
//

#include "NodeStructDeclarator.h"

NodeStructDeclarator::NodeStructDeclarator() {
    declarator = nullptr;
    constExp = nullptr;
}
friend NodeStructDeclarator *parseNodeStructDeclarator(ParserState &state) {
    size_t old_state = state.get_state();
    NodeStructDeclarator *result = new NodeStructDeclarator();
    result->constExp = parseNodeConstExp(state);
    if (result->constExp == nullptr || !state.have_tokens() || state.next_token().get_value() != ":") {
        result->constExp = nullptr;
        state.set_state(old_state);
    }
    result->declarator = parseNodeDeclarator(state);
    if (result->constExp == nullptr && result->declarator == nullptr) {
        state.set_state(old_state);
        delete(result);
        return nullptr;
    }
    return result;
}
