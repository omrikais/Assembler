
/* Created by Omri Kaisari on 05/08/2020.*/

#include "stdlib.h"
#include "instructionWord.h"
#include "constants.h"

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
    int numberOfWords;
};

int instructionWordHowManyWordsByOperand(int addressingMethod);


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
    word->numberOfWords = instructionWordDetermineNumberOfWords(word);
    return word;
}


void instructionWordDestroy(InstructionWord word) {
    free(word);
}

int instructionWordHowManyWordsByOperand(int addressingMethod) {
    int numberOfWords = 0;
    switch (addressingMethod) {
        case IMMEDIATE:
        case DIRECT:
        case RELATIVE:
            numberOfWords = 1;
            break;
        default:
            break;
    }
    return numberOfWords;
}

void instructionWordSetIC(InstructionWord word, int valueOfIc) {
    word->valueOfIC = valueOfIc;
}

int instructionWordDetermineNumberOfWords(InstructionWord word) {
    int totalWords = 1;     /*this number includes the instruction word itself*/
    totalWords += instructionWordHowManyWordsByOperand(word->destinationAddressingMethod) +
                  instructionWordHowManyWordsByOperand(word->sourceAddressingMethod);
    return totalWords;
}

