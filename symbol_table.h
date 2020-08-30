/**********************************************************************************************************************
 ************************************************ The  symbol table** module ******************************************
 **********************************************************************************************************************/
#ifndef ASSEMBLER_SYMBOL_TABLE_H
#define ASSEMBLER_SYMBOL_TABLE_H

#include "list.h"

/**
 * @brief enum of the possible properties of a source code line
 */
enum property {
    External,
    EntryP,
    Code,
    DataP
};

typedef enum property Property;                 /*Property type definition*/

typedef struct symbol_entry_type *SymbolEntry;  /*SymbolEntry definition*/

/**
 * @brief               creates a symbol entry object and allocated all its needed memory
 * @param label         the label of the entry
 * @param location      the location of the line where the label was defined
 * @param property      the property of the line
 * @return              a symbol entry object
 */
SymbolEntry symbol_entry_create(const char *label, int location, Property property);

/**
 * @brief           returns the location (IC) of the given entry
 * @param entry
 * @return          the location of the entry
 */
int symbol_get_location(SymbolEntry entry);

/**
 * @brief           updates the location of the entry after the first pass
 * @param entry
 * @param diff      the amount needed to be added to the original location
 */
void symbol_update_location(SymbolEntry entry, int diff);

/**
 * @brief           destroys an entry and deallocated all its memory
 * @param entry
 */
void symbol_entry_destroy(SymbolEntry entry);

/**
 * @brief           a comparison functions that returns 0 if the given entry has the given label
 * @param label
 * @param entry
 * @return          True if the entry has the label
 */
int symbol_entry_compare(char *label, SymbolEntry entry);

/**
 * @brief           updates the second property of an entry during the second pass
 * @param entry
 */
void symbol_update_second_property(SymbolEntry entry);

/**
 * @brief           deallocated only the entry but not its label field
 * @param entry
 */
void symbol_entry_tmp_destroy(SymbolEntry entry);

/**
 * @brief       returns the byte size of symbol_entry_type struct
 * @return      the byte size of symbol_entry_type struct
 */
size_t symbol_size_of();

/**
 * @brief           returns the first property of an entry
 * @param entry
 * @return          the first property of an entry
 */
Property symbol_get_property(SymbolEntry entry);

/**
 * @brief           returns the second property pf ann entry
 * @param entry
 * @return          the second property pf ann entry
 */
Property symbol_get_second_property(SymbolEntry entry);

/**
 * @brief           returns the original label of an entry
 * @param entry
 * @return          the original label of an entry
 */
const char *symbol_entry_get_label(SymbolEntry entry);

#endif /*ASSEMBLER_SYMBOL_TABLE_H*/
