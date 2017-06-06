//
// Created by gritukan on 6/6/17.
//

#include "NodeFunctionDefinition.h"

NodeFunctionDefinition::NodeFunctionDefinition() {
    decl_specs = nullptr;
    declarator = nullptr;
    decl_list = nullptr;
    compound_stat = nullptr;
}

friend NodeFunctionDefinition *parseNodeFunctionDefinition(ParserState &state) {
    NodeFunctionDefinition *result = new NodeFunctionDefinition();
    result->compound_stat = parseNodeCompoundStat(state);
    if (result->compound_stat == nullptr) {
        delete(result);
        return nullptr;
    }
    old_state = state.get_state();
    result->decl_list = parseNodeDeclList(state);
    old_state = state.get_state();
    result->declarator = parseNodeDeclarator(state);
    if (result->declarator == nullptr) {
        delete(result);
        return nullptr;
    }
    old_state = state.get_state();
    result->decl_specs= parseNodeDeclSpecs(state);
    return result;
}