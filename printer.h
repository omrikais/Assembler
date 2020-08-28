/*Created by Omri Kaisari on 12/08/2020.*/

#ifndef ASSEMBLER_PRINTER_H
#define ASSEMBLER_PRINTER_H

#include <stdio.h>
#include "instruction_word.h"
#include "list.h"
#include "code_table.h"
#include "data_table.h"
#include "constants.h"

/**
 * @brief the printer module prints all the needed files in the assembly process, the object file (.obj) and, if
 * needed, the entry (.ent) and extern (.ext) files
 */


/**
 * @brief prints a complete object file according to the assembler specifications, and an extern file, only if at least
 *          one extern label exists. if no such label exists, it won't produce extern file
 * @param instructions      the instructions list of the current file
 * @param dataList          the data list of the current file
 * @param outputObject
 * @param outputExtern
 */
void print_object_and_extern_files(InstructionsList instructions, DataItemsList dataList, FILE *outputObject,
                                   FILE *outputExtern);

/**
 * @brief prints a complete entry file, only if at least one entry label exists  if no such label exists, it won't
 *          produce entry file
 * @param symbols   a list of all the symbols appeared at the source file
 * @param output
 * @return
 */
Error print_entry_file(List symbols, FILE *output);


#endif /*ASSEMBLER_PRINTER_H*/
