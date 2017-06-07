//
// Created by gritukan on 6/6/17.
//

#include "NodeDeclarator.h"

NodeDeclarator::NodeDeclarator() {
    pointer = nullptr;
    direct_declarator = nullptr;
}
friend NodeDeclarator *parseNodeDeclarator(ParserState &state) {
    NodeDeclarator *result = new NodeDeclarator();
    result->direct_declarator = parseNodeDirectDeclarator(state);
    if (result->direct_declarator == nullptr) {
        delete(result);
        return nullptr;
    }
    result->pointer = parseNodePointer(state);
    return result;
}