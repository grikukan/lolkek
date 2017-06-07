//
// Created by gritukan on 6/6/17.
//

#include "NodeTypeSpec.h"

NodeTypeSpec::NodeTypeSpec() {
    struct_or_union_spec = nullptr;
    enum_spec = nullptr;
    typedef_name = nullptr;
}

friend NodeTypeSpec *parseNodeTypeSpec(ParserState &state) {
    size_t old_state = state.get_state();
    NodeTypeSpec *result = new NodeTypeSpec();
    if (state.have_tokens()) {
        std::string token = state.next_token().get_value();
        if (token == "void" || token == "char" || token == "short" || token == "int" ||
            token == "long" || token == "float" || token == "double" || token == "signed"
            || token == "unsigned") {
            result->value = token;
            return result;
        }
    }
    state.set_state(old_state);
    NodeStructOrUnionSpec *tmpspec = parseNodeStructOrUnionSpec(state);
    if (tmpspec != nullptr) {
        result->struct_or_union_spec = tmpspec;
        return result;
    }
    NodeEnumSpec *tmpenum = parseNodeEnumSpec(state);
    if (tmpenum != nullptr) {
        result->enum_spec = tmpenum;
        return result;
    }
    NodeTypedefName *tmptypedef = parseTypedefName(state);
    if (tmptypedef != nullptr) {
        result->typedef_name = tmptypedef;
        return result;
    }
    delete(result);
    return nullptr;
}