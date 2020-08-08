
/* Created by Omri Kaisari on 08/08/2020.*/


#ifndef ASSEMBLER_CODE_TABLE_H
#define ASSEMBLER_CODE_TABLE_H

#include "parser.h"
#include "instructionWord.h"
#include "list.h"

typedef struct codeListT *InstructionsList;


InstructionsList instructionListCreate();

int instructionListGetIC(InstructionsList instructions);

void instructionListAddInstruction(InstructionsList instructions, InstructionWord word);

void instructionListDestroy(InstructionsList instructions);

InstructionWord instructionListGetInstruction(InstructionsList instructions, int i);

#endif /*ASSEMBLER_CODE_TABLE_H*/
