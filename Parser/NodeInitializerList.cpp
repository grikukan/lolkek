//
// Created by gritukan on 6/6/17.
//

#include <algorithm>
#include "NodeInitializerList.h"

friend NodeInitializerList *parseNodeInitializerList(ParserState &state) {
    NodeInitializerList *result = new NodeInitializerList();
    size_t old_state = state.get_state();
    result->initializer.push_back(parseNodeInitializer(state));
    if (result->initializer.back() == nullptr) {
        return nullptr;
    }
    while (true) {
        if (!state.have_tokens()) break;
        size_t in_state = state.get_state();
        if (state.next_token().get_value() != ",") {
            state.set_state(in_state);
            return result;
        }
        result->initializer.push_back(parseNodeInitializer(state));
        if (result->initializer.back() == nullptr) {
            state.set_state(old_state);
            return nullptr;
        }
    }
    std::reverse(result->initializer.begin(), result->initializer.end());
    return result;
}
