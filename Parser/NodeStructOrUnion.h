//
// Created by gritukan on 6/6/17.
//

#ifndef COMPILER_NODESTRUCTORUNION_H
#define COMPILER_NODESTRUCTORUNION_H

#include <string>
#include "ParserState.h"

class NodeStructOrUnion {
private:
    std::string value;
public:
    friend NodeStructOrUnion *parseNodeStructOrUnion(ParserState &state);
};


#endif //COMPILER_NODESTRUCTORUNION_H
