cmake_minimum_required(VERSION 3.17)
project(Assembler C)

set(CMAKE_C_FLAGS "-Wall -ansi -pedantic")
add_executable(FileGeneratorTests sand_box.c list.c list.h instruction_word.c instruction_word.h constants.h parser.c parser.h errors.c errors.h code_table.c code_table.h data_table.c data_table.h symbol_table.c symbol_table.h builder.c builder.h reader.c reader.h printer.c printer.h files_handler.c files_handler.h)
add_executable(BuilderTests list.c list.h instruction_word.c instruction_word.h constants.h parser.c parser.h errors.c errors.h code_table.c code_table.h data_table.c data_table.h symbol_table.c symbol_table.h builder.c builder.h builder_tests.c reader.c reader.h printer.c printer.h files_handler.c files_handler.h)
add_executable(Tester list.c list.h instruction_word.c instruction_word.h constants.h parser.c parser.h errors.c errors.h code_table.c code_table.h data_table.c data_table.h symbol_table.c symbol_table.h builder.c builder.h tester.c reader.c reader.h printer.c printer.h files_handler.c files_handler.h)
add_executable(assembler list.c list.h instruction_word.c instruction_word.h constants.h parser.c parser.h errors.c errors.h code_table.c code_table.h data_table.c data_table.h symbol_table.c symbol_table.h builder.c builder.h reader.c reader.h printer.c printer.h files_handler.c files_handler.h assembler.c)