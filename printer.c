/*Created by Omri Kaisari on 12/08/2020.*/

#include "printer.h"
#include "symbol_table.h"
#include <string.h>
#include <stdlib.h>


void print_operand(InstructionWord word, int operandIndex, FILE *output);

void print_current_element(long currentElement, int currentIC, FILE *output);

void print_entry(SymbolEntry entry, FILE *output);

void print_instruction_word(InstructionWord word, FILE *output) {
    long *parameters = instruction_word_get_all_parameters(word);
    long instruction = 0, i, j, address = instruction_word_get_ic(word), mask = 0;
    int test;
    char toPrint[MAX_LENGTH];
    Bool hasTwoOperand = has_operand(word, DESTINATION_INDEX);
    mask = ~mask;
    mask <<= 24;
    mask = ~mask;
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
    instruction = instruction & mask;
    sprintf(toPrint, "%07d %06x\n", address, instruction);
    fputs(toPrint, output);
    if (hasTwoOperand == True) {
        print_operand(word, SOURCE_INDEX, output);
        print_operand(word, DESTINATION_INDEX, output);
    } else
        print_operand(word, DESTINATION_INDEX, output);
    /*TODO: delete it - for testing*/
    if (strstr(toPrint, "091e14") != NULL) {
        test = 2;
        return;
    }
}

void print_operand(InstructionWord word, int operandIndex, FILE *output) {
    char toPrint[MAX_LENGTH];
    int address = instruction_word_get_ic(word), operation = 0;
    long operandContent = instruction_word_get_operand_content(word, operandIndex) << 3, mask = 0;
    AddressingMethod addressing = instruction_word_get_addressing_method(word, operandIndex);
    if (addressing == Direct)
        operandContent += 2;
    if (addressing == Relative)
        operandContent += 4;
    if (addressing == Register)
        return;
    if (addressing == Immediate) {
        if (has_operand(word, operandIndex) == True)
            operandContent += 4;
        else
            return;
    }
    if (operandIndex == SOURCE_INDEX)
        ++address;
    else
        address += (instruction_word_get_number_of_words(word) - 1);
    if (instruction_word_is_operand_external(word, operandIndex) == True)
        operandContent = 1;
    /*TODO: check is it is extern - for the e bit*/
    mask = ~mask;
    mask <<= 24;
    mask = ~mask;
    operandContent = operandContent & mask;
    sprintf(toPrint, "%07d %06lx\n", address, operandContent);
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

void print_current_element(long currentElement, int currentIC, FILE *output) {
    char toPrint[MAX_LENGTH];
    long formattedCurrentElement, mask = 0;
    mask = ~mask;
    mask <<= 24;
    mask = ~mask;
    formattedCurrentElement = currentElement & mask;
    sprintf(toPrint, "%07d %06lx\n", currentIC, formattedCurrentElement);
    fputs(toPrint, output);
}

void print_data(List *dataList, size_t sizeOfDataList, int ICF, FILE *output) {
    int i, j, sizeOfCurrentElementList, currentIC = ICF;
    long *currentElement;
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

void print_entry(SymbolEntry entry, FILE *output) {
    char toPrint[MAX_LENGTH];
    const char *label = symbol_entry_get_label(entry);
    int address = symbol_get_location(entry);
    sprintf(toPrint, "%s %07d\n", label, address);
    fputs(toPrint, output);
}

Error print_entry_file(List symbols, FILE *output) {
    int size = list_size(symbols), i;
    SymbolEntry entry;
    Bool isExistsEntry = False;
    for (i = 1; i <= size; ++i) {
        entry = list_get_data_element_at_index(symbols, i);
        if (symbol_get_second_property(entry) == EntryP) {
            isExistsEntry = True;
            print_entry(entry, output);
        }
    }
    if (isExistsEntry != True)
        return NoEntries;
    return NoErrorsFound;
}





