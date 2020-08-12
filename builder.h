/*Created by Omri Kaisari on 09/08/2020.*/

#ifndef ASSEMBLER_BUILDER_H
#define ASSEMBLER_BUILDER_H

#include "code_table.h"
#include "data_table.h"
#include "list.h"
#include "instruction_word.h"
#include "constants.h"
#include "symbol_table.h"

typedef struct builder_t *Builder;

Builder init();

void close(Builder builder);

Error evaluate_directive_line(Builder builder, char *line);

void add_data_item_to_table(Builder builder, const char *line, Directive directive);

Error evaluate_code_line(Builder builder, char *line);

Error evaluate(Builder builder, char *line);

/*to delete*/
List get_symbol_table(Builder builder);

DataItemsList get_data_list(Builder builder);

InstructionWord fill_instruction_word(Error *result, const char *line);

Error evaluate_entry_directive(Builder builder, char *line);

void builder_update_data_symbols_location(Builder builder);

#endif /*ASSEMBLER_BUILDER_H*/
