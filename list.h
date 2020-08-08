
/* Created by Omri Kaisari on 05/08/2020.*/


#ifndef ASSEMBLER_LIST_H
#define ASSEMBLER_LIST_H

#include <stdlib.h>
#include "constants.h"

typedef struct nodeT *ListNode;
typedef ListNode List;

typedef void (*printNodeFunction)(void *nodeData);

typedef void (*destroyFunction)(void *nodeData);

typedef int (*equals)(const void *a, const void *b);

List listCreate();

ListNode listCreateListNode(void *data, size_t dataSize);

void listDestroy(List list, destroyFunction destroy);

void listNodeDestroy(ListNode node, destroyFunction destroy);

int listSize(List list);

/* Function to add a nodeT at the beginning of Linked ListNode.
This function expects a pointer to the data to be added
and size of the data type */
void listInsertNodeAtEnd(List list, void *newData, size_t dataSize);

/* Function to print nodes in a given linked list. fpitr is used
to access the function to be used for printing current nodeT data.
Note that different data types need different specifier in printf() */
void printList(List node, void (*fptr)(void *));

/*Function to print an integer*/
void printInt(void *n);

/* Function to print a float*/
void printFloat(void *f);

void *listGetDataElementAtIndex(List list, int i);

void *listFindElement(List list, void *element, equals compereFunction);


size_t listGetSizeOf();

#endif /*ASSEMBLER_LIST_H*/
