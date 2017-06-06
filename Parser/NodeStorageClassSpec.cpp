//
// Created by gritukan on 6/6/17.
//

#include "NodeStorageClassSpec.h"

NodeStorageClassSpec::NodeStorageClassSpec(const std::string &s) {
    value = s;
}

friend NodeStorageClassSpec *parseNodeStorageClassSpec(ParserState &state) {
    if (!state.have_tokens()) return nullptr;
    size_t old_state = state.get_state();
    std::string cur_token = state.next_token().get_value();
    if (cur_token == "auto" || cur_token == "register" || cur_token == "static" || cur_token == "extern" || cur_token == "typedef") {
        return new NodeStorageClassSpec(cur_token);
    }
    state.set_state(old_state);
    return nullptr;
}