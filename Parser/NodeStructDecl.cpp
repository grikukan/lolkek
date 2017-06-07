//
// Created by gritukan on 6/6/17.
//

#include "NodeStructDecl.h"

NodeStructDecl::NodeStructDecl(){
    spec_qualifier_list = nullptr;
    struct_declarator_list = nullptr;
}
friend NodeStructDecl *parseNodeStructDecl(ParserState &state) {
    if (!state.have_tokens()) return nullptr;
    size_t old_state = state.get_state();
    if (state.next_token().get_value() != ";") {
        state.set_state(old_state);
        return nullptr;
    }
    NodeStructDecl *result = new NodeStructDecl();
    result->struct_declarator_list = parseNodeStructDeclaratorList(state);
    if (result->struct_declarator_list == nullptr) {
        delete(result);
        state.set_state(old_state);
        return nullptr;
    }
    result->spec_qualifier_list = parseNodeSpecQualifierList(state);
    if (result->spec_qualifier_list == nullptr) {
        delete(result);
        state.set_state(old_state);
        return nullptr;
    }
    return result;
}
