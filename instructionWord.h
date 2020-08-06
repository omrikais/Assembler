
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

#endif /*ASSEMBLER_INSTRUCTIONWORD_H*/
