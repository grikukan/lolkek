//
// Created by gritukan on 6/6/17.
//

#ifndef COMPILER_NODEINITIALIZER_H
#define COMPILER_NODEINITIALIZER_H


#include "NodeAssignmentExp.h"
#include "NodeInitializerList.h"
#include "ParserState.h"

class NodeInitializer {
private:
    NodeAssignmentExp *assignment_exp;
    NodeInitializerList *initializer_list;
    bool have_dash;
public:
    NodeInitializer();
    friend NodeInitializer *parseNodeInitializer(ParserState &state);
};


#endif //COMPILER_NODEINITIALIZER_H
