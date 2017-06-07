//
// Created by gritukan on 6/7/17.
//

#ifndef COMPILER_NODEENUMSPEC_H
#define COMPILER_NODEENUMSPEC_H


#include "NodeEnumeratorList.h"
#include "ParserState.h"

class NodeEnumSpec {
private:
    NodeEnumeratorList *enumerator_list;
    std::string id;
public:
    NodeEnumSpec();
    friend NodeEnumSpec *parseNodeEnumSpec(ParserState &state);
};


#endif //COMPILER_NODEENUMSPEC_H
