//
// Created by gritukan on 6/6/17.
//

#ifndef COMPILER_NODEDECLARATOR_H
#define COMPILER_NODEDECLARATOR_H


#include "NodeDirectDeclarator.h"
#include "NodePointer.h"
#include "ParserState.h"

class NodeDeclarator {
private:
    NodePointer *pointer;
    NodeDirectDeclarator *direct_declarator;
public:
    NodeDeclarator();
    friend NodeDeclarator *parseNodeDeclarator(ParserState &state);

};


#endif //COMPILER_NODEDECLARATOR_H
