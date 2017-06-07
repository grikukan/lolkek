//
// Created by gritukan on 6/6/17.
//

#include "NodeParamDecl.h"

NodeParamDecl::NodeParamDecl() {
    abstract_declarator = nullptr;
    declarator = nullptr;
    decl_specs = nullptr;
}
friend NodeParamDecl *parseNodeparamDecl(ParserState &state) {
    NodeParamDecl *result = new NodeParamDecl();
    size_t old_state = state.get_state();
    result->abstract_declarator = parseNodeAbstractDeclarator(state);
    if (result->abstract_declarator == nullptr) {
        result->declarator = parseNodeDeclarator(state);
    }
    result->decl_specs = parseNodeDeclSpecs(state);
    if (result->decl_specs == nullptr) {
        state.set_state(old_state);
        delete(result);
        return nullptr;
    }
    return result;
}