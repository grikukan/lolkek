//
// Created by gritukan on 6/6/17.
//

#include "NodeDeclSpecs.h"

friend NodeDeclSpecs *parseNodeDeclSpecs(ParserState &state) {
    NodeDeclSpecs *result;
    bool added = false;
    while (true) {
        NodeStorageClassSpec *tmpspec = parseNodeStorageClassSpec(state);
        if (tmpspec != nullptr) {
            result->storage_class_spec.push_back(tmpspec);
            added = true;
        }
        NodeTypeSpec *tmptype = parseTypeSpec(state);
        if (tmptype != nullptr) {
            result->type_spec.push_back(tmptype);
            added = true;
        }
        NodeTypeQualifier *tmpqual = parseNodeTypeQualifier(state);
        if (tmptype != nullptr) {
            result->type_qualifier.push_back(tmpqual);
            added = true;
        }
        if (!added) break;
        added = false;
    }
    if (result->storage_class_spec.empty() && result->type_spec.empty() && result->type_qualifier.empty()) {
        delete(result);
        return nullptr;
    }
    return result;
}