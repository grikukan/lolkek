//
// Created by gritukan on 6/6/17.
//

#ifndef COMPILER_NODESTRUCTDECL_H
#define COMPILER_NODESTRUCTDECL_H


#include "NodeSpecQualifierList.h"
#include "NodeStructDeclaratorList.h"
#include "ParserState.h"

class NodeStructDecl {
private:
    NodeSpecQualifierList *spec_qualifier_list;
    NodeStructDeclaratorList *struct_declarator_list;
public:
    NodeStructDecl();
    friend NodeStructDecl *parseNodeStructDecl(ParserState &state);
};


#endif //COMPILER_NODESTRUCTDECL_H
