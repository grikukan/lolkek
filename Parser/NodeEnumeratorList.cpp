//
// Created by gritukan on 6/6/17.
//

#include "NodeEnumeratorList.h"

friend NodeEnumeratorList *parseNodeEnumeratorList(ParserState &state) {
    size_t old_state = state.get_state();
    NodeEnumeratorList *result = new NodeEnumeratorList();
    result->enumerator.push_back(parseNodeEnumerator(state));
    if (result->enumerator.back() == nullptr) {
        delete(result);
        return nullptr;
    }
    while (true) {
        if (!state.have_tokens()) break;
        size_t near_state = state.get_state();
        if (state.next_token().get_value() != ",") {
            state.set_state(near_state);
            break;
        }
        result->enumerator.push_back(parseNodeEnumerator(state));
        if (result->enumerator.back() == nullptr) {
            delete(result);
            state.set_state(old_state);
            return nullptr;
        }
    }
    std::reverse(result->enumerator.begin(), result->enumerator.end());
    return result;
}