
/*Created by Omri Kaisari on 06/08/2020.*/

#include "parser.h"
#include <string.h>
#include <stdlib.h>
#include "ctype.h"

char *trim_label(const char *line);

Bool is_alphabetic(char c);

Operation find_operation(char *word);

int find_index_of_element(const int *array, Operation operation);

Error check_zero_operands_syntax(char const *line);

Bool is_consecutive_commas(const char *string);

Error is_too_few_or_many_operands(const char *line, int numberOfOperands);

int how_many_commas(const char *string);

Bool parser_is_valid_label(const char *label);


Bool parser_is_new_label(const char *line) {
    if (strchr(line, LABEL_DELIM_CHAR) == NULL)
        return False;
    return True;
}

Bool parser_is_directive(char *line) {
    if (strchr(line, DIRECTIVE_CHAR) == NULL)
        return False;
    return True;
}

Bool parser_is_entry(const char *line) {
    if (strstr(line, ".entry") != NULL)
        return True;
    return False;
}


char *parser_get_label(char *line) {
    char tmpLine[MAX_LENGTH];
    char *token, *result;
    strcpy(tmpLine, line);
    token = strtok(tmpLine, ":");
    token = strtok(token, WHITE_DELIMITERS);    /*if the label doesn't begin with alphabetic char, null returned*/
    if (parser_is_valid_label(token)) {
        result = malloc(sizeof(char) * (strlen(token) + 1));
        strcpy(result, token);
        return result;
    }
    return NULL;
}

Bool is_alphabetic(char c) {
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        return True;
    return False;
}

char *delete_spaces(const char *line) {
    char tmpLine[MAX_LINE_LENGTH], *cleanStr = NULL;
    int i = 0, j = 0;
    while (i < strlen(line) && (line[i] != '\0' || line[i] != '\n')) {
        if (line[i] != ' ') {
            tmpLine[j++] = line[i++];
        } else
            i++;
    }
    tmpLine[j] = '\0';
    cleanStr = malloc(sizeof(char) * (strlen(tmpLine) + 1));
    strcpy(cleanStr, tmpLine);
    return cleanStr;
}

char *trim_label(const char *line) {
    char tmpStr[MAX_LINE_LENGTH];
    char *token;
    char *trimmed;
    strcpy(tmpStr, line);
    if (parser_is_new_label(line) == False) {
        trimmed = malloc(sizeof(char) * (strlen(tmpStr) + 1));
        strcpy(trimmed, tmpStr);
        return trimmed;
    }
    token = strchr(tmpStr, ':');
    token += 1;
    if (token[0] == '\0')
        return NULL;        /*there is nothing after the label*/
    while (isspace(token[0]))
        ++token;
    trimmed = malloc(sizeof(char) * (strlen(token) + 1));
    strcpy(trimmed, token);
    return trimmed;
}

Operation find_operation(char *word) {
    char *functions[] = {FUNCTIONS};
    int functionsNumbers[] = {FUNCTIONS_NUMBERS};
    int i;
    for (i = 0; i < NUMBER_OF_FUNCTIONS; ++i) {
        if (strcmp(word, functions[i]) == 0) {
            Operation operation = (Operation) functionsNumbers[i];
            return operation;
        }
    }
    return OperationNotFound;
}

Operation parse_get_operation(const char *line) { /*trim the line, and then only get the operation*/
    char *operationWord = NULL;
    char *startPtr;
    Operation operation;
    if (parser_is_new_label(line) == True)
        operationWord = trim_label(line);
    else {
        operationWord = malloc(sizeof(*operationWord) * MAX_LENGTH);
        strcpy(operationWord, line);
    }
    startPtr = operationWord;
    if (operationWord == NULL)
        return OperationNotFound;
    operationWord = strtok(operationWord, WHITE_DELIMITERS);
    operationWord = strtok(operationWord, NEW_LINE_DELIM);
    operation = find_operation(operationWord);
    free(startPtr);
    return operation;
}

Directive parser_get_directive(char *line) {
    char tmpLine[MAX_LENGTH];
    char *token;
    char *directives[] = {DIRECTIVES};
    strcpy(tmpLine, line);
    token = strtok(tmpLine, DIRECTIVE_DELIM);
    if (token[0] == tmpLine[0])     /*the first char is the same -> there were some chars before '.'*/
        token = strtok(NULL, DIRECTIVE_DELIM);
    token = strtok(token, " \t\n"); /*should be only the directive name*/
    if (token == NULL)
        return NoDirectiveFound;
    if (strcmp(token, directives[Entry]) == 0)
        return Entry;
    if (strcmp(token, directives[Data]) == 0)
        return Data;
    if (strcmp(token, directives[String]) == 0)
        return String;
    if (strcmp(token, directives[Extern]) == 0)
        return Extern;
    return NoDirectiveFound;
}

