//
// Created by gritukan on 6/6/17.
//

#include "NodeStructOrUnionSpec.h"

NodeStructOrUnionSpec::NodeStructOrUnionSpec() {
    struct_or_union = nullptr;
    struct_decl_list = nullptr;
}
friend NodeStructOrUnionSpec *parseNodeStructOrUnionSpec(ParserState &state) {
    if (!state.have_tokens()) {
        return nullptr;
    }
    size_t old_state = state.get_state();
    Token tok = state.next_token();
    std::string token = tok.get_value();
    if (token == "}") {
        NodeStructDeclList *tmp = parseNodeStructDeclList(state);
        if (tmp == nullptr) {
            state.set_state(old_state);
            return nullptr;
        }
        NodeStructOrUnionSpec *result = new NodeStructOrUnionSpec();
        result->struct_decl_list = tmp;
        if (!state.have_tokens() || state.next_token().get_value() != "{") {
            delete (result);
            state.set_state(old_state);
            return nullptr;
        }
        result->struct_or_union = parseNodeStructOrUnion(state);
        if (result->struct_or_union == nullptr) {
            delete (result);
            state.set_state(old_state);
            return nullptr;
        }
        return result;
    }
    if (tok.get_type() == TokenType::ID) {
        NodeStructOrUnionSpec *result = new NodeStructOrUnionSpec();
        result->struct_or_union = parseNodeStructOrUnion(state);
        if (result->struct_or_union == nullptr) {
            delete (result);
            state.set_state(old_state);
            return nullptr;
        }
        return result;
    }
    state.set_state(old_state);
    return nullptr;
}
