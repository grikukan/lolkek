//
// Created by gritukan on 6/6/17.
//

#ifndef COMPILER_NODEPOINTER_H
#define COMPILER_NODEPOINTER_H


#include "NodeTypeQualifierList.h"
#include "ParserState.h"

class NodePointer {
private:
    size_t pointer_depth;
    NodeTypeQualifierList *type_qualifier_list;
public:
    NodePointer();
    friend NodePointer *parseNodePointer(ParserState &state);
};


#endif //COMPILER_NODEPOINTER_H