List parser_get_string_data(const char *line) {
    /*returns an ascii array of the string
     * assumes to get a string directive line*/
    char tmpLine[MAX_LENGTH], *token;
    char *stringAsciiArray;
    int i = 0, current;
    List charList = list_create();
    strcpy(tmpLine, line);
    strtok(tmpLine, STRING_DELIM);
    token = strtok(NULL, STRING_DELIM);/*token is now on the string*/
    stringAsciiArray = malloc(sizeof(int) * (strlen(token) + 1));
    strcpy(stringAsciiArray, token);
    for (; i < strlen(stringAsciiArray) + 1; ++i) {
        current = (int) stringAsciiArray[i];
        list_insert_node_at_end(charList, &current, sizeof(int));
    }
    free(stringAsciiArray);
    return charList;
}

List parser_get_data_array(const char *line) {
    /*assumes to get a Data directive with valid arguments*/
    char tmpLine[MAX_LENGTH], *token, *trimmed;
    List dataList = list_create();
    long currentNumber;
    trimmed = trim_label(line);
    strcpy(tmpLine, trimmed);
    free(trimmed);
    token = strtok(tmpLine, "., \n\t");
    while ((token = strtok(NULL, "., \n\t")) != NULL) {
        currentNumber = atol(token);
        list_insert_node_at_end(dataList, &currentNumber, sizeof(long));
    }
    return dataList;
}

int find_index_of_element(const int *array, Operation operation) {
    int i;
    for (i = 0; i < NUMBER_OF_FUNCTIONS; ++i) {
        if (array[i] == operation)
            return i;
    }
    return NA;
}

int parser_get_number_of_operands(Operation operation) {
    int functionsNumbers[] = {FUNCTIONS_NUMBERS};
    int numberOfOperandsByFunction[] = {NUMBER_OF_OPERANDS};
    return numberOfOperandsByFunction[find_index_of_element(functionsNumbers, operation)];
}

Error parser_check_operands(const char *line, int numberOfOperands) {/*This function expects to receive instruction
 * line*/
    char tmpLine[MAX_LENGTH], *trimmed, *token;
    Error result;
    strcpy(tmpLine, line);
    token = tmpLine;
    if (is_consecutive_commas(line) == True)
        return ConsecutiveComma;
    if (parser_is_new_label(tmpLine)) {
        trimmed = trim_label(tmpLine);
        strcpy(tmpLine, trimmed);
        free(trimmed);
        token = tmpLine;
    }
    if (isprint(tmpLine[0]) == 0)
        token = strtok(tmpLine, WHITE_DELIMITERS);   /*now token is on the op word*/
    if (numberOfOperands == 0)
        return check_zero_operands_syntax(token);
    result = is_too_few_or_many_operands(tmpLine, numberOfOperands);
    return result;
}

Error is_too_few_or_many_operands(const char *line, int numberOfOperands) { /*assumes that line begins with opcode */
    char tmpLine[MAX_LENGTH];
    char *token;
    int commaCounter = how_many_commas(line);
    strcpy(tmpLine, line);
    strtok(tmpLine, ", \t");
    token = strtok(NULL, ", \t");     /*token should be on the first operand*/
    if (token == NULL || token[0] == '\n')
        return TooFewOperands;
    if (numberOfOperands == 1) {
        token = strtok(NULL, ", \t");
        if (commaCounter > 0)
            return IllegalComma;
        if (token == NULL || token[0] == '\n')
            return NoErrorsFound;
        return TooManyOperands;
    }
    if (numberOfOperands == 2) {
        token = strtok(NULL, ", \t");           /*token should be on the second operand*/
        if (token == NULL || token[0] == '\n')
            return TooFewOperands;
        token = strtok(NULL, ", \t\n");
        if (token != NULL)
            return TooManyOperands;
        if (commaCounter > 1)
            return IllegalComma;
        if (commaCounter < 1)
            return MissingComma;
        return NoErrorsFound;
    }
    return NoErrorsFound;
}

int how_many_commas(const char *string) {
    int counter = 0;
    int i;
    for (i = 0; i < strlen(string); i++)
        if (string[i] == ',')
            counter++;
    return counter;
}

Error check_zero_operands_syntax(char const *line) {    /*line begins with the op word*/
    char tmpLine[MAX_LENGTH];
    char *token;
    strcpy(tmpLine, line);
    if (strchr(tmpLine, COMMA_CHAR) != NULL) {
        return IllegalComma;
    }
    strtok(tmpLine, WHITE_DELIMITERS);   /*token is still on the op word*/
    token = strtok(NULL, WHITE_DELIMITERS);  /*token should be on \n or null*/
    if (token == NULL || *token == '\n')
        return NoErrorsFound;
    return TooManyOperands;
}

Bool is_consecutive_commas(const char *string) {
    char *doubleComma;
    doubleComma = strstr(string, ",,");
    return doubleComma == NULL ? False : True;
}

