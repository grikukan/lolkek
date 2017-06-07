//
// Created by gritukan on 6/6/17.
//

#include "NodeInitDeclarator.h"

NodeInitDeclarator::NodeInitDeclarator() {
    declarator = nullptr;
    initializer = nullptr;
}
friend NodeInitDeclarator *parseNodeInitDeclarator(ParserState &state) {
    NodeInitDeclarator *result = new NodeInitDeclarator();
    size_t old_state = state.get_state();
    result->initializer = parseNodeInitializer(state);
    if (result->initializer == nullptr || !state.have_tokens() || state.next_token().get_value() != "=") {
        state.set_state(old_state);
        result->initializer = nullptr;
    }
    result->declarator = parseNodeDeclarator(state);
        if (result->declarator == nullptr) {
        delete(result);
        return nullptr;
    }
    return result;
}
