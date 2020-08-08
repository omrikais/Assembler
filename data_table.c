
/*Created by Omri Kaisari on 08/08/2020.*/

#include "data_table.h"
#include <stdlib.h>

struct dataListT {
    List data;
    int DC;
    int numberOfDataItems;
};

DataItemsList dataItemsListCreate() {
    DataItemsList list = malloc(sizeof(struct dataListT));
    list->data = listCreate();
    list->DC = 0;
    list->numberOfDataItems = 0;
    return list;
}

int dataItemsListGetDC(DataItemsList list) {
    return list->DC;
}

void dataItemsListAddDataElement(DataItemsList list, void *dataElement, size_t sizeOfDataElement) {
    /*assumes that dataElement is a valid array of chars or ints */
    /*if the data element is List - it uses the original list (it is not being copied)*/
    /*the DC should be updated by the reading module*/
    listInsertNodeAtEnd(list->data, dataElement, sizeOfDataElement);
    ++(list->numberOfDataItems);
}

void dataItemsListUpdateDC(DataItemsList list, int value) {
    list->DC = value;
}

void *dataItemsListGetData(DataItemsList list, int i) {
    return listGetDataElementAtIndex(list->data, i);
}

void dataItemsListDestroy(DataItemsList list) {
    listDestroy(list->data);
    free(list);
}
