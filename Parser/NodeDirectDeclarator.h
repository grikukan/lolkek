//
// Created by gritukan on 6/6/17.
//

#ifndef COMPILER_NODEDIRECTDECLARATOR_H
#define COMPILER_NODEDIRECTDECLARATOR_H

#include "NodeDeclarator.h"
#include "NodeParamTypeList.h"
#include "NodeIdList.h"
#include "NodeConstExp.h"
#include <string>

class NodeDirectDeclarator {
private:
    std::string id;
    NodeDeclarator *declarator;
    NodeConstExp *const_exp;
    NodeDirectDeclarator *direct_declarator;
    NodeParamTypeList *param_type_list;
    NodeIdList *id_list;
    bool void_args;
public:
    NodeDirectDeclarator();
    friend NodeDirectDeclarator *parseNodeDirectDeclarator(ParserState &state);


};


#endif //COMPILER_NODEDIRECTDECLARATOR_H
