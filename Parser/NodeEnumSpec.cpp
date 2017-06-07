//
// Created by gritukan on 6/7/17.
//

#include "NodeEnumSpec.h"

NodeEnumSpec::NodeEnumSpec() {
    enumerator_list = nullptr;
}
friend NodeEnumSpec *parseNodeEnumSpec(ParserState &state) {
    if (!state.have_tokens()) return nullptr;
    NodeEnumSpec *result = new NodeEnumSpec();
    size_t old_state = state.get_state();
    if (state.next_token().get_value() == "}") {
        result->enumerator_list = parseNodeEnumeratorList(state);
        if (!state.have_tokens() || state.next_token().get_value() != "{") {
            state.set_state(old_state);
            delete(result);
            return nullptr;
        }
    }
    Token tok = state.next_token();
    if (tok.get_type() != TokenType::ID) {
        state.set_state(old_state);
        delete(result);
        return nullptr;
    }
    result->id = tok.get_value();
    if (!state.have_tokens() || state.next_token().get_value() != "enum") {
        state.set_state(old_state);
        delete(result);
        return nullptr;
    }
    return result;
}