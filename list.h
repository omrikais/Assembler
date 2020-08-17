
/* Created by Omri Kaisari on 05/08/2020.*/


#ifndef ASSEMBLER_LIST_H
#define ASSEMBLER_LIST_H

#include <stdlib.h>
#include "constants.h"

typedef struct node_t *ListNode;
typedef ListNode List;

typedef void (*PrintNodeFunction)(void *nodeData);

typedef void (*DestroyFunction)(void *nodeData);

typedef int (*Equals)(const void *a, const void *b);

List list_create();

ListNode list_create_list_node(void *data, size_t dataSize);

void list_destroy(List list, DestroyFunction destroy);

void list_node_destroy(ListNode node, DestroyFunction destroy);

int list_size(List list);

/* Function to add a node_t at the beginning of Linked ListNode.
This function expects a pointer to the Data to be added
and size of the Data type */
void list_insert_node_at_end(List list, void *newData, size_t dataSize);

/* Function to print nodes in a given linked list. printFunction is used
to access the function to be used for printing current node_t Data.
Note that different Data types need different specifier in printf() */
void print_list(List node, PrintNodeFunction printFunction);

/*Function to print an integer*/
void print_int(void *n);

void *list_get_data_element_at_index(List list, int i);

void * list_find_element(List list, const void *element, Equals compereFunction);


size_t list_get_size_of();

#endif /*ASSEMBLER_LIST_H*/
