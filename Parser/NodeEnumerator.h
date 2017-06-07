//
// Created by gritukan on 6/6/17.
//

#ifndef COMPILER_NODEENUMERATOR_H
#define COMPILER_NODEENUMERATOR_H

#include <string>
#include "NodeConstExp.h"
#include "ParserState.h"

class NodeEnumerator {
private:
    std::string id;
    NodeConstExp *const_exp;
public:
    NodeEnumerator();
    friend NodeEnumerator *parseNodeEnumerator(ParserState &state);
};


#endif //COMPILER_NODEENUMERATOR_H
