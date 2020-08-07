
/*Created by Omri Kaisari on 06/08/2020.*/

#include "parser.h"
#include <string.h>
#include <stdlib.h>
#include "ctype.h"

char *trimLabel(char *line);

Bool isAlphabetic(char c);

Operation findOperation(char *word);

int findIndexOfElement(const int *array, Operation operation);

Error checkZeroOperandsSyntax(char const *line);


Bool parserIsNewLabel(char *line) {
    if (strchr(line, LABEL_DELIM_CHAR) == NULL)
        return FALSE;
    return TRUE;
}

Bool parserIsDirective(char *line) {
    if (strchr(line, DIRECTIVE_CHAR) == NULL)
        return FALSE;
    return TRUE;
}


char *parserGetLabel(char *line) {
    char *endLocation = strchr(line, LABEL_DELIM_CHAR);
    char *label = malloc(sizeof(*label) * (endLocation - line));
    char *originalPtr = label;
    char *token;
    memcpy(label, line, endLocation - line);
    token = strtok(label, WHITE_DELIMITERS);    /*if the label doesn't begin with alphabetic char, null returned*/
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
    token = strtok(tmpStr, ":");
    if (token == NULL)
        return NULL;        /*there is nothing after the label*/
    token = strtok(NULL, ":");  /*now the first word is the operation*/
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
    return OPERATION_NOT_FOUND;
    
    
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
        return OPERATION_NOT_FOUND;
    operationWord = strtok(operationWord, WHITE_DELIMITERS);
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
    token = strtok(token, WHITE_DELIMITERS); /*should be only the directive name*/
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
    return NA;
}

int parserGetNumberOfOperands(Operation operation) {
    int functionsNumbers[] = {FUNCTIONS_NUMBERS};
    int numberOfOperandsByFunction[] = {NUMBER_OF_OPERANDS};
    return numberOfOperandsByFunction[findIndexOfElement(functionsNumbers, operation)];
}

Error parserCheckArguments(const char *line, int numberOfOperands) {/*This function expects to receive instruction
 * line*/
    char tmpLine[MAX_LENGTH];
    char *trimmed;
    char *token;
    strcpy(tmpLine, line);
    token = tmpLine;
    if (parserIsNewLabel(tmpLine)) {
        trimmed = trimLabel(tmpLine);
        strcpy(tmpLine, trimmed);
        free(trimmed);
        token = tmpLine;
    }
    if (isprint(tmpLine[0]) == 0)
        token = strtok(tmpLine, WHITE_DELIMITERS);   /*now token is on the op word*/
    if (numberOfOperands == 0)
        return checkZeroOperandsSyntax(token);
    if (numberOfOperands == 1) {
        if (strchr(token, COMMA_CHAR) != NULL)
            return ILLEGAL_COMMA;
        token = strtok(tmpLine, WHITE_DELIMITERS);
        token = strtok(NULL, WHITE_DELIMITERS);     /*token should be on the first operand*/
        if (token == NULL || token[0] == '\n')
            return TOO_FEW_OPERANDS;
        token = strtok(NULL, WHITE_DELIMITERS);
        if (token == NULL || token[0] == '\n')
            return NO_ERRORS_FOUND;
        return TOO_MANY_OPERANDS;
    }
    if (numberOfOperands == 2) {
        if (strchr(token, COMMA_CHAR) == NULL) {
            return MISSING_COMMA;
        }
        token = strtok(tmpLine, ", \t\n");
        token = strtok(NULL, ", \t\n");     /*token should be on the first operand*/
        if (token == NULL || token[0] == '\n')
            return TOO_FEW_OPERANDS;
        token = strtok(NULL, ", \t\n");           /*token should be on the second operand*/
        if (token == NULL || token[0] == '\n')
            return TOO_FEW_OPERANDS;
        token = strtok(NULL, ", \t\n");
        if (token != NULL)
            return TOO_MANY_OPERANDS;
        return NO_ERRORS_FOUND;
    }
    return NO_ERRORS_FOUND;
    
}

Error checkZeroOperandsSyntax(char const *line) {    /*line begins with the op word*/
    char tmpLine[MAX_LENGTH];
    char *token;
    strcpy(tmpLine, line);
    token = tmpLine;
    if (strchr(tmpLine, COMMA_CHAR) != NULL) {
        return ILLEGAL_COMMA;
    }
    token = strtok(tmpLine, WHITE_DELIMITERS);   /*token is still on the op word*/
    token = strtok(NULL, WHITE_DELIMITERS);  /*token should be on \n or null*/
    if (token == NULL || *token == '\n')
        return NO_ERRORS_FOUND;
    return TOO_MANY_OPERANDS;
}


/*
 * צריך להוסיף מתודה שבודקת כמות גדולה מדי של פסיקים, פסיקים רצופים ופסיקים במקומות לא נכונים
 * אפשר לעשות זאת ע״י יצירת מחרוזת חסרת רווחים ובדיקה עליה ועוד כל מיני
 * */


















