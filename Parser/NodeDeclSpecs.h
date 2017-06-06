//
// Created by gritukan on 6/6/17.
//

#ifndef COMPILER_NODEDECLSPECS_H
#define COMPILER_NODEDECLSPECS_H


#include <vector>
#include "NodeStorageClassSpec.h"
#include "NodeTypeSpec.h"
#include "NodeTypeQualifier.h"
#include "ParserState.h"

class NodeDeclSpecs {
    std::vector<NodeStorageClassSpec*> storage_class_spec;
    std::vector<NodeTypeSpec*> type_spec;
    std::vector<NodeTypeQualifier*> type_qualifier;
public:
    friend NodeDeclSpecs *parseNodeDeclSpecs(ParserState &state);
};


#endif //COMPILER_NODEDECLSPECS_H
