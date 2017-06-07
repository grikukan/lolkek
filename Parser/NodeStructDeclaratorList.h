//
// Created by gritukan on 6/6/17.
//

#ifndef COMPILER_NODESTRUCTDECLARATORLIST_H
#define COMPILER_NODESTRUCTDECLARATORLIST_H


#include <vector>
#include "NodeStructDeclarator.h"
#include "ParserState.h"

class NodeStructDeclaratorList {
private:
    std::vector<NodeStructDeclarator*> struct_declarator;
public:
    friend NodeStructDeclaratorList *parseNodeStructDeclaratorList(ParserState &state);
};


#endif //COMPILER_NODESTRUCTDECLARATORLIST_H
