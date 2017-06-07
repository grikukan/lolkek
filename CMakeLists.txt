cmake_minimum_required(VERSION 3.7)
project(compiler)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Tokenizer.cpp Tokenizer.h Token.cpp Token.h)
add_executable(compiler ${SOURCE_FILES})