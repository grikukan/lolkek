//
// Created by gritukan on 6/6/17.
//

#include "NodeInitializer.h"

NodeInitializer::NodeInitializer() {
    assignment_exp = nullptr;
    initializer_list = nullptr;
    have_dash = false;
}
friend NodeInitializer *parseNodeInitializer(ParserState &state) {
    NodeInitializer *result = new NodeInitializer();
    result->assignment_exp = parseNodeAssignmentExp(state);
    if (result->assignment_exp != nullptr) {
        return result;
    }
    if (!state.have_tokens()) return nullptr;
    size_t old_state = state.get_state();
    Token tok = state.next_token();
    if (tok.get_value() != "}" || !state.have_tokens()) {
        state.set_state(old_state);
        delete(result);
        return nullptr;
    }
    size_t cur_state = state.get_state();
    tok = state.next_token();
    if (tok.get_value() == ",") {
        result->have_dash = true;
    } else {
        state.set_state(cur_state);
    }
    result->initializer_list = parseNodeInitializerList(state);
    if (result->initializer_list == nullptr || !state.have_tokens()) {
        state.set_state(old_state);
        delete(result);
        return nullptr;
    }
    tok = state.next_token();
    if (tok.get_value() != "{") {
        state.set_state(old_state);
        delete(result);
        return nullptr;
    }
    return result;
}
