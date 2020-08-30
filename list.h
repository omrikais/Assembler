/**********************************************************************************************************************
 ************************************************ The list module *****************************************************
 **********************************************************************************************************************/


#ifndef ASSEMBLER_LIST_H
#define ASSEMBLER_LIST_H

#include <stdlib.h>
#include "constants.h"

typedef struct node_t *ListNode;            /*the ListNode type definition*/

typedef ListNode List;                      /*the List type definition*/

/**
 * @brief a function pointer for printing purposes
 */
typedef void (*PrintNodeFunction)(void *nodeData);

/**
 * @brief a function pointer for destroying node purposes
 */
typedef void (*DestroyFunction)(void *nodeData);

/**
 * @brief a function pointer for comparison purposes
 */
typedef int (*Equals)(const void *a, const void *b);

/**
 * @brief       creates an empty linked list
 * @return      an empty linked list
 */
List list_create();

/**
 * @brief           created a new node
 * @param data      the data to be stored in the node
 * @param dataSize  the size of the data to be stored
 * @return          the new node with its data
 */
ListNode list_create_list_node(void *data, size_t dataSize);

/**
 * @brief           deallocates a given list and all its nodes and their data
 * @param list
 * @param destroy   a pointer to destroying function
 */
void list_destroy(List list, DestroyFunction destroy);

/**
 * @brief           deallocates a given node and all its data
 * @param node
 * @param destroy   a pointer to destroying function
 */
void list_node_destroy(ListNode node, DestroyFunction destroy);

/**
 * @brief           returns the amount of elements in the list
 * @param list
 * @return          the amount of elements in the list
 */
size_t list_size(List list);

/**
 * @brief           inserts a node at the end of the list
 * @param list
 * @param newData   the data be copied to the new node
 * @param dataSize  the size of the data in terms of bytes
 */
void list_insert_node_at_end(List list, void *newData, size_t dataSize);

/**
 * @brief           returns the data original element of the node at index i
 * @param list
 * @param i         the node index where the data element is
 * @return          the data element of the node
 */
void *list_get_data_element_at_index(List list, int i);

/**
 * @brief                       finds a data element in a list
 * @param list
 * @param element               the element to find
 * @param compereFunction       comparison function pointer
 * @return                      if the data element is in the list, a pointer of it will be returned, NULL otherwise
 */
void * list_find_element(List list, const void *element, Equals compereFunction);

/**
 * @brief       returns the byte size of the node_t struct
 * @return      the byte size of the node_t struct
 */
size_t list_get_size_of();

#endif /*ASSEMBLER_LIST_H*/
