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
/*    char *label = parserGetLabel("      ?sholom: sadjlaslkdjsakl");
    parserIsNewLabel("hdfjksfhsdjk: sadjlaslkdjsakl");
    printf("%s\n", label);
    char string[] = "SHlom";
    char *token;
    token = strtok(string, ":");
    printf("%s", token);*/
    char str[] = "DUI:    .string hi!";
    Bool y1 = parserIsDirective(str);
    Directive x1 = parserGetDirective(str);
    char str2[] = "stop 3 2";
    Operation operation = parseGetOperation(str2);
    int y2 = parserGetNumberOfOperands(operation);
    char s1[] = "hi, my \n,name is omri";
    char *token = strtok(s1, WHITE_DELIMITERS);
    printf("%s\n", token);
    token = strtok(NULL, " \t\n,");
    printf("%s\n", token);
    char line[] = "hi: inc ,   ";
    Error error = parserCheckOperands(line, 0);
    char s2[] = "inc r33  , 2";
    char *operand = parserGetOperand(s2, 1);
    AddressingMethod addressingMethod = parserGetAddressingMethodOfOperand(operand);
    printf("%s\n", operand);
    return 0;
}
