/*Created by Omri Kaisari on 08/08/2020.*/

#include <stdlib.h>
#include <string.h>
#include "symbol_table.h"

struct symbol_entry_type {
    char *label;
    int value;
    Property property;
};

SymbolEntry symbol_entry_create(const char *label, int value, Property property) {
    SymbolEntry entry = malloc(sizeof(struct symbol_entry_type));
    entry->property = property;
    entry->value = value;
    entry->label = malloc(sizeof(char) * (strlen(label) + 1));
    strcpy(entry->label, label);
    return entry;
}

int symbol_entry_compare(char *label, SymbolEntry entry) {
    return strcmp(label, entry->label);
}

void symbol_entry_destroy(SymbolEntry entry) {
    free(entry->label);
    free(entry);
}

size_t symbol_size_of() {
    return sizeof(struct symbol_entry_type);
}
 
 

