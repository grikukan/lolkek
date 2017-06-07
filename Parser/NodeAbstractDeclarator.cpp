//
// Created by gritukan on 6/6/17.
//

#include "NodeAbstractDeclarator.h"

NodeAbstractDeclarator::NodeAbstractDeclarator() {
    pointer = nullptr;
    direct_abstract_declarator = nullptr;
}

friend NodeAbstractDeclarator *parseNodeAbstractDeclarator(ParserState &state) {
    NodeAbstractDeclarator *result = new NodeAbstractDeclarator();
    result->direct_abstract_declarator = parseNodeDirectAbstractDeclarator(state);
    result->pointer = parseNodePointer(state);
    if (result->direct_abstract_declarator == nullptr && result->pointer == nullptr) {
        return nullptr;
    }
    return result;
}