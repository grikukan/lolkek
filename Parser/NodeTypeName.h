//
// Created by gritukan on 6/6/17.
//

#ifndef COMPILER_NODETYPENAME_H
#define COMPILER_NODETYPENAME_H


#include "NodeAbstractDeclarator.h"
#include "NodeSpecQualifierList.h"

class NodeTypeName {
private:
    NodeAbstractDeclarator *abstract_declarator;
    NodeSpecQualifierList *spec_qualifier_list;
public:
    NodeTypeName();
    friend NodeTypeName *parseNodeTypeName(ParserState &state);
};


#endif //COMPILER_NODETYPENAME_H
