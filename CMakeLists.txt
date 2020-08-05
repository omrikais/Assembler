cmake_minimum_required(VERSION 3.17)
project(Assembler C)

set(CMAKE_C_FLAGS  "-Wall -ansi -pedantic")
add_executable(Assembler Tester.c List.c List.h )