/**********************************************************************************************************************
 ************************************************ The file handler module **********************************************
 **********************************************************************************************************************/

#ifndef ASSEMBLER_FILES_HANDLER_H
#define ASSEMBLER_FILES_HANDLER_H

#include "constants.h"
#include "reader.h"

/**
 * @brief runs the assembly process with the two passes algorithm. checks if any error occured and sends the relevant
 *              arguments to the module-internal functions which are at the files_handler h. file.
 * @param args      the arguments given to the main program (assembler)
 * @param size      the size of args array
 */
void assemble(const char **args, int size);

#endif /*ASSEMBLER_FILES_HANDLER_H*/
