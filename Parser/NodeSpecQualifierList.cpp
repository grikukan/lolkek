//
// Created by gritukan on 6/6/17.
//

#include "NodeSpecQualifierList.h"

friend NodeSpecQualifierList *parseNodeSpecQualifierList(ParserState &state) {
    NodeSpecQualifierList *result = new NodeSpecQualifierList();
    bool added = false;
    while (true) {
        NodeTypeSpec *tmpspec = parseNodeTypeSpec(state);
        if (tmpspec != nullptr) {
            result->type_spec.push_back(tmpspec);
            added = true;
        }
        NodeTypeQualifier *tmpqual = parseNodeTypeQualifier(state);
        if (tmpqual != nullptr) {
            result->type_qualifier.push_back(tmpqual);
            added = true;
        }
        if (!added) break;
        added = false;
    }
    if (result->type_qualifier.empty() && result->type_spec.empty()) {
        delete(result);
        return nullptr;
    }
    std::reverse(result->type_spec.begin(), result->type_spec.end());
    std::reverse(result->type_qualifier.begin(), result->type_qualifier.end());
    return result;
}