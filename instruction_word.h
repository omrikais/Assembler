
/* Created by Omri Kaisari on 05/08/2020.*/

#ifndef ASSEMBLER_INSTRUCTION_WORD_H
#define ASSEMBLER_INSTRUCTION_WORD_H

typedef struct instruction_word_t *InstructionWord;

InstructionWord instruction_word_create(int opcode, int func, int sourceAddressingMethod, int sourceRegister,
                                        int destinationAddressingMethod, int destinationRegister,
                                        int sourceOperandContent, int destinationOperandContent);

void instruction_word_destroy(InstructionWord word);

int instruction_word_determine_number_of_words(InstructionWord word);

void instruction_word_set_ic(InstructionWord word, int valueOfIc);

int instruction_word_get_number_of_words(InstructionWord word);

void instruction_word_set_destination_string(InstructionWord word, const char *string);

void instruction_word_set_source_string(InstructionWord word, const char *string);

void instruction_word_set_operand_content(InstructionWord word, int address, int operandIndex);

const char *instruction_word_get_destination_string(InstructionWord word);

int instruction_word_get_ic(InstructionWord word);

const char *instruction_word_get_source_string(InstructionWord word);

int instruction_word_get_addressing_method(InstructionWord word, int operandIndex);

void instruction_word_destroy_tmp(InstructionWord word);

size_t instruction_word_get_size();

#endif /*ASSEMBLER_INSTRUCTION_WORD_H*/
