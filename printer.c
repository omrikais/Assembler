/*Created by Omri Kaisari on 12/08/2020.*/

#include "printer.h"
#include "symbol_table.h"

/**
 * @brief prints the first line in object file, which contains two numbers in a specified format
 * @param numberOfInstructionWords
 * @param numberOfDataWords
 * @param output
 */
void print_header_line(int numberOfInstructionWords, int numberOfDataWords, FILE *output);

/**
 * @brief prints a complete data array or a string to the object file as specified
 *          (a line to each char or array element).
 * @param dataList          the data element to print
 * @param sizeOfDataList    the size of the data element
 * @param icf               the final IC
 * @param output
 */
void print_data(List *dataList, size_t sizeOfDataList, int icf, FILE *output);

/**
 * @brief prints to outputObject word as specified in the assembler manual
 * @param word
 * @param outputObject
 * @param outputExtern
 */
void print_instruction_word(InstructionWord word, FILE *outputObject, FILE *outputExtern);

/**
 * @brief prints the operand word of instruction word to the suitable output file
 * @param word
 * @param operandIndex  can be DESTINATION_INDEX or SOURCE_INDEX
 * @param outputObject
 * @param outputExtern
 */
void print_operand(InstructionWord word, int operandIndex, FILE *outputObject, FILE *outputExtern);

/**
 * @brief prints word of a data array or a char of a string
 * @param currentElement
 * @param currentIc
 * @param output
 */
void print_current_element(long currentElement, int currentIc, FILE *output);

/**
 * @brief prints an entry line to the suitable output file
 * @param entry
 * @param output
 */
void print_entry(SymbolEntry entry, FILE *output);

/**
 * @brief builds an instruction word array of data to print
 * @param parameters    the parameters of instruction word as defined in the suitable macro in constants.h
 * @param instruction   the instruction word number to print
 */
void build_instruction_word(const long *parameters, long *instruction);

/**
 * @brief creates a bit mask in order to avoid unequal word length printing
 * @param mask  can be of any value, will be initialized.
 * @return      the mask to bitwise OR with the instruction word number to pront
 */
long make_mask(long mask);

void print_instruction_word(InstructionWord word, FILE *outputObject, FILE *outputExtern) {
    long *parameters = instruction_word_get_all_parameters(word);
    long instruction = 0, address = instruction_word_get_ic(word), mask = 0;
    char toPrint[MAX_LENGTH];
    Bool hasTwoOperand = has_operand(word, DESTINATION_INDEX);
    mask = make_mask(mask);
    build_instruction_word(parameters, &instruction);
    free(parameters);
    instruction = instruction & mask;
    sprintf(toPrint, "%07ld %06lx", address, instruction);
    fputs(toPrint, outputObject);
    if (hasTwoOperand == True) {
        print_operand(word, SOURCE_INDEX, outputObject, outputExtern);
        print_operand(word, DESTINATION_INDEX, outputObject, outputExtern);
    } else {
        print_operand(word, DESTINATION_INDEX, outputObject, outputExtern);
    }
}

long make_mask(long mask) {
    mask = ~mask;
    mask <<= WORD_WIDTH;
    mask = ~mask;
    return mask;
}

void build_instruction_word(const long *parameters, long *instruction) {
    (*instruction) += parameters[opcode];
    (*instruction) <<= OPCODE_SHIFT;
    (*instruction) += parameters[sourceAddressingMethod] << SOURCE_METHOD_SHIFT;
    (*instruction) += parameters[sourceRegister] << SOURCE_REGISTER_SHIFT;
    (*instruction) += parameters[destinationAddressingMethod] << DESTINATION_METHOD_SHIFT;
    (*instruction) += parameters[destinationRegister] << DESTINATION_REGISTER_SHIFT;
    (*instruction) += parameters[func] << FUNC_SHIFT;
    (*instruction) += INSTRUCTION_ARE_VALUE;
}

void print_extern_entry(InstructionWord word, int operandIndex, FILE *outputExtern, int address) {
    char toPrint[MAX_LENGTH];
    const char *label;
    if (operandIndex == DESTINATION_INDEX)
        label = instruction_word_get_destination_string(word);
    else
        label = instruction_word_get_source_string(word);
    sprintf(toPrint, "%s %07d\n", label, address);
    fputs(toPrint, outputExtern);
}

