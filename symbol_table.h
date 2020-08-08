
/*Created by Omri Kaisari on 08/08/2020.*/

#ifndef ASSEMBLER_SYMBOL_TABLE_H
#define ASSEMBLER_SYMBOL_TABLE_H

#include "list.h"

enum proprety {
    external,
    enrty,
    code,
    data
};

typedef enum proprety Proprety;

typedef struct symbol_entry_type *SymbolEntry;

SymbolEntry symbolEntryCreate(const char *label, int value, Proprety proprety);

void symbolEntryDestroy(SymbolEntry entry);

int symbolEntryCompare(char *label, SymbolEntry entry);

size_t symboleSizeOf();

#endif /*ASSEMBLER_SYMBOL_TABLE_H*/
