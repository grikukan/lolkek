//
// Created by gritukan on 6/6/17.
//

#ifndef COMPILER_EXTERNALDECL_H
#define COMPILER_EXTERNALDECL_H


#include "NodeFunctionDefinition.h"
#include "ParserState.h"
#include "NodeDecl.h"

class NodeExternalDecl {
private:
    NodeFunctionDefinition *function;
    NodeDecl *decl;
public:
    NodeExternalDecl();
    friend NodeExternalDecl *parseNodeExternalDecl(ParserState &state);
};


#endif //COMPILER_EXTERNALDECL_H
