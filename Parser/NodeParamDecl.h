//
// Created by gritukan on 6/6/17.
//

#ifndef COMPILER_NODEPARAMDECL_H
#define COMPILER_NODEPARAMDECL_H


#include "NodeAbstractDeclarator.h"
#include "NodeDeclarator.h"
#include "NodeDeclSpecs.h"

class NodeParamDecl {
private:
    NodeAbstractDeclarator *abstract_declarator;
    NodeDeclarator *declarator;
    NodeDeclSpecs *decl_specs;
public:
    NodeParamDecl();
    friend NodeParamDecl *parseNodeparamDecl(ParserState &state);
};


#endif //COMPILER_NODEPARAMDECL_H
