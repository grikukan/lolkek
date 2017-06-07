//
// Created by gritukan on 6/6/17.
//

#ifndef COMPILER_NODESTRUCTDECLARATOR_H
#define COMPILER_NODESTRUCTDECLARATOR_H


#include "NodeDeclarator.h"
#include "NodeConstExp.h"
#include "ParserState.h"

class NodeStructDeclarator {
private:
    NodeDeclarator *declarator;
    NodeConstExp *constExp;
public:
    NodeStructDeclarator();
    friend NodeStructDeclarator *parseNodeStructDeclarator(ParserState &state);
};


#endif //COMPILER_NODESTRUCTDECLARATOR_H
