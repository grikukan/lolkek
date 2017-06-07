//
// Created by gritukan on 6/6/17.
//

#ifndef COMPILER_NODESTRUCTORUNIONSPEC_H
#define COMPILER_NODESTRUCTORUNIONSPEC_H


#include "NodeStructOrUnion.h"
#include "NodeStructDeclList.h"
#include "ParserState.h"
#include <string>

class NodeStructOrUnionSpec {
private:
    NodeStructOrUnion *struct_or_union;
    std::string id;
    NodeStructDeclList *struct_decl_list;
    NodeStructOrUnionSpec();
public:
    friend NodeStructOrUnionSpec *parseNodeStructOrUnionSpec(ParserState &state);
};


#endif //COMPILER_NODESTRUCTORUNIONSPEC_H
