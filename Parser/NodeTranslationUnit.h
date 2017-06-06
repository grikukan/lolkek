//
// Created by gritukan on 6/6/17.
//

#ifndef COMPILER_NODETRANSLATIONUNIT_H
#define COMPILER_NODETRANSLATIONUNIT_H


#include <vector>
#include "NodeExternalDecl.h"
#include "ParserState.h"

class NodeTranslationUnit {
private:
    std::vector<NodeExternalDecl*> child;
public:
    friend NodeTranslationUnit *parseNodeTranslationUnit(ParserState &state);
};


#endif //COMPILER_NODETRANSLATIONUNIT_H
