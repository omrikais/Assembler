
/* Created by Omri Kaisari on 05/08/2020.*/

#ifndef ASSEMBLER_INSTRUCTIONWORD_H
#define ASSEMBLER_INSTRUCTIONWORD_H

typedef struct instructionWordT *InstructionWord;

InstructionWord instructionWordCreate(int opcode, int func, int sourceAddressingMethod, int sourceRegister,
                                      int destinationAddressingMethod, int destinationRegister,
                                      int sourceOperandContent, int destinationOperandContent);

void instructionWordDestroy(InstructionWord word);

int instructionWordDetermineNumberOfWords(InstructionWord word);

void instructionWordSetIC(InstructionWord word, int valueOfIc);

int instructionWordGetNumberOfWords(InstructionWord word);

size_t instructionWordGetSize();

#endif /*ASSEMBLER_INSTRUCTIONWORD_H*/
