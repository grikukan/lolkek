//
// Created by gritukan on 6/6/17.
//

#ifndef COMPILER_NODEINITDECLARATOR_H
#define COMPILER_NODEINITDECLARATOR_H


#include "NodeDeclarator.h"
#include "NodeInitializer.h"
#include "ParserState.h"

class NodeInitDeclarator {
private:
    NodeDeclarator *declarator;
    NodeInitializer *initializer;
public:
    NodeInitDeclarator();
    friend NodeInitDeclarator *parseNodeInitDeclarator(ParserState &state);
};


#endif //COMPILER_NODEINITDECLARATOR_H
