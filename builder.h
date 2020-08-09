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


#endif /*ASSEMBLER_BUILDER_H*/
