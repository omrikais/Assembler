#include <stdio.h>
#include <string.h>
#include "list.h"
#include "parser.h"
#include "instructionWord.h"
#include "code_table.h"
#include "data_table.h"

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
    char line[] = "hi: inc 1,2   ";
    Error error = parserCheckOperands(line, 2);
    char s2[] = "inc r33  , 2";
    char *operand = parserGetOperand(s2, 1);
    AddressingMethod addressingMethod = parserGetAddressingMethodOfOperand(operand);
    printf("%s\n", operand);
    char s3[] = ".string \"abcds\"";
    int *arr = parserGetStingData(s3);
    printf("%s\n", (char *) arr);
    char s4[] = "hi: .data +4,5,6,7,9,+8\n";
    List list1 = parserGetDataArray(s4);
    printList(list1, printInt);
    printf("\nThe List Size is: %d\n", listSize(list1));
    InstructionWord word = instructionWordCreate(12, 4, 1, 2, 3, 2, 3, 2);
    InstructionWord word2 = instructionWordCreate(15, 4, 1, 2, 3, 2, 3, 2);
    InstructionsList list2 = instructionListCreate();
    instructionListAddInstruction(list2, word);
    instructionListAddInstruction(list2, word2);
    InstructionWord word1 = instructionListGetInstruction(list2, 1);
    InstructionWord word3 = instructionListGetInstruction(list2, 2);
    DataItemsList dataItemsList = dataItemsListCreate();
    dataItemsListAddDataElement(dataItemsList, "abcde", strlen("abcde"));
    dataItemsListAddDataElement(dataItemsList, list1, parserGetSizeOfElement(list1, DATA));
    List list3 = (List) dataItemsListGetData(dataItemsList, 2);
    printList(list3, printInt);
    return 0;
}
