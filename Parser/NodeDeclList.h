//
// Created by gritukan on 6/6/17.
//

#ifndef COMPILER_NODEDECLLIST_H
#define COMPILER_NODEDECLLIST_H


#include "NodeDecl.h"

class NodeDeclList {
private:
    std::vector<NodeDecl*> child;
public:
    friend NodeDeclList *parseNodeDeclList(ParserState &state);
};


#endif //COMPILER_NODEDECLLIST_H
