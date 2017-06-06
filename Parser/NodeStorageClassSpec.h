//
// Created by gritukan on 6/6/17.
//

#ifndef COMPILER_NODESTORAGECLASSSPEC_H
#define COMPILER_NODESTORAGECLASSSPEC_H

#include <string>
#include "ParserState.h"

class NodeStorageClassSpec {
private:
    std::string value;
public:
    NodeStorageClassSpec(const std::string &s);
    friend NodeStorageClassSpec *parseNodeStorageClassSpec(ParserState &state);
};


#endif //COMPILER_NODESTORAGECLASSSPEC_H
