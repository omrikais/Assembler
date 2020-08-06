#include <stdio.h>
#include "list.h"
#include "parser.h"
#include <string.h>

/*Created by Omri Kaisari on 05/08/2020.*/

void printInt(void *n) {
    printf(" %d", *((int *) n));
}

void printFloat(void *f) {
    printf(" %f", *(float *) f);
}


int main() {
    List list = listCreate();
    int x = 1, y = 2, z = 3, u = 4;
    listInsertNodeAtEnd(list, &x, sizeof(x));
    listInsertNodeAtEnd(list, &y, sizeof(x));
    listInsertNodeAtEnd(list, &z, sizeof(x));
    listInsertNodeAtEnd(list, &u, sizeof(x));
    printList(list, printInt);
    printf("\nThe List Size is: %d\n", listSize(list));
    listDestroy(list);
    char *label = parserGetLabel("      ?sholom: sadjlaslkdjsakl");
    parserIsNewLabel("hdfjksfhsdjk: sadjlaslkdjsakl");
    printf("%s\n", label);
    char string[] = "SHlom";
    char *token;
    token = strtok(string, ":");
    printf("%s", token);
    return 0;
}
