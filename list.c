
/*Created by Omri Kaisari on 05/08/2020.*/

#include<stdlib.h>
#include "list.h"


struct node_t {
    void *data;
    ListNode next;
};

List list_create() {
    ListNode head = (ListNode) malloc(sizeof(struct node_t));
    head->next = NULL;
    head->data = NULL;
    return head;
}

ListNode list_create_list_node(void *data, size_t dataSize) {
    ListNode node = (ListNode) malloc(sizeof(struct node_t));
    int i;
    node->data = malloc(dataSize);
    for (i = 0; i < dataSize; i++)
        *((char *) node->data + i) = *((char *) data + i);
    return node;
}


void list_node_destroy(ListNode node, DestroyFunction destroy) {
    if (node == NULL)
        return;
    if (node->data != NULL) {
        if (destroy != NULL)
            destroy(node->data);
        else
            free(node->data);
    }
    free(node);
}


void list_destroy(List list, DestroyFunction destroy) {
    ListNode current = list;
    ListNode next;
    if (list == NULL)
        return;
    while (current->next != NULL) {
        next = current->next;
        list_node_destroy(current, destroy);
        current = next;
    }
    list_node_destroy(current, destroy);
}

int list_size(List list) {
    int size = 0;
    ListNode current = list;
    if (list == NULL)
        return size;
    while (current->next != NULL) {
        size++;
        current = current->next;
    }
    return size;
}

void list_insert_node_at_end(List list, void *newData, size_t dataSize) {
    ListNode newNode = list_create_list_node(newData, dataSize);
    ListNode temp = list;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = NULL;
}

void *list_get_data_element_at_index(List list, int i) {
    /*the first element is in index 1
     * returns the original Data element*/
    int j = 0;
    ListNode current = list;
    while (j < i) {
        current = current->next;
        j++;
    }
    return current->data;
}

void print_list(List node, PrintNodeFunction printFunction) {
    while (node != NULL) {
        if (node->data != NULL)
            (*printFunction)(node->data);
        node = node->next;
    }
}

size_t list_get_size_of() {
    return sizeof(struct node_t);
}

void * list_find_element(List list, const void *element, Equals compereFunction) {
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