Bool parser_is_valid_label(const char *label) {
    int i;
    for (i = 0; i < strlen(label); ++i) {
        if (i == 0)
            if (isalpha(label[i]) == 0)
                return False;
        if (isalnum(label[i]) == 0)
            return False;
    }
    if (strlen(label) > 31)
        return False;
    return True;
}

Bool parser_is_empty_line(const char *line) {
    char tmpLine[MAX_LENGTH], *token;
    strcpy(tmpLine, line);
    token = strtok(tmpLine, " \t\n");
    if (token == NULL)
        return True;
    if (token[0] == ';')
        return True;
    return False;
}

char *parser_get_operand(const char *line, int operandIndex) {
    /*assumes that line  with correct operands structure */
    char tmpLine[MAX_LENGTH];
    char *token, *operand;
    char *noLabelLine;
    noLabelLine = trim_label(line);
    strcpy(tmpLine, noLabelLine);
    free(noLabelLine);
    strtok(tmpLine, ":, \n");
    token = strtok(NULL, ":, \n");/*token now is on the first argument*/
    if (operandIndex == 1) {
        operand = delete_spaces(token);
        return operand;
    }
    token = strtok(NULL, ":, \n");/*token now is on the second argument*/
    operand = delete_spaces(token);
    return operand;
}

AddressingMethod parser_get_addressing_method_of_operand(const char *operand) {
    /*assumes that operand is an operand string with no spaces*/
    if (operand[0] == IMMEDIATE_ADDRESSING_SYMBOL)
        return Immediate;
    if (operand[0] == RELATIVE_ADDRESSING_SYMBOL)
        return Relative;
    if (operand[0] == REGISTER_CHAR && strlen(operand) == 2)
        return Register;
    return Direct;
}

size_t parser_get_size_of_element(void *element, Directive type) {
    if (type == String)
        return strlen((char *) element);
    else
        return list_get_size_of();
}


char *parser_get_extern_label(const char *line, Error *result) {
    char tmpLine[MAX_LENGTH];
    char *token, *operand;
    strcpy(tmpLine, line);
    token = strtok(tmpLine, ". \n\t");/*should be on extern*/
    token = strtok(NULL, ". \n\t");/*should be on label*/
    if (token == NULL) {
        *result = MissingLabel;
        return NULL;
    }
    operand = malloc(sizeof(char) * (strlen(token) + 1));
    strcpy(operand, token);
    if (parser_is_valid_label(operand) == False) {
        free(operand);
        *result = IllegalLabel;
        return NULL;
    }
    if (strtok(NULL, " \n\t") != NULL) {
        free(operand);
        *result = TooManyParametersOfExtern;
        return NULL;
    }
    *result = NoErrorsFound;
    return operand;
}


int parser_get_register_num(const char *operand) {
    char *endPtr;
    long int registerNumber = strtol(operand + 1, &endPtr, 10);
    if (registerNumber < 0 || registerNumber > 7)
        return NA;
    return (int) registerNumber;
}

long parser_get_immediate_operand(const char *operand) {
    long operandValue = atol(operand + 1);
    int i = 1;
    if (strlen(operand) <= 1)
        return NA;
    for (; i < (strlen(operand) - 1); ++i) {
        if (i == 1 && operand[i] == '-')
            continue;
        if (isnumber(operand[i]) == False)  /*change it - should be is_not_number*/
            return NA;
    }
    return operandValue;
}

char *parser_get_label_from_operand(const char *operand) {
    char *label;
    const char *toCopy = operand;
    if (operand[0] == RELATIVE_ADDRESSING_SYMBOL)
        toCopy += 1;
    label = malloc(sizeof(char) * (strlen(toCopy) + 1));
    strcpy(label, toCopy);
    return label;
}

Error parser_check_string_directive_form(const char *line, Directive directive) {
    /*assumes data (string or data) directive*/
    char tmpLine[MAX_LINE_LENGTH], *trimmed, *token, *cleanStr, endChar;
    trimmed = trim_label(line);
    strcpy(tmpLine, trimmed);
    free(trimmed);
    cleanStr = delete_spaces(tmpLine);
    strcpy(tmpLine, cleanStr);
    token = tmpLine + strlen(".string");
    if (strchr(token, '\"') == NULL)
        return StringWithoutQuotes;
    if (token[0] != '\"')
        return NoOpenQuoteMark;
    if (token[strlen(token) - 2] != '\"')
        return NoEndQuoteMark;
    token = strtok(token, "\"");
    token = strtok(NULL, "\"");
    if (token == NULL)
        return NoErrorsFound;
    if (token[0] != '\n')
        return StringDirectiveHasMoreThenOneArgument;
    return NoErrorsFound;
}

Error parser_check_data_directive_form(const char *line, Directive directive) {

}


























