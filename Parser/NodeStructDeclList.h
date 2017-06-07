//
// Created by gritukan on 6/6/17.
//

#ifndef COMPILER_NODESTRUCTDECLLIST_H
#define COMPILER_NODESTRUCTDECLLIST_H


#include <vector>
#include <algorithm>
#include "NodeStructDecl.h"
#include "ParserState.h"

class NodeStructDeclList {
private:
    std::vector<NodeStructDecl*> child;
public:
    friend NodeStructDeclList *parseNodeStructDeclList(ParserState &state);
};


#endif //COMPILER_NODESTRUCTDECLLIST_H
