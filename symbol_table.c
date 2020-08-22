/*Created by Omri Kaisari on 08/08/2020.*/

#include <stdlib.h>
#include <string.h>
#include "symbol_table.h"

struct symbol_entry_type {
    char *label;
    int location;
    Property property;
    Property property2;
};

SymbolEntry symbol_entry_create(const char *label, int location, Property property) {
    SymbolEntry entry = malloc(sizeof(struct symbol_entry_type));
    entry->property = property;
    entry->location = location;
    entry->label = malloc(sizeof(char) * (strlen(label) + 1));
    strcpy(entry->label, label);
    entry->property2 = NA;
    return entry;
}

int symbol_entry_compare(char *label, SymbolEntry entry) {
    return strcmp(label, entry->label);
}

void symbol_entry_destroy(SymbolEntry entry) {
    free(entry->label);
    free(entry);
}

Property symbol_get_second_property(SymbolEntry entry) {
    return entry->property2;
}

void symbol_entry_tmp_destroy(SymbolEntry entry) {
    if (entry != NULL)
        free(entry);
}

void symbol_update_second_property(SymbolEntry entry) {
    entry->property2 = EntryP;
}

int symbol_get_location(SymbolEntry entry) {
    return entry->location;
}

void symbol_update_location(SymbolEntry entry, int diff) {
    entry->location += diff;
}

Property symbol_get_property(SymbolEntry entry) {
    return entry->property;
}


size_t symbol_size_of() {
    return sizeof(struct symbol_entry_type);
}

const char *symbol_entry_get_label(SymbolEntry entry) {
    return entry->label;
}
