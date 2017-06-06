//
// Created by gritukan on 6/6/17.
//

#include "NodeExternalDecl.h"
#include "ParsingException.h"

NodeExternalDecl::NodeExternalDecl() {
    function = nullptr;
    decl = nullptr;
}
friend NodeExternalDecl *parseNodeExternalDecl(ParserState &state) {
    NodeExternalDecl *result = new NodeExternalDecl();
    result->function = parseNodeFunctionDefinition(state);
    if (result->function == nullptr) {
        result->decl = parseNodeDecl(state);
        if (result->decl == nullptr) {
            delete(result);
            return nullptr;
        }
    }
    return result;
}