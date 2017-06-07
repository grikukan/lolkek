//
// Created by gritukan on 6/6/17.
//

#ifndef COMPILER_NODETYPEQUALIFIERLIST_H
#define COMPILER_NODETYPEQUALIFIERLIST_H


#include "NodeTypeQualifier.h"

class NodeTypeQualifierList {
private:
    std::vector<NodeTypeQualifier*> type_qualifier;
public:
    friend NodeTypeQualifierList *parseNodeTypeQualifierList(ParserState &state);
};


#endif //COMPILER_NODETYPEQUALIFIERLIST_H
