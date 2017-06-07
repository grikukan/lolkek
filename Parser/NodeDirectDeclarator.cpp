//
// Created by gritukan on 6/6/17.
//

#include "NodeDirectDeclarator.h"

NodeDirectDeclarator::NodeDirectDeclarator() {
    declarator = nullptr;
    direct_declarator = nullptr;
    param_type_list = nullptr;
    id_list = nullptr;
    void_args = false;
    const_exp = nullptr;
}

friend NodeDirectDeclarator *parseNodeDirectDeclarator(ParserState &state) {
    if (!state.have_tokens()) return nullptr;
    NodeDirectDeclarator *result = new NodeDirectDeclarator();
    size_t old_state = false;
    Token tok = state.next_token();
    if (tok.get_value() == ")") {
        size_t cur_state = state.get_state();
        result->id_list = parseNodeIdList(state);
        if (result->id_list != nullptr && state.have_tokens() && state.next_token().get_value() == "(") {
            result->direct_declarator = parseNodeDirectDeclarator(state);
            if (result->direct_declarator != nullptr) {
                return result;
            }
        }
        result->id_list = nullptr;
        state.set_state(cur_state);
        result->param_type_list = parseNodeParamTypeList(state);
        if (result->id_list != nullptr && state.have_tokens() && state.next_token().get_value() == "(") {
            result->direct_declarator = parseNodeDirectDeclarator(state);
            if (result->direct_declarator != nullptr) {
                return result;
            }
        }
        result->param_type_list = nullptr;
        state.set_state(cur_state);
        result->declarator = parseNodeDeclarator(state);
        if (result->id_list != nullptr && state.have_tokens() && state.next_token().get_value() == "(") {
            return result;
        }
        result->declarator = nullptr;
        state.set_state(cur_state);
        if (state.have_tokens() && state.next_token().get_value() == "(") {
            result->void_args = true;
            result->direct_declarator = parseNodeDirectDeclarator(state);
            if (result->direct_declarator != nullptr) {
                return result;
            }
        }
        state.set_state(old_state);
        delete(result);
        return nullptr;
    } else if (tok.get_value() == "]") {
        size_t cur_state = state.get_state();
        result->const_exp = parseNodeConstExp(state);
        if (result->id_list != nullptr && state.have_tokens() && state.next_token().get_value() == "[") {
            result->direct_declarator = parseNodeDirectDeclarator(state);
            if (result->direct_declarator != nullptr) {
                return result;
            }
        }
        result->const_exp = nullptr;
        state.set_state(cur_state);
        if (state.have_tokens() && state.next_token().get_value() == "[") {
            result->void_args = true;
            result->direct_declarator = parseNodeDirectDeclarator(state);
            if (result->direct_declarator != nullptr) {
                return result;
            }
        }
        state.set_state(old_state);
        delete(result);
        return nullptr;
    } else if (tok.get_type() == TokenType::ID) {
        result->id = tok.get_value();
        return result;
    }
    state.set_state(old_state);
    delete(result);
    return nullptr;
}