/*Created by Omri Kaisari on 09/08/2020.*/

#include <stdlib.h>
#include "builder.h"

struct builder_t {
    InstructionsList instructions;
    DataItemsList dataList;
    List symbols;
};

Builder init() {
    Builder builder = malloc(sizeof(struct builder_t));
    builder->instructions = instruction_list_create();
    builder->dataList = data_items_list_create();
    builder->symbols = list_create();
    return builder;
}

void close(Builder builder) {
    list_destroy(builder->symbols, (DestroyFunction) symbol_entry_destroy);
    data_items_list_destroy(builder->dataList);
}

