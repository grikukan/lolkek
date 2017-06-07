//
// Created by gritukan on 6/6/17.
//

#ifndef COMPILER_NODEPARAMTYPELIST_H
#define COMPILER_NODEPARAMTYPELIST_H


#include "NodeParamList.h"
#include "ParserState.h"

class NodeParamTypeList {
private:
    bool is_va_args;
    NodeParamList *param_list;
public:
    NodeParamTypeList();
    friend NodeParamTypeList *parseNodeParamTypeList(ParserState &state);
};


#endif //COMPILER_NODEPARAMTYPELIST_H
