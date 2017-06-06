#include <iostream>
#include <fstream>
#include <string>
#include "Tokenizer.h"
int main(int argc, char **argv) {
    std::cerr << argc << std::endl;
    if (argc != 2) {
        std::cerr << "Usage fuckc <filename>" << std::endl;
        return 1;
    }
    std::ifstream source_file((std::string(argv[1])));
    std::string source;
    while (!source_file.eof()) {
        std::string tmp;
        std::getline(source_file, tmp);
        source += "\n";
        source += tmp;
    }
    Tokenizer tokenizer;
    std::vector<Token> tokens = tokenizer.tokenize(source);

}