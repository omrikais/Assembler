
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



void listNodeDestroy(ListNode node) {
    if (node == NULL)
        return;
    if (node->data!=NULL)
        free(node->data);
    free(node);
}



void listDestroy(List list) {
    ListNode current = list;
    ListNode next;
    if (list == NULL)
        return;
    while (current->next!=NULL) {
        next = current->next;
        listNodeDestroy(current);
        current = next;
    }
    listNodeDestroy(current);
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
    ListNode newNode = listCreateListNode(newData,dataSize);
    ListNode temp = list;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next=NULL;
    newNode->previous=temp;
}

void printList(List node, printNodeFunction function) {
    while (node != NULL)
    {
        if (node->data != NULL)
            (*function)(node->data);
        node = node->next;
    }
}

