//
// Created by gritukan on 6/6/17.
//

#ifndef COMPILER_NODEABSTRACTDECLARATOR_H
#define COMPILER_NODEABSTRACTDECLARATOR_H


#include "NodePointer.h"
#include "NodeDirectAbstractDeclarator.h"

class NodeAbstractDeclarator {
private:
    NodePointer *pointer;
    NodeDirectAbstractDeclarator *direct_abstract_declarator;
public:
    NodeAbstractDeclarator();
    friend NodeAbstractDeclarator *parseNodeAbstractDeclarator(ParserState &state);
};


#endif //COMPILER_NODEABSTRACTDECLARATOR_H
