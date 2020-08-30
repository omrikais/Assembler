/**********************************************************************************************************************
 ************************************************ The assembler  Program ***********************************************
 **********************************************************************************************************************/

#include "files_handler.h"

/**
 * @brief           the assembler program should get a list of assembly source code files names, without their
 *                  extension. the program will create an object file and entry/extern files - if needed.
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, char *argv[]) {
    assemble((const char **) argv, argc);
    return 0;
}

