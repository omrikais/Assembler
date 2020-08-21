/*Created by Omri Kaisari on 09/08/2020.*/

#include <stdlib.h>
#include <string.h>
#include "builder.h"

struct builder_t {
    InstructionsList instructions;
    DataItemsList dataList;
    List symbols;
};

Error evaluate_extern(Builder builder, char *line);

Bool is_label_exists(List list, const char *label);

void handle_operand(const char *line, int *addressingMethod, int *registerOfOperand, long *operandContent,
                    char **operandContentString, int operandIndex, Error *error);

Error check_operands_addressing_method(InstructionWord word, int numberOfOperands);

Error
handle_directive(Builder builder, const char *line, Directive directive, const char *label);

Error update_operand(InstructionWord word, Builder builder, int operandIndex);

Error change_operand(Builder builder, InstructionWord word, int operandIndex, AddressingMethod method);

Builder init() {
    Builder builder = malloc(sizeof(struct builder_t));
    builder->instructions = instruction_list_create();
    builder->dataList = data_items_list_create();
    builder->symbols = list_create();
    return builder;
}

void close(Builder builder) {
    if (builder == NULL)
        return;
    list_destroy(builder->symbols, (DestroyFunction) symbol_entry_destroy);
    data_items_list_destroy(builder->dataList);
    instruction_list_destroy(builder->instructions);
    free(builder);
}

Error evaluate(Builder builder, char *line) {
    if (parser_is_empty_line(line) == True)
        return NoErrorsFound;
    if (parser_is_directive(line) == True)
        return evaluate_directive_line(builder, line);
    return evaluate_code_line(builder, line);
}

Error evaluate_extern(Builder builder, char *line) {
    /*assumes to get a line with .extern label*/
    Error result;
    SymbolEntry entry;
    char *label = parser_get_extern_label(line, &result);
    if (result != NoErrorsFound) {
        free(label);
        return result;
    }
    if (is_label_exists(builder->symbols, label) == True) {
        free(label);
        return TheExternOperandIsAlreadyDefined;
    }
    entry = symbol_entry_create(label, 0, External);
    list_insert_node_at_end(builder->symbols, entry, symbol_size_of());
    symbol_entry_tmp_destroy(entry);
    free(label);
    return NoErrorsFound;
}

Error update_operand(InstructionWord word, Builder builder, int operandIndex) {
    Error error = NoErrorsFound;
    AddressingMethod method = instruction_word_get_addressing_method(word, operandIndex);
    if ((method == Direct || method == Relative) && has_operand(word, operandIndex) == True)
        error = change_operand(builder, word, operandIndex, method);
    return error;
}

Error evaluate_directive_line(Builder builder, char *line) {
    /*assumes that this is the first pass*/
    Directive directive = parser_get_directive(line);
    Error error;
    char *label = NULL;
    if (parser_is_new_label(line) == True) {
        label = parser_get_label(line, &error);
        if (label == NULL)
            return error;
    }
    if (directive == NoDirectiveFound) {
        if (label != NULL)
            free(label);
        return DirectiveNotFound;
    }
    if (directive == String || directive == Data) {
        error = handle_directive(builder, line, directive, label);
        if (label != NULL)
            free(label);
        return error;
    }
    if (directive == Extern)
        return evaluate_extern(builder, line);
    return NoErrorsFound;
}

Error handle_directive(Builder builder, const char *line, Directive directive, const char *label) {
    Error error = (directive == String) ? parser_check_string_directive_form(line)
                                        : parser_check_data_directive_form(line);
    SymbolEntry entry;
    if (error != NoErrorsFound)
        return error;
    if (label != NULL) {
        if (is_label_exists(builder->symbols, label) == True)
            return LabelAlreadyExists;
        entry = symbol_entry_create(label, data_items_get_dc(builder->dataList), DataP);
        list_insert_node_at_end(builder->symbols, entry, symbol_size_of());
        symbol_entry_tmp_destroy(entry);
    }
    add_data_item_to_table(builder, line, directive);
    return NoErrorsFound;
}


