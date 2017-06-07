//
// Created by gritukan on 6/6/17.
//

#ifndef COMPILER_NODEINITIALIZERLIST_H
#define COMPILER_NODEINITIALIZERLIST_H


#include "NodeInitializer.h"

class NodeInitializerList {
private:
    std::vector<NodeInitializer*> initializer;
public:
    friend NodeInitializerList *parseNodeInitializerList(ParserState &state);
};


#endif //COMPILER_NODEINITIALIZERLIST_H
