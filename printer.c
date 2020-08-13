/*Created by Omri Kaisari on 12/08/2020.*/

#include "printer.h"
#include <string.h>
#include <stdlib.h>
#include "constants.h"
#include "code_table.h"

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
    int *parameters = instruction_word_get_all_parameters(word);
    int instruction = 0, i, j, address = instruction_word_get_ic(word);
    char toPrint[MAX_LENGTH];
    instruction += parameters[0];
    instruction <<= 17;
    instruction += parameters[1] << 15;
    instruction += parameters[2] << 12;
    instruction += parameters[3] << 10;
    instruction += parameters[4] << 7;
    instruction += parameters[5] << 2;
    instruction += 4;
    free(parameters);
    /*showbits(instruction);*/
    sprintf(toPrint, "%07d %x\n", address, instruction);
    fputs(toPrint, output);
    print_operand(word, SOURCE_INDEX, output);
    print_operand(word, DESTINATION_INDEX, output);
}

void print_operand(InstructionWord word, int operandIndex, FILE *output) {
    char toPrint[MAX_LENGTH];
    int address = instruction_word_get_ic(word);
    int operandContent = instruction_word_get_operand_content(word, operandIndex) << 3;
    AddressingMethod addressing = instruction_word_get_addressing_method(word, operandIndex);
    if (addressing == Direct)
        operandContent += 2;
    if (addressing == Relative)
        operandContent += 4;
    if (addressing == Immediate || addressing == Register)
        return;
    if (operandIndex == SOURCE_INDEX)
        ++address;
    else
        address += 2;
    sprintf(toPrint, "%07d %x\n", address, operandContent);
    fputs(toPrint, output);
}

void print_object_file()

        void print_current_element(int currentElement, int currentIC, FILE *output) {
    char toPrint[MAX_LENGTH];
    sprintf(toPrint, "%07d %x\n", currentIC, currentElement);
    fputs(toPrint, output);
}

void print_data(List *dataList, size_t sizeOfDataList, int ICF, FILE *output) {
    int i, j, sizeOfCurrentElementList, *currentElement, currentIC = ICF;
    List currentList;
    for (i = 0; i < sizeOfDataList; ++i) {
        currentList = dataList[i];
        sizeOfCurrentElementList = list_size(currentList);
        for (j = 0; j < sizeOfCurrentElementList; ++j) {
            currentElement = list_get_data_element_at_index(currentList, j);
            print_current_element(*currentElement, currentIC, output);
            ++currentIC;

        }
    }
}

void print_header_line(int numberOfInstructionWords, int numberOfDataWords, FILE *output) {
    char toPrint[MAX_LENGTH];
    sprintf(toPrint, "%10d %d\n", numberOfInstructionWords, numberOfDataWords);
    fputs(toPrint, output);
}





