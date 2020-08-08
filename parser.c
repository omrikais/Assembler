
/*Created by Omri Kaisari on 06/08/2020.*/

#include "parser.h"
#include <string.h>
#include <stdlib.h>
#include "ctype.h"

char *trimLabel(const char *line);

Bool isAlphabetic(char c);

Operation findOperation(char *word);

int findIndexOfElement(const int *array, Operation operation);

Error checkZeroOperandsSyntax(char const *line);

Bool isConsecutiveCommas(const char *string);

Error isTooFewOrManyOperands(const char *line, int numberOfOperands);

int howManyCommas(const char *string);


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

char *deleteSpaces(const char *line) {
    char tmpLine[MAX_LENGTH], *cleanStr;
    int i = 0, j = 0;
    while (i < strlen(line) && (line[i] != '\0' || line[i] != '\n')) {
        if (line[i] != ' ') {
            tmpLine[j++] = line[i++];
        } else
            i++;
    }
    tmpLine[j] = '\0';
    cleanStr = malloc(sizeof(*cleanStr) * (strlen(tmpLine) + 1));
    strcpy(cleanStr, tmpLine);
    return cleanStr;
}

char *trimLabel(const char *line) {
    char tmpStr[MAX_LENGTH];
    char *token;
    char *trimmed;
    strcpy(tmpStr, line);
    if (parserIsNewLabel(line) == FALSE) {
        trimmed = malloc(sizeof((*line) * (strlen(line) + 1)));
        strcpy(trimmed, token);
        return trimmed;
    }
    token = strtok(tmpStr, ":");
    if (token == NULL)
        return NULL;        /*there is nothing after the label*/
    token = strtok(NULL, ":");  /*now the first word is the operation*/
    while (isspace(token[0]))
        ++token;
    trimmed = malloc(sizeof((*trimmed) * (strlen(token) + 1)));
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

char *parserGetStingData(const char *line) {
    /*returns an ascii array of the string
     * assumes to get a string directive line*/
    char tmpLine[MAX_LENGTH], *token;
    char *stringAsciiArray;
    strcpy(tmpLine, line);
    strtok(tmpLine, STRING_DELIM);
    token = strtok(NULL, STRING_DELIM);/*token is now on the string*/
    stringAsciiArray = malloc(sizeof(*stringAsciiArray) * (strlen(token) + 1));
    strcpy(stringAsciiArray, token);
    return stringAsciiArray;
}

List parserGetDataArray(const char *line) {
    /*assumes to get a data directive with valid arguments*/
    char tmpLine[MAX_LENGTH], *token, *trimmed, *rest;
    List dataList = listCreate();
    int currentNumber;
    trimmed = trimLabel(line);
    strcpy(tmpLine, trimmed);
    free(trimmed);
    rest = tmpLine;
    while ((token = strtok_r(rest, ".data, \n", &rest))) {
        currentNumber = atoi(token);
        listInsertNodeAtEnd(dataList, &currentNumber, sizeof(int));
    }
    return dataList;
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

Error parserCheckOperands(const char *line, int numberOfOperands) {/*This function expects to receive instruction
 * line*/
    char tmpLine[MAX_LENGTH], *trimmed, *token;
    Error result;
    strcpy(tmpLine, line);
    token = tmpLine;
    if (isConsecutiveCommas(line) == TRUE)
        return COSECUTIVE_COMMA;
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
    result = isTooFewOrManyOperands(tmpLine, numberOfOperands);
    return result;
}

Error isTooFewOrManyOperands(const char *line, int numberOfOperands) { /*assumes that line begins with opcode */
    char tmpLine[MAX_LENGTH];
    char *token;
    int commaCounter = howManyCommas(line);
    strcpy(tmpLine, line);
    token = strtok(tmpLine, ", \t");
    token = strtok(NULL, ", \t");     /*token should be on the first operand*/
    if (token == NULL || token[0] == '\n')
        return TOO_FEW_OPERANDS;
    if (numberOfOperands == 1) {
        token = strtok(NULL, ", \t");
        if (commaCounter > 0)
            return ILLEGAL_COMMA;
        if (token == NULL || token[0] == '\n')
            return NO_ERRORS_FOUND;
        return TOO_MANY_OPERANDS;
    }
    if (numberOfOperands == 2) {
        token = strtok(NULL, ", \t");           /*token should be on the second operand*/
        if (token == NULL || token[0] == '\n')
            return TOO_FEW_OPERANDS;
        token = strtok(NULL, ", \t\n");
        if (token != NULL)
            return TOO_MANY_OPERANDS;
        if (commaCounter > 1)
            return ILLEGAL_COMMA;
        if (commaCounter < 1)
            return MISSING_COMMA;
        return NO_ERRORS_FOUND;
    }
    return NO_ERRORS_FOUND;
}

int howManyCommas(const char *string) {
    int counter = 0;
    int i;
    for (i = 0; i < strlen(string); i++)
        if (string[i] == ',')
            counter++;
    return counter;
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

Bool isConsecutiveCommas(const char *string) {
    char *doubleComma;
    doubleComma = strstr(string, ",,");
    return doubleComma == NULL ? FALSE : TRUE;
}

char *parserGetOperand(const char *line, int operandIndex) {
    /*assumes that line is an instruction without label and with correct operands structure */
    char tmpLine[MAX_LENGTH];
    char *token, *operand;
    strcpy(tmpLine, line);
    strtok(tmpLine, ":, \n");
    token = strtok(NULL, ":, \n");/*token now is on the first argument*/
    if (operandIndex == 1) {
        operand = deleteSpaces(token);
        return operand;
    }
    token = strtok(NULL, ":, \n");/*token now is on the second argument*/
    operand = deleteSpaces(token);
    return operand;
}

AddressingMethod parserGetAddressingMethodOfOperand(const char *operand) {
    /*assumes that operand is an operand string with no spaces*/
    if (operand[0] == IMMEDIATE_ADDRESSING_SYMBOL)
        return IMMEDIATE;
    if (operand[0] == RELATIVE_ADDRESSING_SYMBOL)
        return RELATIVE;
    if (operand[0] == REGISTER_CHAR && strlen(operand) == 2)
        return REGISTER;
    return DIRECT;
}

size_t parserGetSizeOfElement(void *element, Directive type) {
    if (type == STRING)
        return strlen((char *) element);
    else
        return listGetSizeOf();
}




/*
 * צריך להוסיף פונקציות לקבלת הארגומנטים, פונקציות לקבלת שיטות המיעון של כל אופרנד ועוד ענייני סדר וניקיון.
 * לאחר מכן אפשר להתחיל בבניית מודול בניית הטבלאות שמקבל את הנתונים מהפרסר, מציב אותם במילות הוראה ויוצר ממילות ההוראה רשימת
 * הוראות שמהווה את תמונת הקוד.
 * */


















