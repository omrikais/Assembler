/*Created by Omri Kaisari on 08/08/2020.*/

#ifndef ASSEMBLER_SYMBOL_TABLE_H
#define ASSEMBLER_SYMBOL_TABLE_H

#include "list.h"

enum property {
    External,
    EntryP,
    Code,
    DataP
};

typedef enum property Property;

typedef struct symbol_entry_type *SymbolEntry;

SymbolEntry symbol_entry_create(const char *label, int location, Property property);

int symbol_get_location(SymbolEntry entry);

void symbol_update_location(SymbolEntry entry, int diff);

void symbol_entry_destroy(SymbolEntry entry);

int symbol_entry_compare(char *label, SymbolEntry entry);

void symbol_update_second_property(SymbolEntry entry);

void symbol_entry_tmp_destroy(SymbolEntry entry);

size_t symbol_size_of();

Property symbol_get_property(SymbolEntry entry);

Property symbol_get_second_property(SymbolEntry entry);

const char *symbol_entry_get_label(SymbolEntry entry);

#endif /*ASSEMBLER_SYMBOL_TABLE_H*/
