//
// Created by gritukan on 6/6/17.
//

#ifndef COMPILER_NODEPARAMLIST_H
#define COMPILER_NODEPARAMLIST_H


#include <vector>
#include "NodeParamDecl.h"
#include "ParserState.h"

class NodeParamList {
private:
    std::vector<NodeParamDecl*> param_decl;
public:
    friend NodeParamList *parseNodeParamList(ParserState &state);
};


#endif //COMPILER_NODEPARAMLIST_H
