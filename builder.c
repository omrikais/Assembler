/*Created by Omri Kaisari on 09/08/2020.*/

#include <stdlib.h>
#include "builder.h"

struct builder_t {
    InstructionsList instructions;
    DataItemsList dataList;
    List symbols;
    int passNumber;
};

Error evaluate_extern(Builder builder, char *line);

Bool is_label_exists(List list, char *label);


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

Error evaluate(char *line) {
    char *label;
    if (parser_is_new_label(line) == True) {
        label = parser_get_label(line);
        /*if (parser_is_directive(line);*/
    }
    return NoErrorsFound;
}

Error evaluate_extern(Builder builder, char *line) {
    Error result;
    SymbolEntry entry;
    char *label = parser_get_extern_label(line, &result);
    if (result != NoErrorsFound)
        return result;
    if (is_label_exists(builder->symbols, label) == True) {
        free(label);
        return LabelAlreadyExists;
    }
    entry = symbol_entry_create(label, data_items_get_dc(builder->dataList), DataP);
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
    SymbolEntry entry = symbol_entry_create(label, 0, DataP);
    if (list_find_element(list, label, (Equals) symbol_entry_compare) != NULL) {
        return True;
    }
    return False;
}


void add_data_item_to_table(Builder builder, const char *line, Directive directive) {
    List data = (directive == String) ? (parser_get_sting_data(line)) : parser_get_data_array(line);
    size_t size = list_size(data);
    data_items_list_add_data_element(builder->dataList, data, list_get_size_of());
    data_items_list_update_dc(builder->dataList, size);
}
