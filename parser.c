
/*Created by Omri Kaisari on 06/08/2020.*/

#include "parser.h"
#include <string.h>
#include <stdlib.h>

char *trimLabel(char *line);

Bool isAlphabetic(char c);

Operation findOperation(char *word);

int findIndexOfElement(const int *array, Operation operation);


Bool parserIsNewLabel(char *line) {
    if (strchr(line, LABAL_DELIM_CHAR) == NULL)
        return FALSE;
    return TRUE;
}

Bool parserIsDirective(char *line) {
    if (strchr(line, DIRECTIVE_CHAR) == NULL)
        return FALSE;
    return TRUE;
}


char *parserGetLabel(char *line) {
    char *endLocation = strchr(line, LABAL_DELIM_CHAR);
    char *label = malloc(sizeof(*label) * (endLocation - line));
    char *originalPtr = label;
    char *token;
    memcpy(label, line, endLocation - line);
    token = strtok(label, WHITH_DELIMITERS);    /*if the label doesn't begin with alphabetic char, null returned*/
    label = token;
    if (isAlphabetic(label[0]))
        return label;
    free(originalPtr);
    return NULL;
}

Bool isAlphabetic(char c) {
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        return TRUE;
    return FALSE;
}

char *trimLabel(char *line) {  /*this function assumes that there is label in line*/
    char tmpStr[MAX_LENGTH];
    char *token;
    char *trimmed;
    strcpy(tmpStr, line);
    token = strtok(tmpStr, LABEL_DELIM);
    if (token == NULL)
        return NULL;        /*there is nothing after the label*/
    token = strtok(NULL, WHITH_DELIMITERS);  /*now the first word is the operation*/
    trimmed = malloc(sizeof(trimmed) * (MAX_LENGTH));
    strcpy(trimmed, token);
    return trimmed;
}

Operation findOperation(char *word) {
    char *functions[] = {FUNCTIONS};
    int functionsNumbers[] = {FUNCTIONS_NUMBERS};
    int i;
    for (i = 0; i < NUMBER_OF_FUNCTIONS; ++i) {
        if (strcmp(word, functions[i]) == 0) {
            Operation operation = functionsNumbers[i];
            return operation;
        }
    }
    return OPRATION_NOT_FOUND;
    
    
}

Operation parseGetOperation(char *line) { /*trim the line, and then only get the operation*/
    char *operationWord = NULL;
    char *startPtr;
    Operation operation;
    if (parserIsNewLabel(line) == TRUE)
        operationWord = trimLabel(line);
    else {
        operationWord = malloc(sizeof(*operationWord) * MAX_LENGTH);
        strcpy(operationWord, line);
    }
    startPtr = operationWord;
    if (operationWord == NULL)
        return OPRATION_NOT_FOUND;
    operationWord = strtok(operationWord, WHITH_DELIMITERS);
    operationWord = strtok(operationWord, NEW_LINE_DELIM);
    operation = findOperation(operationWord);
    free(startPtr);
    return operation;
}

Directive parserGetDirective(char *line) {
    char tmpLine[MAX_LENGTH];
    char *token;
    char *directives[] = {DIRECTIVES};
    strcpy(tmpLine, line);
    token = strtok(tmpLine, DIRECTIVE_DELIM);
    if (token[0] == tmpLine[0])     /*the first char is the same -> there were some chars before '.'*/
        token = strtok(NULL, DIRECTIVE_DELIM);
    token = strtok(token, WHITH_DELIMITERS); /*should be only the directive name*/
    if (token == NULL)
        return NO_DIRECTIVE_FOUND;
    if (strcmp(token, directives[ENTRY]) == 0)
        return ENTRY;
    if (strcmp(token, directives[DATA]) == 0)
        return DATA;
    if (strcmp(token, directives[STRING]) == 0)
        return STRING;
    if (strcmp(token, directives[EXTERN]) == 0)
        return EXTERN;
    return NO_DIRECTIVE_FOUND;
}

int findIndexOfElement(const int *array, Operation operation) {
    int i;
    for (i = 0; i < NUMBER_OF_FUNCTIONS; ++i) {
        if (array[i] == operation)
            return i;
    }
    return -1;
}

int parserGetNumberOfOperands(Operation operation) {
    int functionsNumbers[] = {FUNCTIONS_NUMBERS};
    int numberOfOperandsByFunction[] = {NUMBER_OF_OPERANDS};
    return numberOfOperandsByFunction[findIndexOfElement(functionsNumbers, operation)];
}


















