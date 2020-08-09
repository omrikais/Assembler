
/* Created by Omri Kaisari on 05/08/2020.*/

#include "stdlib.h"
#include "instruction_word.h"
#include "constants.h"

struct instruction_word_t {
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

int instruction_word_how_many_words_by_operand(int addressingMethod);


InstructionWord instruction_word_create(int opcode, int func, int sourceAddressingMethod, int sourceRegister,
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
    word->numberOfWords = instruction_word_determine_number_of_words(word);
    return word;
}

size_t instruction_word_get_size() {
    return sizeof(struct instruction_word_t);
}


void instruction_word_destroy(InstructionWord word) {
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

void instruction_word_set_ic(InstructionWord word, int valueOfIc) {
    word->valueOfIC = valueOfIc;
}

int instruction_word_determine_number_of_words(InstructionWord word) {
    int totalWords = 1;     /*this number includes the instruction word itself*/
    totalWords += instruction_word_how_many_words_by_operand(word->destinationAddressingMethod) +
                  instruction_word_how_many_words_by_operand(word->sourceAddressingMethod);
    return totalWords;
}

int instruction_word_get_number_of_words(InstructionWord word) {
    return word->numberOfWords;
}

