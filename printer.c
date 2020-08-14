/*Created by Omri Kaisari on 12/08/2020.*/

#include "printer.h"
#include <string.h>
#include <stdlib.h>


void showbits(unsigned int x) {
    int i;
    for (i = (sizeof(char) * 23) - 1; i >= 0; i--) {
        putchar(x & (1u << i) ? '1' : '0');
    }
    printf("\n");
}

void print_operand(InstructionWord word, int operandIndex, FILE *output);

void print_current_element(int currentElement, int currentIC, FILE *output);

void print_instruction_word(InstructionWord word, FILE *output) {
    long *parameters = instruction_word_get_all_parameters(word);
    long instruction = 0, i, j, address = instruction_word_get_ic(word);
    int test;
    char toPrint[MAX_LENGTH];
    instruction += parameters[0];
    instruction <<= 18;
    instruction += parameters[1] << 16;
    instruction += parameters[2] << 13;
    instruction += parameters[3] << 11;
    instruction += parameters[4] << 8;
    instruction += parameters[5] << 3;
    instruction += 4;
    free(parameters);
    /*showbits(instruction);*/
    sprintf(toPrint, "%07d %06x\n", address, instruction);
    fputs(toPrint, output);
    print_operand(word, SOURCE_INDEX, output);
    print_operand(word, DESTINATION_INDEX, output);
    /*TODO: delete it - for testing*/
    if (strstr(toPrint, "091e14") != NULL) {
        test = 2;
        return;
    }
}

void print_operand(InstructionWord word, int operandIndex, FILE *output) {
    char toPrint[MAX_LENGTH];
    int address = instruction_word_get_ic(word);
    long operandContent = instruction_word_get_operand_content(word, operandIndex) << 3;
    AddressingMethod addressing = instruction_word_get_addressing_method(word, operandIndex);
    if (addressing == Direct)
        operandContent += 2;
    if (addressing == Relative)
        operandContent += 4;
    if (addressing == Register)
        return;
    if (addressing == Immediate)
        operandContent += 4;
    if (operandIndex == SOURCE_INDEX)
        ++address;
    else
        address += (instruction_word_get_number_of_words(word) - 1);
    if (instruction_word_is_operand_external(word, operandIndex) == True)
        operandContent -= 1;
    /*TODO: check is it is extern - for the e bit*/
    sprintf(toPrint, "%07d %06lx\n", address, (operandContent << 8) >> 8);
    fputs(toPrint, output);
}

void print_object_file(InstructionsList instructions, DataItemsList dataList, FILE *output) {
    int ICF = instruction_list_get_ic(instructions);
    int numberOfInstructionWords = ICF - BEGIN_ADDRESS;
    int numberOfDataWords = data_items_get_dc(dataList);
    int i, size = instruction_list_get_number_of_instructions(instructions);
    List *arrayOfDataElements = data_items_get_list_of_data(dataList);
    InstructionWord word;
    print_header_line(numberOfInstructionWords, numberOfDataWords, output);
    for (i = 1; i <= size; ++i) {
        word = instruction_list_get_instruction(instructions, i);
        print_instruction_word(word, output);
    }
    size = data_items_get_number_of_data_items(dataList);
    print_data(arrayOfDataElements, size, ICF, output);
}

void print_current_element(int currentElement, int currentIC, FILE *output) {
    char toPrint[MAX_LENGTH];
    sprintf(toPrint, "%07d %06x\n", currentIC, currentElement);
    fputs(toPrint, output);
}

void print_data(List *dataList, size_t sizeOfDataList, int ICF, FILE *output) {
    int i, j, sizeOfCurrentElementList, *currentElement, currentIC = ICF;
    List currentList;
    for (i = 0; i < sizeOfDataList; ++i) {
        currentList = dataList[i];
        sizeOfCurrentElementList = list_size(currentList);
        for (j = 1; j <= sizeOfCurrentElementList; ++j) {
            currentElement = list_get_data_element_at_index(currentList, j);
            print_current_element(*currentElement, currentIC, output);
            currentIC += 1;
        }
    }
}

void print_header_line(int numberOfInstructionWords, int numberOfDataWords, FILE *output) {
    char toPrint[MAX_LENGTH];
    sprintf(toPrint, "%d %d\n", numberOfInstructionWords, numberOfDataWords);
    fputs(toPrint, output);
}





