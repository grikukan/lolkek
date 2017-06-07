//
// Created by gritukan on 6/6/17.
//

#include "NodeParamTypeList.h"

NodeParamTypeList::NodeParamTypeList() {
    is_va_args = false;
    param_list = nullptr;
}
friend NodeParamTypeList *parseNodeParamTypeList(ParserState &state) {
    if (!state.have_tokens()) return nullptr;
    NodeParamTypeList *result = new NodeParamTypeList();
    size_t old_state = state.get_state();
    if (state.next_token().get_value() == "...") {
        if (!state.have_tokens() || state.next_token().get_value() != ",") {
            delete(result);
            state.set_state(old_state);
            return nullptr;
        }
        result->is_va_args = true;
    }
    result->param_list = parseNodeParamList(state);
    if (result->param_list == nullptr) {
        state.set_state(old_state);
        delete(result);
        return nullptr;
    }
    return result;
}
