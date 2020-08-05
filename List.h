
/* Created by Omri Kaisari on 05/08/2020.*/


#ifndef ASSEMBLER_LIST_H
#define ASSEMBLER_LIST_H

typedef struct node_t* List;

/* Function to add a node_t at the beginning of Linked List.
This function expects a pointer to the data to be added
and size of the data type */
void push(List *headRef, void *newData, size_t dataSize);

/* Function to print nodes in a given linked list. fpitr is used
to access the function to be used for printing current node_t data.
Note that different data types need different specifier in printf() */
void printList(List node, void (*fptr)(void *));

/*Function to print an integer*/
void printInt(void *n);

/* Function to print a float*/
void printFloat(void *f);

#endif /*ASSEMBLER_LIST_H*/
