
/*Created by Omri Kaisari on 08/08/2020.*/

#include "data_table.h"

/**
 * @brief the DataItemsList struct
 */
struct data_list_t {
    List data;              /*a linked list stored all the data elements*/
    int dc;                 /*the current DC value after adding the last element*/
    int numberOfDataItems;  /*the total number of data elements*/
};

/************************************************** Internal functions ************************************************/

/**
 * @brief       a default destroy function for destroying list of primitive types
 * @param list
 */
void data_item_list_destroy(List list);

/************************************************** Functions implementations *****************************************/

DataItemsList data_items_list_create() {
    DataItemsList list = malloc(sizeof(struct data_list_t));
    list->data = list_create();
    list->dc = 0;
    list->numberOfDataItems = 0;
    return list;
}

List *data_items_get_list_of_data(DataItemsList dataItemsList) {
    List data = dataItemsList->data;
    int listSize = dataItemsList->numberOfDataItems;
    int i;
    List *listArray;
    listArray = malloc(sizeof(List) * (listSize));
    for (i = FIRST_ELEMENT; i <= listSize; ++i) {
        listArray[i - 1] = list_get_data_element_at_index(data, i);
    }
    return listArray;

}

void data_items_list_add_data_element(DataItemsList list, void *dataElement, size_t sizeOfDataElement) {
    /*assumes that dataElement is a valid array of chars or ints */
    /*if the Data element is List - it uses the original list (it is not being copied)*/
    /*the DC should be updated by the reading module*/
    list_insert_node_at_end(list->data, dataElement, sizeOfDataElement);
    (list->numberOfDataItems)++;
}

void data_items_list_update_dc(DataItemsList list, int delta) {
    (list->dc) += delta;
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
    return list->dc;
}

void data_item_list_destroy(List list) {
    list_destroy(list, NULL);
}

int data_items_get_number_of_data_items(DataItemsList list) {
    return list->numberOfDataItems;
}
