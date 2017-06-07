//
// Created by gritukan on 6/6/17.
//

#include <algorithm>
#include "NodeParamList.h"

friend NodeParamList *parseNodeParamList(ParserState &state) {
    NodeParamList *result = new NodeParamList();
    size_t old_state = state.get_state();
    result->param_decl.push_back(parseNodeParamDecl(state));
    if (result->param_decl.back() == nullptr) {
        return nullptr;
    }
    while (true) {
        if (!state.have_tokens()) break;
        size_t in_state = state.get_state();
        if (state.next_token().get_value() != ",") {
            state.set_state(in_state);
            return result;
        }
        result->param_decl.push_back(parseNodeParamDecl(state));
        if (result->param_decl.back() == nullptr) {
            state.set_state(old_state);
            return nullptr;
        }
    }
    std::reverse(result->param_decl.begin(), result->param_decl.end());
}