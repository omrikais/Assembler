
/*Created by Omri Kaisari on 05/08/2020.*/


/*
 * Generic linked list
*/
#include<stdio.h>
#include<stdlib.h>
#include "list.h"


/* A linked list nodeT */
struct nodeT {
    void *data;
    ListNode next;
    ListNode previous;
};

List listCreate() {
    ListNode head = (ListNode) malloc(sizeof(struct nodeT));
    head->next = NULL;
    head->previous=NULL;
    head->data = NULL;
    return head;
}

ListNode listCreateListNode(void* data, size_t dataSize) {
    ListNode node = (ListNode) malloc(sizeof(struct nodeT));
    int i;
    node->data = malloc(dataSize);
    for (i=0; i < dataSize; i++)
        *((char *)node->data + i) = *((char *)data + i);
    return node;
}



void listNodeDestroy(ListNode node, destroyFunction destroy) {
    if (node == NULL)
        return;
    if (node->data != NULL)
        destroy(node->data);
    free(node);
}


void listDestroy(List list, destroyFunction destroy) {
    ListNode current = list;
    ListNode next;
    if (list == NULL)
        return;
    while (current->next != NULL) {
        next = current->next;
        listNodeDestroy(current, destroy);
        current = next;
    }
    listNodeDestroy(current, destroy);
}

int listSize(List list) {
    int size = 0;
    ListNode current = list;
    if (list == NULL)
        return size;
    while (current->next!=NULL) {
        size++;
        current = current->next;
    }
    return size;
}

void listInsertNodeAtEnd(List list, void *newData, size_t dataSize) {
    ListNode newNode = listCreateListNode(newData, dataSize);
    ListNode temp = list;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = NULL;
    newNode->previous = temp;
}

void *listGetDataElementAtIndex(List list, int i) {
    /*the first element is in index 1
     * returns the original data element*/
    int j = 0;
    ListNode current = list;
    while (j < i) {
        current = current->next;
        j++;
    }
    return current->data;
}

void printList(List node, printNodeFunction function) {
    while (node != NULL) {
        if (node->data != NULL)
            (*function)(node->data);
        node = node->next;
    }
}

size_t listGetSizeOf() {
    return sizeof(struct nodeT);
}

void *listFindElement(List list, void *element, equals compereFunction) {
    ListNode current = list;
    while (current != NULL) {
        if (current->data != NULL) {
            if (compereFunction(element, current->data) == 0)
                return current->data;
        }
        current = current->next;
    }
    return NULL;
}

