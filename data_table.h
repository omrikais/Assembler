/**********************************************************************************************************************
 ************************************************ The data table module ***********************************************
 **********************************************************************************************************************/

#ifndef ASSEMBLER_DATA_TABLE_H
#define ASSEMBLER_DATA_TABLE_H

#include "list.h"

typedef struct data_list_t *DataItemsList;      /*the DataItemsList type definition*/

/**
 * @brief created an empty data items list and allocates all its memory
 * @return
 */
DataItemsList data_items_list_create();

/**
 * @brief                       add a data element to a DataItemsList
 * @param list                  a DataItemsList list
 * @param dataElement           the data to add
 * @param sizeOfDataElement     the bit size of the element
 */
void data_items_list_add_data_element(DataItemsList list, void *dataElement, size_t sizeOfDataElement);

/**
 * @brief           updated the DC of the list after adding an elenebt to it
 * @param list      a DataItemsList list
 * @param delta     the amount to add to the list
 */
void data_items_list_update_dc(DataItemsList list, int delta);

/**
 * @brief           returns the original data element in index i
 * @param list      a DataItemsList list
 * @param i         the index in which the requested element
 * @return          the original data element in index i
 */
void *data_items_list_get_data(DataItemsList list, int i);

/**
 * @brief       returns the DC value of the list
 * @param list  a DataItemsList list
 * @return      the DC value of the list
 */
int data_items_get_dc(DataItemsList list);

/**
 * @brief       destroys the given list and deallocated all its memory
 * @param list  a DataItemsList list to destroy
 */
void data_items_list_destroy(DataItemsList list);

/**
 * @brief                   returns a linked list with the stored data of the DataItemsList
 * @param dataItemsList     a DataItemsList list
 * @return                  a linked list with the stored data of the DataItemsList
 */
List *data_items_get_list_of_data(DataItemsList dataItemsList);

/**
 * @brief           returns the value of the total data elements in the list
 * @param list      a DataItemsList list
 * @return          the value of the total data elements in the list
 */
int data_items_get_number_of_data_items(DataItemsList list);

#endif /*ASSEMBLER_DATA_TABLE_H*/
