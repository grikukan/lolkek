//
// Created by gritukan on 6/6/17.
//

#include "NodeStructDeclList.h"

friend NodeStructDeclList *parseNodeStructDeclList(ParserState &state) {
    NodeStructDeclList *result = new NodeStructDeclList();
    while (true) {
        NodeStructDecl *tmp = parseNodeStructDecl(state);
        if (tmp == nullptr) break;
        result->child.push_back(tmp);
    }
    if (result->child.empty()) {
        delete(result);
        return nullptr;
    }
    std::reverse(result->child.begin(), result->child.end());
    return result;
}