Error evaluate_entry_directive(Builder builder, const char *line) {
    Error result;
    SymbolEntry entry = NULL;
    List symbols = builder->symbols;
    char *label = parser_get_extern_label(line, &result);
    if (result != NoErrorsFound) {
        free(label);
        return result;
    }
    if (is_label_exists(builder->symbols, label) == False) {
        free(label);
        return EntryLabelNotExists;
    }
    entry = list_find_element(symbols, label, (Equals) symbol_entry_compare);
    symbol_update_second_property(entry);
    free(label);
    return NoErrorsFound;
}

void builder_update_instruction(InstructionWord word, Builder builder, Error *error) {
    *error = NoErrorsFound;
    if ((*error = update_operand(word, builder, SOURCE_INDEX)) != NoErrorsFound)
        return;
    if ((*error = update_operand(word, builder, DESTINATION_INDEX)) != NoErrorsFound)
        return;
}

Error change_operand(Builder builder, InstructionWord word, int operandIndex, AddressingMethod method) {
    const char *label = NULL;
    SymbolEntry entry;
    int labelLocation, wordLocation = 0;
    Property property;
    Bool isOneOperand = !(has_operand(word, DESTINATION_INDEX));
    if (operandIndex == DESTINATION_INDEX)
        label = instruction_word_get_destination_string(word);
    if (isOneOperand == False && operandIndex == SOURCE_INDEX)
        label = instruction_word_get_source_string(word);
    entry = list_find_element(builder->symbols, label, (Equals) symbol_entry_compare);
    if (entry == NULL)
        return EntryLabelNotExists;
    labelLocation = symbol_get_location(entry);
    if (method == Direct) {
        property = symbol_get_property(entry);
        if (property == External) {
            labelLocation = 0;
            instruction_word_set_is_extern(word, operandIndex);
        }
    }
    if (method == Relative)
        wordLocation = instruction_word_get_ic(word);
    instruction_word_set_operand_content(word, labelLocation - wordLocation, operandIndex);
    return NoErrorsFound;
}

Bool is_label_exists(List list, const char *label) {
    if (list_find_element(list, label, (Equals) symbol_entry_compare) != NULL)
        return True;
    return False;
}

void add_data_item_to_table(Builder builder, const char *line, Directive directive) {
    List data = (directive == String) ? (parser_get_string_data(line)) : parser_get_data_array(line);
    size_t size = list_size(data);
    data_items_list_add_data_element(builder->dataList, data, list_get_size_of());
    data_items_list_update_dc(builder->dataList, size);
    list_node_destroy(data, NULL);
}

void builder_update_data_symbols_location(Builder builder) {
    int i;
    List symbols = builder->symbols;
    SymbolEntry entry;
    int diff = instruction_list_get_ic(builder->instructions);
    for (i = 1; i <= list_size(symbols); ++i) {
        entry = list_get_data_element_at_index(symbols, i);
        if (symbol_get_property(entry) == DataP)
            symbol_update_location(entry, diff);
    }
}

Error evaluate_code_line(Builder builder, char *line) {
    char *label;
    SymbolEntry entry;
    InstructionWord word = NULL;
    Error result;
    int ic = instruction_list_get_ic(builder->instructions);
    if (parser_is_new_label(line) == True) {
        label = parser_get_label(line, &result);
        if (label == NULL)
            return result;
        if (is_label_exists(builder->symbols, label) == True) {
            free(label);
            return LabelAlreadyExists;
        }
        entry = symbol_entry_create(label, instruction_list_get_ic(builder->instructions), Code);
        list_insert_node_at_end(builder->symbols, entry, symbol_size_of());
        free(label);
        symbol_entry_tmp_destroy(entry);
    }
    word = fill_instruction_word(&result, line);
    if (word == NULL)
        return result;
    instruction_word_set_ic(word, ic);
    instruction_list_add_instruction(builder->instructions, word);
    instruction_word_destroy_tmp(word);/*check this*/
    return result;
}

