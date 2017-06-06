//
// Created by gritukan on 6/6/17.
//

#include "NodeDecl.h"

NodeDecl::NodeDecl() {
    decl_specs = nullptr;
    init_declarator_list = nullptr;
}

friend NodeDecl *parseNodeDecl(ParserState &state) {
    size_t old_state = state.get_state();
    if (!state.have_tokens() || state.next_token().get_value() != ";") {
        state.set_state(old_state);
        return nullptr;
    }
    NodeDecl *result = new NodeDecl();
    result->init_declarator_list = parseInitDeclaratorList(state);
    result->decl_specs = parseDeclSpecs(state);
    if (result->decl_specs == nullptr) {
        state.set_state(old_state);
        delete(result);
        return nullptr;
    }
    return result;
}