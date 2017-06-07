//
// Created by gritukan on 6/6/17.
//

#include "NodeEnumerator.h"


NodeEnumerator::NodeEnumerator() {
    const_exp = nullptr;
}
friend NodeEnumerator *parseNodeEnumerator(ParserState &state) {
    size_t old_state = state.get_state();
    NodeEnumerator *result = new NodeEnumerator();
    result->const_exp = parseNodeConstExp(state);
    if (result->const_exp == nullptr || !state.have_tokens() || state.next_token().get_value() != "=") {
        result->const_exp = nullptr;
        state.set_state(old_state);
    }
    if (!state.have_tokens()) {
        state.set_state(old_state);
        delete(result);
        return nullptr;
    }
    Token tok = state.next_token();
    if (tok.get_type() != TokenType::ID) {
        state.set_state(old_state);
        delete(result);
        return nullptr;
    }
    result->id = tok.get_value();
    return result;
}