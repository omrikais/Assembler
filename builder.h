/*Created by Omri Kaisari on 09/08/2020.*/

#ifndef ASSEMBLER_BUILDER_H
#define ASSEMBLER_BUILDER_H

#include "code_table.h"
#include "data_table.h"
#include "list.h"
#include "instruction_word.h"
#include "constants.h"
#include "symbol_table.h"
#include "errors.h"

typedef struct builder_t *Builder;

Builder init();

void close(Builder builder);

Error evaluate_directive_line(Builder builder, char *line);

void add_data_item_to_table(Builder builder, const char *line, Directive directive);

Error evaluate_code_line(Builder builder, char *line);

Error evaluate(Builder builder, char *line);

InstructionWord fill_instruction_word(Error *result, const char *line);

Error evaluate_entry_directive(Builder builder, const char *line);

void builder_update_data_symbols_location(Builder builder);

/*void builder_update_instructions(Builder builder, int lineNumber, char *fileName);*/

InstructionsList builder_get_instructions_list(Builder builder);

void builder_update_instruction(InstructionWord word, Builder builder, Error *error);

DataItemsList builder_get_data_items_list(Builder builder);

List builder_get_symbols_list(Builder builder);

#endif /*ASSEMBLER_BUILDER_H*/
