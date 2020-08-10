/*Created by Omri Kaisari on 09/08/2020.*/

#include <stdlib.h>
#include "builder.h"
#include <string.h>

struct builder_t {
    InstructionsList instructions;
    DataItemsList dataList;
    List symbols;
    int passNumber;
};

Error evaluate_extern(Builder builder, char *line);

Bool is_label_exists(List list, char *label);

void handle_operand(const char *line, int *addressingMethod, int *registerOfOperand, int *operandContent,
                    char **operandContentString, int operandIndex);

Builder init() {
    Builder builder = malloc(sizeof(struct builder_t));
    builder->instructions = instruction_list_create();
    builder->dataList = data_items_list_create();
    builder->symbols = list_create();
    builder->passNumber = 1;
    return builder;
}

void close(Builder builder) {
    list_destroy(builder->symbols, (DestroyFunction) symbol_entry_destroy);
    data_items_list_destroy(builder->dataList);
    instruction_list_destroy(builder->instructions);
    free(builder);
}

Error evaluate(Builder builder, char *line) {
    char *label;
    if (parser_is_empty_line(line) == True)
        return NoErrorsFound;
    if (parser_is_directive(line) == True)
        return evaluate_directive_line(builder, line);
    return NoErrorsFound;
}

Error evaluate_extern(Builder builder, char *line) {
    /*assumes to get a line with .extern label*/
    Error result;
    SymbolEntry entry;
    char *label = parser_get_extern_label(line, &result);
    if (result != NoErrorsFound)
        return result;
    if (is_label_exists(builder->symbols, label) == True) {
        free(label);
        return LabelAlreadyExists;
    }
    entry = symbol_entry_create(label, 0, DataP);
    list_insert_node_at_end(builder->symbols, entry, symbol_size_of());
    return NoErrorsFound;
}

Error evaluate_directive_line(Builder builder, char *line) {
    /*assumes that this is the first pass*/
    /*here should be some error checking functions connected to directive issues*/
    Directive directive = parser_get_directive(line);
    SymbolEntry entry;
    char *label = NULL;
    if (parser_is_new_label(line) == True) {
        label = parser_get_label(line);
        if (label == NULL)
            return IllegalLabel;
    }
    if (directive == NoDirectiveFound) {
        if (label != NULL)
            free(label);
        return DirectiveNotFound;
    }
    if (directive == String || directive == Data) {
        if (label != NULL) {
            /*needs to get the DC value here in order to put the label at the symbol table*/
            if (is_label_exists(builder->symbols, label) == True) {
                free(label);
                return LabelAlreadyExists;
            }
            entry = symbol_entry_create(label, data_items_get_dc(builder->dataList), DataP);
            list_insert_node_at_end(builder->symbols, entry, symbol_size_of());
            free(label);
        }
        add_data_item_to_table(builder, line, directive);
        return NoErrorsFound;
    }
    if (directive == Extern)
        return evaluate_extern(builder, line);
    return NoErrorsFound;
}

Bool is_label_exists(List list, char *label) {
    if (list_find_element(list, label, (Equals) symbol_entry_compare) != NULL) {
        return True;
    }
    return False;
}


void add_data_item_to_table(Builder builder, const char *line, Directive directive) {
    List data = (directive == String) ? (parser_get_string_data(line)) : parser_get_data_array(line);
    size_t size = list_size(data);
    data_items_list_add_data_element(builder->dataList, data, list_get_size_of());
    data_items_list_update_dc(builder->dataList, size);
}

/*to delete*/
List get_symbol_table(Builder builder) {
    return builder->symbols;
}

Error evaluate_code_line(Builder builder, char *line) {
    char *label;
    SymbolEntry entry;
    InstructionWord instructionWord;
    if (parser_is_new_label(line) == True) {
        label = parser_get_label(line);
        if (label == NULL)
            return IllegalLabel;
        if (is_label_exists(builder->symbols, label) == True) {
            free(label);
            return LabelAlreadyExists;
        }
        entry = symbol_entry_create(label, instruction_list_get_ic(builder->instructions), Code);
        list_insert_node_at_end(builder->symbols, entry, symbol_size_of());
        free(label);
    }

    return NoErrorsFound;
}

InstructionWord fill_instruction_word(Error *result, const char *line) { /*assumes instruction code line*/
    int opCode, functionCode, sourceAddressingMethod = 0, destinationAddressingMethod = 0,
            sourceRegister = 0, destinationRegister = 0;
    int sourceOperandContent = 0, destinationOperandContent = 0, numberOfOperands;
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
    opCode = (int) operation / 10;
    functionCode = (int) operation % 10;
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
    handle_operand(tmpLine, &sourceAddressingMethod, &sourceRegister, &sourceOperandContent, &sourceContent, 1);
    if (numberOfOperands == 1) {
        word = instruction_word_create(opCode, functionCode, sourceAddressingMethod, sourceRegister,
                                       destinationAddressingMethod, destinationRegister, sourceOperandContent,
                                       destinationOperandContent);
        instruction_word_set_source_string(word, sourceContent);
        free(sourceContent);
        *result = NoErrorsFound;
        return word;
    }
    handle_operand(tmpLine, &destinationAddressingMethod, &destinationRegister, &destinationOperandContent,
                   &destinationContent, 2);
    word = instruction_word_create(opCode, functionCode, sourceAddressingMethod, sourceRegister,
                                   destinationAddressingMethod, destinationRegister, sourceOperandContent,
                                   destinationOperandContent);
    instruction_word_set_source_string(word, sourceContent);
    instruction_word_set_destination_string(word, destinationContent);
    free(sourceContent);
    free(destinationContent);
    *result = NoErrorsFound;
    return word;
}

void handle_operand(const char *line, int *addressingMethod, int *registerOfOperand, int *operandContent,
                    char **operandContentString, int operandIndex) {
    char *operand = parser_get_operand(line, operandIndex);
    (*addressingMethod) = parser_get_addressing_method_of_operand(operand);
    if ((*addressingMethod) == Immediate) {/*an error mechanism is needed here*/
        (*operandContent) = parser_get_immediate_operand(operand);
    } else if ((*addressingMethod) == Register) {
        (*registerOfOperand) = parser_get_register_num(operand);
    } else {
        (*operandContentString) = parser_get_label_from_operand(operand);
    }
    free(operand);
}
/*need to split to two or 3 functions*/

/*
Error handle_label(Builder builder,char * line) {
    SymbolEntry entry;
    char tmpLine[MAX_LENGTH];
    char *label = NULL;
    Directive directive;
    if (parser_is_new_label(line) == True) {
        label = parser_get_label(line);
        if (label == NULL)
            return IllegalLabel;
    }
    if (is_label_exists(builder->symbols, label) == True) {
        free(label);
        return LabelAlreadyExists;
    }
    if (parser_is_directive(line) == True) {
        directive = parser_get_directive(line);
        if (directive!=NoDirectiveFound) {
            free(label);
            return DirectiveNotFound;
        }
        if ((directive==Data) || (directive == String)) {
            entry = symbol_entry_create(label, data_items_get_dc(builder->dataList), DataP);
            list_insert_node_at_end(builder->symbols, entry, symbol_size_of());
            free(label);
            return NoErrorsFound;
        }

    }

}
*/


