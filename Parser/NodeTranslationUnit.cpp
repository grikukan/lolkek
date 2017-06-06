//
// Created by gritukan on 6/6/17.
//

#include <iostream>
#include <algorithm>
#include "NodeTranslationUnit.h"
#include "ParsingException.h"

NodeTranslationUnit *parseNodeTranslationUnit(ParserState &state) {
    NodeTranslationUnit *result = new NodeTranslationUnit();
    while (state.have_tokens()) {
        size_t old_state = state.get_state();
        NodeExternalDecl *tmp = parseNodeExternalDecl(state);
        if (tmp == nullptr) {
            state.set_state(old_state);
            break;
        }
        result->child.push_back(tmp);
    }
    std::reverse(result->child.begin(), result->child.end());
    return result;
}