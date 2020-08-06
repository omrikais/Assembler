
/* Created by Omri Kaisari on 05/08/2020.*/

#include "stdlib.h"
#include "InstructionWord.h"

struct instructionWordT {
    int opcode;
    int func;
    int sourceAddressingMethod;
    int sourceRegister;
    int destinationAddressingMethod;
    int destinationRegister;
    int sourceOperandContent;
    int destinationOperandContent;
    int valueOfIC;
    int valueOfL;
    int numberOfWords;
};

InstructionWord instructionWordCreate(int opcode, int func, int sourceAddressingMethod, int sourceRegister,
                                      int destinationAddressingMethod, int destinationRegister,
                                      int sourceOperandContent, int destinationOperandContent) {
    InstructionWord word = malloc(sizeof(*word));
    word->opcode = opcode;
    word->func = func;
    word->sourceAddressingMethod = sourceAddressingMethod;
    word->sourceRegister = sourceRegister;
    word->destinationAddressingMethod = destinationAddressingMethod;
    word->destinationRegister = destinationRegister;
    word->sourceOperandContent = sourceOperandContent;
    word->destinationOperandContent = destinationOperandContent;
    return word;
}

void instructionWordDestroy(InstructionWord word) {
    free(word);
}
