//
// Created by gritukan on 6/6/17.
//

#ifndef COMPILER_NODEINITDECLARATORLIST_H
#define COMPILER_NODEINITDECLARATORLIST_H


#include <vector>
#include <algorithm>
#include "NodeInitDeclarator.h"
#include "ParserState.h"

class NodeInitDeclaratorList {
private:
    std::vector<NodeInitDeclarator*> child;
public:
    friend NodeInitDeclaratorList *parseNodeInitDeclaratorList(ParserState &state);
};


#endif //COMPILER_NODEINITDECLARATORLIST_H
