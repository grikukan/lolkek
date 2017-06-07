//
// Created by gritukan on 6/6/17.
//

#include "NodeTypeName.h"

NodeTypeName::NodeTypeName() {
    spec_qualifier_list = nullptr;
    abstract_declarator = nullptr;
}
friend NodeTypeName *parseNodeTypeName(ParserState &state) {
    NodeTypeName *result = new NodeTypeName();
    size_t old_state = state.get_state();
    result->abstract_declarator = parseNodeAbstractDeclarator(state);
    result->spec_qualifier_list = parseNodeSpecQualifierList(state);
    if (result->spec_qualifier_list) {
        state.set_state(old_state);
        delete(result);
        return nullptr;
    }
    return result;
}