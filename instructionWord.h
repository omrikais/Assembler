
/* Created by Omri Kaisari on 05/08/2020.*/

#ifndef ASSEMBLER_INSTRUCTIONWORD_H
#define ASSEMBLER_INSTRUCTIONWORD_H

typedef struct instruction_word_t *InstructionWord;

InstructionWord instruction_word_create(int opcode, int func, int sourceAddressingMethod, int sourceRegister,
                                        int destinationAddressingMethod, int destinationRegister,
                                        int sourceOperandContent, int destinationOperandContent);

void instruction_word_destroy(InstructionWord word);

int instruction_word_determine_number_of_words(InstructionWord word);

void instruction_word_set_ic(InstructionWord word, int valueOfIc);

int instruction_word_get_number_of_words(InstructionWord word);

size_t instruction_word_get_size();

#endif /*ASSEMBLER_INSTRUCTIONWORD_H*/
