/*Created by Omri Kaisari on 08/08/2020.*/

#include <stdlib.h>
#include <string.h>
#include "symbol_table.h"

struct symbol_entry_type {
    char *label;
    int value;
    Proprety proprety;
};

SymbolEntry symbolEntryCreate(const char *label, int value, Proprety proprety) {
    SymbolEntry entry = malloc(sizeof(struct symbol_entry_type));
    entry->proprety = proprety;
    entry->value = value;
    entry->label = malloc(sizeof(char) * (strlen(label) + 1));
    strcpy(entry->label, label);
    return entry;
}

int symbolEntryCompare(char *label, SymbolEntry entry) {
    return strcmp(label, entry->label);
}

void symbolEntryDestroy(SymbolEntry entry) {
    free(entry->label);
    free(entry);
}

size_t symboleSizeOf() {
    return sizeof(struct symbol_entry_type);
}
 
 

