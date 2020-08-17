
/* Created by Omri Kaisari on 05/08/2020.*/

#include <stdlib.h>
#include "instruction_word.h"

#include <string.h>

struct instruction_word_t {
    int opcode;
    int func;
    int sourceAddressingMethod;
    int sourceRegister;
    int destinationAddressingMethod;
    int destinationRegister;
    long sourceOperandContent;
    char *sourceOperandContentStr;
    long destinationOperandContent;
    char *destinationOperandContentStr;
    int valueOfIC;
    int numberOfWords;
    Bool isDestinationExtern;
    Bool isSourceExtern;
};

int instruction_word_how_many_words_by_operand(int addressingMethod);

Bool instruction_word_has_operand(Operation operation, int indexOfOperation);


InstructionWord instruction_word_create(int opcode, int func, int sourceAddressingMethod, int sourceRegister,
                                        int destinationAddressingMethod, int destinationRegister,
                                        long sourceOperandContent, long destinationOperandContent) {
    InstructionWord word = malloc(sizeof(*word));
    word->opcode = opcode;
    word->func = func;
    word->sourceAddressingMethod = sourceAddressingMethod;
    word->sourceRegister = sourceRegister;
    word->destinationAddressingMethod = destinationAddressingMethod;
    word->destinationRegister = destinationRegister;
    word->sourceOperandContent = sourceOperandContent;
    word->destinationOperandContent = destinationOperandContent;
    word->numberOfWords = instruction_word_determine_number_of_words(word);
    word->destinationOperandContentStr = NULL;
    word->sourceOperandContentStr = NULL;
    word->isDestinationExtern = -1;
    word->isSourceExtern = False;
    return word;
}

size_t instruction_word_get_size() {
    return sizeof(struct instruction_word_t);
}

int instruction_word_get_opcode(InstructionWord word) {
    return word->opcode;
}

long *instruction_word_get_all_parameters(InstructionWord word) {
    long *parameters = malloc(sizeof(*parameters) * WORD_PARAMETERS);
    parameters[0] = word->opcode;
    parameters[1] = word->sourceAddressingMethod;
    parameters[2] = word->sourceRegister;
    parameters[3] = word->destinationAddressingMethod;
    parameters[4] = word->destinationRegister;
    parameters[5] = word->func;
    return parameters;
}

void instruction_word_set_destination_string(InstructionWord word, const char *string) {
    if (string == NULL)
        return;
    word->destinationOperandContentStr = malloc(sizeof(char) * (strlen(string) + 1));
    strcpy(word->destinationOperandContentStr, string);
}

void instruction_word_set_source_string(InstructionWord word, const char *string) {
    if (string == NULL)
        return;
    word->sourceOperandContentStr = malloc(sizeof(char) * (strlen(string) + 1));
    strcpy(word->sourceOperandContentStr, string);
}

const char *instruction_word_get_destination_string(InstructionWord word) {
    return word->destinationOperandContentStr;
}

const char *instruction_word_get_source_string(InstructionWord word) {
    return word->sourceOperandContentStr;
}

void instruction_word_set_operand_content(InstructionWord word, int address, int operandIndex) {
    if (operandIndex == SOURCE_INDEX)
        word->sourceOperandContent = address;
    if (operandIndex == DESTINATION_INDEX)
        word->destinationOperandContent = address;
}


void instruction_word_destroy(InstructionWord word) {
    if (word == NULL)
        return;
    if (word->destinationOperandContentStr != NULL)
        free(word->destinationOperandContentStr);
    if (word->sourceOperandContentStr != NULL)
        free(word->sourceOperandContentStr);
    free(word);
}

void instruction_word_destroy_tmp(InstructionWord word) {
    if (word == NULL)
        return;
    free(word);
}

int instruction_word_how_many_words_by_operand(int addressingMethod) {
    int numberOfWords = 0;
    switch (addressingMethod) {
        case Immediate:
        case Direct:
        case Relative:
            numberOfWords = 1;
            break;
        default:
            break;
    }
    return numberOfWords;
}

int instruction_word_get_addressing_method(InstructionWord word, int operandIndex) {
    if (operandIndex == SOURCE_INDEX)
        return word->sourceAddressingMethod;
    if (operandIndex == DESTINATION_INDEX)
        return word->destinationAddressingMethod;
    return -1;
}

void instruction_word_set_ic(InstructionWord word, int valueOfIc) {
    word->valueOfIC = valueOfIc;
}

int instruction_word_get_ic(InstructionWord word) {
    return word->valueOfIC;
}

Bool instruction_word_has_operand(Operation operation, int indexOfOperation) {
    int numberOfOperand[] = {NUMBER_OF_OPERANDS};
    int functionsNumbers[] = {FUNCTIONS_NUMBERS}, i;
    for (i = 0; i < NUMBER_OF_FUNCTIONS; ++i) {
        if (functionsNumbers[i] == operation)
            break;
    }
    if (indexOfOperation == DESTINATION_INDEX && numberOfOperand[i] > 0)
        return True;
    if (indexOfOperation == SOURCE_INDEX && numberOfOperand[i] == 2)
        return True;
    return False;
}

int instruction_word_determine_number_of_words(InstructionWord word) {
    int totalWords = 1;     /*this number includes the instruction word itself*/
    Bool hasDestination, hasSource;
    int opcode = (word->func != 0) ? ((word->opcode) * 10 + word->func) : word->opcode;
    hasSource = instruction_word_has_operand(opcode, SOURCE_INDEX);
    hasDestination = instruction_word_has_operand(opcode, DESTINATION_INDEX);
    totalWords += ((instruction_word_how_many_words_by_operand(word->destinationAddressingMethod) * hasDestination) +
                   (instruction_word_how_many_words_by_operand(word->sourceAddressingMethod) * hasSource));
    return totalWords;
}

Bool has_operand(InstructionWord word, int operandIndex) {
    int opcode = (word->func != 0) ? ((word->opcode) * 10 + word->func) : word->opcode;
    int numberOfOperand[] = {NUMBER_OF_OPERANDS};
    int functionsNumbers[] = {FUNCTIONS_NUMBERS}, i;
    for (i = 0; i < NUMBER_OF_FUNCTIONS; ++i) {
        if (functionsNumbers[i] == opcode)
            break;
    }
    if (operandIndex == DESTINATION_INDEX && numberOfOperand[i] > 0)
        return True;
    if (operandIndex == SOURCE_INDEX && numberOfOperand[i] == 2)
        return True;
    return False;
}

int instruction_word_get_number_of_words(InstructionWord word) {
    return word->numberOfWords;
}

int instruction_word_get_operand_content(InstructionWord word, int operandIndex) {
    if (operandIndex == DESTINATION_INDEX)
        return word->destinationOperandContent;
    return word->sourceOperandContent;
}

void instruction_word_set_is_extern(InstructionWord word, int operandIndex) {
    if (operandIndex == SOURCE_INDEX)
        (word->isSourceExtern = True);
    if (operandIndex == DESTINATION_INDEX)
        (word->isDestinationExtern = True);
}

Bool instruction_word_is_operand_external(InstructionWord word, int operandIndex) {
    return (operandIndex == SOURCE_INDEX) ? word->isSourceExtern : word->isDestinationExtern;
}

