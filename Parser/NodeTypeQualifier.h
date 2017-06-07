//
// Created by gritukan on 6/6/17.
//

#ifndef COMPILER_NODETYPEQUALIFIER_H
#define COMPILER_NODETYPEQUALIFIER_H

#include <string>
#include "ParserState.h"

class NodeTypeQualifier {
private:
    std::string value;
public:
    friend NodeTypeQualifier *parseNodeTypeQualifier(ParserState &state);
};


#endif //COMPILER_NODETYPEQUALIFIER_H
