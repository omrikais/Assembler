/**********************************************************************************************************************
 ************************************************ The code table module ***********************************************
 **********************************************************************************************************************/

#ifndef ASSEMBLER_CODE_TABLE_H
#define ASSEMBLER_CODE_TABLE_H

#include "parser.h"
#include "instruction_word.h"
#include "list.h"

typedef struct code_list_t *InstructionsList;           /*the InstructionsList type definition*/

/**
 * @brief       created an instruction list object and allocates all its relevant memory
 * @return      an empty instruction list
 */
InstructionsList instruction_list_create();

/**
 * @brief                   returns the current IC value of the assembler program
 * @param instructions      the current file instructions list
 * @return                  the current IC value of the assembler program
 */
int instruction_list_get_ic(InstructionsList instructions);

/**
 * @brief                   add a new instruction to the instructions list
 * @param instructions      the current file instructions list
 * @param word              the instruction word to add
 */
void instruction_list_add_instruction(InstructionsList instructions, InstructionWord word);

/**
 * @brief                   deallocated all the memory and the contents of the given instructions list
 * @param instructions      the instructions list to destroy
 */
void instruction_list_destroy(InstructionsList instructions);

/**
 * @brief                   returns the size of the instructions list, i.e how many instructions does it store
 * @param instructions      the current file instructions list
 * @return                  the size of the instructions list
 */
int instruction_list_get_number_of_instructions(InstructionsList instructions);

/**
 * @brief                   returns the instruction in the given index within the instructions list
 * @param instructions      the current file instructions list
 * @param i                 the position of the instruction
 * @return                  the instruction word at the given index
 */
InstructionWord instruction_list_get_instruction(InstructionsList instructions, int i);

#endif /*ASSEMBLER_CODE_TABLE_H*/
