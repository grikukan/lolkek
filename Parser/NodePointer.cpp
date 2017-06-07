//
// Created by gritukan on 6/6/17.
//

#include "NodePointer.h"

NodePointer::NodePointer() {
    pointer_depth = 0;
    type_qualifier_list = nullptr;
}

friend NodePointer *parseNodePointer(ParserState &state) {
    size_t old_state = state.get_state();
    NodePointer *result = new NodePointer();
    result->type_qualifier_list = parseNodeTypeQualifierList(state);
    if (!state.have_tokens() || state.next_token().get_value() != "*") {
        delete(result);
        state.set_state(old_state);
        return nullptr;
    }
    result->pointer_depth = 1;
    while (state.have_tokens() && state.next_token().get_value() == "*") {
        result->pointer_depth++;
        old_state = state.get_state();
    }
    state.set_state(old_state);
    return result;
}