InstructionWord fill_instruction_word(Error *result, const char *line) { /*assumes instruction code line*/
    int opCode, functionCode, sourceAddressingMethod = 0, destinationAddressingMethod = 0,
            sourceRegister = 0, destinationRegister = 0, numberOfOperands;
    long sourceOperandContent = 0, destinationOperandContent = 0;
    char tmpLine[MAX_LENGTH];
    char *sourceContent = NULL, *destinationContent = NULL;
    Operation operation;
    InstructionWord word = NULL;
    strcpy(tmpLine, line);
    operation = parse_get_operation(tmpLine);
    if (operation == OperationNotFound) {
        *result = CommandNotFound;
        return NULL;
    }
    opCode = ((int) operation > 19) ? (((int) operation) / 10) : ((int) operation);
    functionCode = ((int) operation > 19) ? (((int) operation) % 10) : 0;
    numberOfOperands = parser_get_number_of_operands(operation);
    *result = parser_check_operands(tmpLine, numberOfOperands);
    if (*result != NoErrorsFound) {
        instruction_word_destroy(word);
        return NULL;
    }
    if (numberOfOperands == 0) {
        word = instruction_word_create(opCode, functionCode, 0, 0, 0, 0, 0, 0);
        *result = NoErrorsFound;
        return word;
    }
    if (numberOfOperands == 1) {
        handle_operand(tmpLine, &destinationAddressingMethod, &destinationRegister, &destinationOperandContent,
                       &destinationContent, 1, result);
        if (*result != NoErrorsFound)
            return NULL;
        word = instruction_word_create(opCode, functionCode, sourceAddressingMethod, sourceRegister,
                                       destinationAddressingMethod, destinationRegister, sourceOperandContent,
                                       destinationOperandContent);
        instruction_word_set_destination_string(word, destinationContent);
        free(destinationContent);
        *result = check_operands_addressing_method(word, numberOfOperands);
        return word;
    }
    handle_operand(tmpLine, &sourceAddressingMethod, &sourceRegister, &sourceOperandContent,
                   &sourceContent, 1, result);
    if (*result != NoErrorsFound)
        return NULL;
    handle_operand(tmpLine, &destinationAddressingMethod, &destinationRegister, &destinationOperandContent,
                   &destinationContent, 2, result);
    if (*result != NoErrorsFound)
        return NULL;
    word = instruction_word_create(opCode, functionCode, sourceAddressingMethod, sourceRegister,
                                   destinationAddressingMethod, destinationRegister, sourceOperandContent,
                                   destinationOperandContent);
    instruction_word_set_source_string(word, sourceContent);
    instruction_word_set_destination_string(word, destinationContent);
    free(sourceContent);
    free(destinationContent);
    *result = check_operands_addressing_method(word, numberOfOperands);
    return word;
}

Error check_operands_addressing_method(InstructionWord word, int numberOfOperands) {
    int opcode = instruction_word_get_opcode(word);
    AddressingMethod method1 = instruction_word_get_addressing_method(word, DESTINATION_INDEX);
    AddressingMethod method2;
    if (numberOfOperands == 1) {
        if (method1 == 0 && opcode != PRN)
            return IncompatibleAddressing;
        if (method1 == 3 && opcode == 9)
            return IncompatibleAddressing;
        if (method1 == 2 && opcode != 9)
            return IncompatibleAddressing;
    }
    if (numberOfOperands == 2) {
        method2 = instruction_word_get_addressing_method(word, SOURCE_INDEX);
        if ((method2 == 0 || method2 == 3) && opcode == 4)
            return IncompatibleAddressing;
        if (method2 == 2 || method1 == 2)
            return IncompatibleAddressing;
        if (method1 == 0 && opcode != 1)
            return IncompatibleAddressing;
    }
    return NoErrorsFound;

}

void handle_operand(const char *line, int *addressingMethod, int *registerOfOperand, long *operandContent,
                    char **operandContentString, int operandIndex, Error *error) {
    char *operand = parser_get_operand(line, operandIndex);
    (*addressingMethod) = parser_get_addressing_method_of_operand(operand);
    if ((*addressingMethod) == Immediate) {/*an error mechanism is needed here*/
        (*operandContent) = parser_get_immediate_operand(operand);
    } else if ((*addressingMethod) == Register) {
        (*registerOfOperand) = parser_get_register_num(operand);
    } else if ((*addressingMethod) == NA) {
        *error = InvalidAddressingMethod;
    } else
        (*operandContentString) = parser_get_label_from_operand(operand);
    free(operand);
}

InstructionsList builder_get_instructions_list(Builder builder) {
    return builder->instructions;
}

DataItemsList builder_get_data_items_list(Builder builder) {
    return builder->dataList;
}

List builder_get_symbols_list(Builder builder) {
    return builder->symbols;
}
