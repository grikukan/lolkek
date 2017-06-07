//
// Created by gritukan on 6/6/17.
//

#ifndef COMPILER_NODESPECQUALIFIERLIST_H
#define COMPILER_NODESPECQUALIFIERLIST_H


#include "NodeTypeSpec.h"
#include "NodeTypeQualifier.h"

class NodeSpecQualifierList {
private:
    std::vector<NodeTypeSpec*> type_spec;
    std::vector<NodeTypeQualifier*> type_qualifier;
public:
    friend NodeSpecQualifierList *parseNodeSpecQualifierList(ParserState &state);

};


#endif //COMPILER_NODESPECQUALIFIERLIST_H
