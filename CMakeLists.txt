cmake_minimum_required(VERSION 3.17)
project(Assembler C)

set(CMAKE_C_FLAGS "-Wall -ansi -pedantic")
add_executable(Assembler tester.c list.c list.h instructionWord.c instructionWord.h constants.h parser.c parser.h errors.c errors.h code_table.c code_table.h data_table.c data_table.h symbol_table.c symbol_table.h)