//
// Created by gritukan on 6/6/17.
//

#ifndef COMPILER_NODEDECL_H
#define COMPILER_NODEDECL_H


#include "NodeDeclSpecs.h"
#include "NodeInitDeclaratorList.h"
#include "ParserState.h"

class NodeDecl {
private:
    NodeDeclSpecs *decl_specs;
    NodeInitDeclaratorList *init_declarator_list;
public:
    NodeDecl();
    friend NodeDecl *parseNodeDecl(ParserState &state);
};


#endif //COMPILER_NODEDECL_H
