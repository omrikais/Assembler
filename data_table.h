
/*Created by Omri Kaisari on 08/08/2020.*/


#ifndef ASSEMBLER_DATA_TABLE_H
#define ASSEMBLER_DATA_TABLE_H

#include "list.h"

typedef struct data_list_t *DataItemsList;

DataItemsList data_items_list_create();

void data_items_list_add_data_element(DataItemsList list, void *dataElement, size_t sizeOfDataElement);

void data_items_list_update_dc(DataItemsList list, int value);

void *data_items_list_get_data(DataItemsList list, int i);

int data_items_get_dc(DataItemsList list);

void data_items_list_destroy(DataItemsList list);

#endif /*ASSEMBLER_DATA_TABLE_H*/