void print_operand(InstructionWord word, int operandIndex, FILE *outputObject, FILE *outputExtern) {
    char toPrint[MAX_LENGTH];
    int address = instruction_word_get_ic(word);
    long operandContent = instruction_word_get_operand_content(word, operandIndex) << 3, mask = 0;
    AddressingMethod addressing = instruction_word_get_addressing_method(word, operandIndex);
    if (addressing == Direct)
        operandContent += DIRECT_ARE;
    if (addressing == Relative)
        operandContent += RELATIVE_ARE;
    if (addressing == Register)
        return;
    if (addressing == Immediate) {
        if (has_operand(word, operandIndex) == True)
            operandContent += RELATIVE_ARE;
        else
            return;
    }
    if (operandIndex == SOURCE_INDEX)
        ++address;
    else
        address += (instruction_word_get_number_of_words(word) - 1);
    if (instruction_word_is_operand_external(word, operandIndex) == True) {
        operandContent = 1;
        print_extern_entry(word, operandIndex, outputExtern, address);
    }
    mask = make_mask(mask);
    operandContent = operandContent & mask;
    sprintf(toPrint, "\n%07d %06lx", address, operandContent);
    fputs(toPrint, outputObject);
}

void print_object_and_extern_files(InstructionsList instructions, DataItemsList dataList, FILE *outputObject,
                                   FILE *outputExtern) {
    int icf = instruction_list_get_ic(instructions);
    int numberOfInstructionWords = icf - BEGIN_ADDRESS;
    int numberOfDataWords = data_items_get_dc(dataList);
    int i, size = instruction_list_get_number_of_instructions(instructions);
    List *arrayOfDataElements = data_items_get_list_of_data(dataList);
    InstructionWord word;
    print_header_line(numberOfInstructionWords, numberOfDataWords, outputObject);
    for (i = FIRST_ELEMENT; i <= size; ++i) {
        word = instruction_list_get_instruction(instructions, i);
        print_instruction_word(word, outputObject, outputExtern);
        (i != size) ? fputc(NEW_LINE_CHAR, outputObject) : i;
    }
    size = data_items_get_number_of_data_items(dataList);
    print_data(arrayOfDataElements, size, icf, outputObject);
    free(arrayOfDataElements);
}

void print_current_element(long currentElement, int currentIc, FILE *output) {
    char toPrint[MAX_LENGTH];
    long formattedCurrentElement, mask = 0;
    mask = make_mask(mask);
    formattedCurrentElement = currentElement & mask;
    sprintf(toPrint, "%07d %06lx", currentIc, formattedCurrentElement);
    fputs(toPrint, output);
}

void print_data(List *dataList, size_t sizeOfDataList, int icf, FILE *output) {
    int i, j, sizeOfCurrentElementList, currentIc = icf;
    long *currentElement;
    List currentList;
    for (i = 0; i < sizeOfDataList; ++i) {
        fputc(NEW_LINE_CHAR, output);
        currentList = dataList[i];
        sizeOfCurrentElementList = list_size(currentList);
        for (j = FIRST_ELEMENT; j <= sizeOfCurrentElementList; ++j) {
            (j != FIRST_ELEMENT) ? fputc(NEW_LINE_CHAR, output) : j;
            currentElement = list_get_data_element_at_index(currentList, j);
            print_current_element(*currentElement, currentIc, output);
            ++currentIc;
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
    sprintf(toPrint, "%s %07d", label, address);
    fputs(toPrint, output);
}

Error print_entry_file(List symbols, FILE *output) {
    int size = list_size(symbols), i;
    SymbolEntry entry;
    Bool isExistsEntry = False;
    for (i = FIRST_ELEMENT; i <= size; ++i) {
        entry = list_get_data_element_at_index(symbols, i);
        if (symbol_get_second_property(entry) == EntryP) {
            (isExistsEntry) ? putc(NEW_LINE_CHAR, output) : i;
            isExistsEntry = True;
            print_entry(entry, output);
        }
    }
    if (isExistsEntry != True)
        return NoEntries;
    return NoErrorsFound;
}
