
/*Created by Omri Kaisari on 05/08/2020.*/


/*
 * Generic linked list
*/
#include<stdio.h>
#include<stdlib.h>
#include "List.h"

/* A linked list node_t */
struct node_t {
    /* Any data type can be stored in this node_t*/
    void *data;
    List next;
};



void push(List *headRef, void *newData, size_t dataSize) {
    /* Allocate memory for node_t*/
    List newNode = (List) malloc(sizeof(struct node_t));
    int i;
    
    newNode->data = malloc(dataSize);
    newNode->next = (*headRef);
    
    /* Copy contents of newData to newly allocated memory.
     Assumption: char takes 1 byte.*/
    for (i=0; i < dataSize; i++)
        *((char *)newNode->data + i) = *((char *)newData + i);
    
    /*Change head pointer as new node_t is added at the beginning*/
    (*headRef) = newNode;
}

void printList(struct node_t *node, void (*fptr)(void *)) {
    while (node != NULL)
    {
        (*fptr)(node->data);
        node = node->next;
    }
}

void printInt(void *n) {
    printf(" %d", *(int *)n);
}

void printFloat(void *f) {
    printf(" %f", *(float *)f);
}


#include "List.h"
