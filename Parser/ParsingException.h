//
// Created by gritukan on 6/6/17.
//

#include <exception>
#include <string>
#ifndef COMPILER_PARSINGEXCEPTION_H
#define COMPILER_PARSINGEXCEPTION_H


class ParsingException : public std::exception {
private:
    std::string text;
public:
    ParsingException(const std::string &s) {
        text = s;
    }
    virtual const char* what() const throw() {
        return text.c_str();
    }
};


#endif //COMPILER_PARSINGEXCEPTION_H
