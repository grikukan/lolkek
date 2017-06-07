//
// Created by gritukan on 6/6/17.
//

#ifndef COMPILER_NODEENUMERATORLIST_H
#define COMPILER_NODEENUMERATORLIST_H


#include <vector>
#include <algorithm>
#include "NodeEnumerator.h"
#include "ParserState.h"

class NodeEnumeratorList {
private:
    std::vector<NodeEnumerator*> enumerator;
public:
    friend NodeEnumeratorList *parseNodeEnumeratorList(ParserState &state);
};


#endif //COMPILER_NODEENUMERATORLIST_H
