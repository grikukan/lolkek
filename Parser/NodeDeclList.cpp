//
// Created by gritukan on 6/6/17.
//

#include <algorithm>
#include "NodeDeclList.h"

friend NodeDeclList *parseNodeDeclList(ParserState &state) {
    NodeDeclList *result;
    while (true) {
        NodeDecl *tmp = parseNodeDecl(state);
        if (tmp == nullptr) break;
        result->child.push_back(tmp);
    }
    std::reverse(result->child.begin(), result->child.end());
    return result;
}
