
/* Created by Omri Kaisari on 08/08/2020.*/


#ifndef ASSEMBLER_CODE_TABLE_H
#define ASSEMBLER_CODE_TABLE_H

#include "parser.h"
#include "instruction_word.h"
#include "list.h"

typedef struct code_list_t *InstructionsList;


InstructionsList instruction_list_create();

int instruction_list_get_ic(InstructionsList instructions);

void instruction_list_add_instruction(InstructionsList instructions, InstructionWord word);

void instruction_list_destroy(InstructionsList instructions);

InstructionWord instruction_list_get_instruction(InstructionsList instructions, int i);

#endif /*ASSEMBLER_CODE_TABLE_H*/
