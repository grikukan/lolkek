//
// Created by gritukan on 6/6/17.
//

#ifndef COMPILER_NODETYPESPEC_H
#define COMPILER_NODETYPESPEC_H


#include "NodeStructOrUnionSpec.h"
#include "NodeEnumSpec.h"
#include "NodeTypedefName.h"
#include "ParserState.h"
#include <string>

class NodeTypeSpec {
private:
    std::string value;
    NodeStructOrUnionSpec *struct_or_union_spec;
    NodeEnumSpec *enum_spec;
    NodeTypedefName *typedef_name;
    NodeTypeSpec();
public:
    friend NodeTypeSpec *parseNodeTypeSpec(ParserState &state);
};


#endif //COMPILER_NODETYPESPEC_H
