//
// Created by gritukan on 6/6/17.
//

#include <algorithm>
#include "NodeTypeQualifierList.h"

friend NodeTypeQualifierList *parseNodeTypeQualifierList(ParserState &state) {
    NodeTypeQualifierList *result = new NodeTypeQualifierList();
    while (true) {
        result->type_qualifier.push_back(parseNodeTypeQualifier(state));
        if (result->type_qualifier.back() == nullptr) {
            result->type_qualifier.pop_back();
            break;
        }
    }
    if (result->type_qualifier.empty()) {
        delete(result);
        return nullptr;
    }
    std::reverse(result->type_qualifier.begin(), result->type_qualifier.end());
    return result;
}