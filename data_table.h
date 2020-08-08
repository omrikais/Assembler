
/*Created by Omri Kaisari on 08/08/2020.*/


#ifndef ASSEMBLER_DATA_TABLE_H
#define ASSEMBLER_DATA_TABLE_H

#include "list.h"

typedef struct dataListT *DataItemsList;

DataItemsList dataItemsListCreate();

void dataItemsListAddDataElement(DataItemsList list, void *dataElement, size_t sizeOfDataElement);

void dataItemsListUpdateDC(DataItemsList list, int value);

void *dataItemsListGetData(DataItemsList list, int i);

void dataItemsListDestroy(DataItemsList list);

#endif /*ASSEMBLER_DATA_TABLE_H*/
