//
// Created by gritukan on 6/6/17.
//

#ifndef COMPILER_NODEFUNCTIONDEFINITION_H
#define COMPILER_NODEFUNCTIONDEFINITION_H


#include "NodeDeclSpecs.h"
#include "NodeDeclarator.h"
#include "NodeDeclList.h"
#include "NodeCompoundStat.h"
#include "ParserState.h"

class NodeFunctionDefinition {
private:
    NodeDeclSpecs *decl_specs;
    NodeDeclarator *declarator;
    NodeDeclList *decl_list;
    NodeCompoundStat *compound_stat;
public:
    NodeFunctionDefinition();
    friend NodeFunctionDefinition *parseNodeFunctionDefinition(ParserState &state);

};


#endif //COMPILER_NODEFUNCTIONDEFINITION_H
