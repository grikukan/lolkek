//
// Created by gritukan on 6/6/17.
//

#ifndef COMPILER_NODEIDLIST_H
#define COMPILER_NODEIDLIST_H

#include <vector>
#include <string>
#include "ParserState.h"

class NodeIdList {
private:
    std::vector<std::string> id;
public:
    friend NodeIdList *parseNodeIdList(ParserState &state);
};


#endif //COMPILER_NODEIDLIST_H
