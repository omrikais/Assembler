
/*Created by Omri Kaisari on 08/08/2020.*/

#include "data_table.h"
#include <stdlib.h>

struct data_list_t {
    List data;
    int DC;
    int numberOfDataItems;
};

void data_item_list_destroy(List list);

DataItemsList data_items_list_create() {
    DataItemsList list = malloc(sizeof(struct data_list_t));
    list->data = list_create();
    list->DC = 0;
    list->numberOfDataItems = 0;
    return list;
}

int data_items_list_get_dc(DataItemsList list) {
    return list->DC;
}

void data_items_list_add_data_element(DataItemsList list, void *dataElement, size_t sizeOfDataElement) {
    /*assumes that dataElement is a valid array of chars or ints */
    /*if the Data element is List - it uses the original list (it is not being copied)*/
    /*the DC should be updated by the reading module*/
    list_insert_node_at_end(list->data, dataElement, sizeOfDataElement);
    (list->numberOfDataItems)++;
}

void data_items_list_update_dc(DataItemsList list, int value) {
    (list->DC) += value;
}

void *data_items_list_get_data(DataItemsList list, int i) {
    List result = list_get_data_element_at_index(list->data, i);
    return result;
}

void data_items_list_destroy(DataItemsList list) {
    list_destroy(list->data, (DestroyFunction) data_item_list_destroy);
    free(list);
}

int data_items_get_dc(DataItemsList list) {
    return list->DC;
}

void data_item_list_destroy(List list) {
    list_destroy(list, NULL);
}
