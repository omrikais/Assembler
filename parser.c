/*Created by Omri Kaisari on 06/08/2020.*/

#include <string.h>
#include <ctype.h>
#include "parser.h"

char *trim_label(const char *line);

Operation find_operation(char *word);

int find_index_of_element(const int *array, Operation operation);

Error check_zero_operands_syntax(char const *line);

Bool is_consecutive_commas(const char *string);

Error is_too_few_or_many_operands(const char *line, int numberOfOperands);

int how_many_commas(const char *string);

Bool is_number(char c);

Error check_comma_between_data_elements(const char *line);

Error check_arguments_of_data(const char *line);

Error parser_after_label_check(const char *line);

char *get_string_of_string_directive(const char *line);

Bool parser_is_new_label(const char *line) {
    if (strchr(line, LABEL_DELIM_CHAR) == NULL)
        return False;
    return True;
}

Bool parser_is_directive(char *line) {
    char tmpLine[MAX_LINE_LENGTH], *token, *trimmed;
    trimmed = trim_label(line);
    strcpy(tmpLine, trimmed);
    free(trimmed);
    token = strtok(tmpLine, WHITE_DELIM_WITH_NEW_LINE);   /*directive word*/
    if (token != NULL && strchr(token, DIRECTIVE_CHAR) != NULL)
        return True;
    return False;
}

Bool parser_is_entry(const char *line) {
    if (strstr(line, ENTRY) != NULL)
        return True;
    return False;
}

Bool parser_is_empty_label(const char *line) {
    Error error;
    char *ptr = NULL;
    if (parser_is_new_label(line)) {
        ptr = parser_get_label(line, &error);
        if (error == OnlyLabel)
            return True;
    }
    if (ptr != NULL)
        free(ptr);
    return False;
}

char *parser_get_label(const char *line, Error *error) {
    char tmpLine[MAX_LINE_LENGTH], *result;
    char *token;
    strcpy(tmpLine, line);
    token = strtok(tmpLine, LABEL_DELIM);
    token = strtok(token, WHITE_DELIMITERS);    /*if the label doesn't begin with alphabetic char, null returned*/
    *error = parser_is_valid_label(token);
    if (*error == NoErrorsFound && (*error = parser_after_label_check(line)) == NoErrorsFound) {
        result = malloc(sizeof(char) * (strlen(token) + 1));
        strcpy(result, token);
        return result;
    }
    return NULL;
}

Error parser_after_label_check(const char *line) {
    char tmpLine[MAX_LINE_LENGTH], *token;
    strcpy(tmpLine, line);
    strtok(tmpLine, IGNORED_DELIM);  /*on the label*/
    token = strtok(NULL, IGNORED_DELIM); /*on the first word after the label*/
    if (token == NULL) {
        return OnlyLabel;
    }
    return NoErrorsFound;
}

char *delete_spaces(const char *line) {
    char tmpLine[MAX_LINE_LENGTH], *cleanStr = NULL;
    int i = 0, j = 0;
    while ((i < strlen(line)) != 0) {
        if (line[i] != ' ') {
            tmpLine[j++] = line[i++];
        } else
            i++;
    }
    tmpLine[j] = STRING_END;
    cleanStr = malloc(sizeof(char) * (strlen(tmpLine) + 1));
    strcpy(cleanStr, tmpLine);
    return cleanStr;
}

char *trim_label(const char *line) {
    char tmpStr[MAX_LINE_LENGTH], *token, *trimmed;
    strcpy(tmpStr, line);
    if (!parser_is_new_label(line)) {
        trimmed = malloc(sizeof(char) * (strlen(tmpStr) + 1));
        strcpy(trimmed, tmpStr);
        return trimmed;
    }
    token = strchr(tmpStr, LABEL_DELIM_CHAR);
    ++token;
    if (token[BEGINNING] == STRING_END)
        return NULL;        /*there is nothing after the label*/
    while (isspace(token[BEGINNING]))
        ++token;
    trimmed = malloc(sizeof(char) * (strlen(token) + 1));
    strcpy(trimmed, token);
    return trimmed;
}

Operation find_operation(char *word) {
    char *functions[] = {FUNCTIONS};
    int functionsNumbers[] = {FUNCTIONS_NUMBERS};
    int i;
    for (i = 0; i < NUMBER_OF_FUNCTIONS; ++i)
        if (strcmp(word, functions[i]) == 0) {
            Operation operation = (Operation) functionsNumbers[i];
            return operation;
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
    char tmpLine[MAX_LENGTH], *token;
    char *directives[] = {DIRECTIVES};
    int size = NUMBER_OF_DIRECTIVE, i = 0;
    strcpy(tmpLine, line);
    token = strtok(tmpLine, DIRECTIVE_DELIM);
    if (token[BEGINNING] ==
        tmpLine[BEGINNING])              /*the first char is the same -> there were some chars before '.'*/
        token = strtok(NULL, DIRECTIVE_DELIM);
    token = strtok(token, " \t\n");     /*should be only the directive name*/
    while (token != NULL && i < size) {
        if (strcmp(token, directives[i]) == 0)
            return (Directive) i;
        i++;
    }
    return NoDirectiveFound;
}

List parser_get_string_data(const char *line) {
    /*returns an ascii array of the string ,assumes to get a string directive line*/
    char tmpLine[MAX_LENGTH], *token, *stringAsciiArray;
    int i, current;
    List charList = list_create();
    strcpy(tmpLine, line);
    strtok(tmpLine, STRING_DELIM);
    token = strtok(NULL, STRING_DELIM);/*token is now on the string*/
    stringAsciiArray = malloc(sizeof(int) * (strlen(token) + 1));
    strcpy(stringAsciiArray, token);
    for (i = 0; i < strlen(stringAsciiArray) + 1; ++i) {
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
    strtok(tmpLine, IGNORED);
    while ((token = strtok(NULL, IGNORED)) != NULL) {
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

Error
parser_check_operands(const char *line, int numberOfOperands) {/*This function expects to receive instruction line*/
    char tmpLine[MAX_LENGTH], *trimmed, *token;
    Error result;
    strcpy(tmpLine, line);
    token = tmpLine;
    if (is_consecutive_commas(line))
        return ConsecutiveComma;
    if (parser_is_new_label(tmpLine)) {
        trimmed = trim_label(tmpLine);
        strcpy(tmpLine, trimmed);
        free(trimmed);
        token = tmpLine;
    }
    if (isprint(tmpLine[BEGINNING]) == 0)
        token = strtok(tmpLine, WHITE_DELIMITERS);   /*now token is on the op word*/
    if (numberOfOperands == NO_OPERANDS)
        return check_zero_operands_syntax(token);
    result = is_too_few_or_many_operands(tmpLine, numberOfOperands);
    return result;
}

Error is_too_few_or_many_operands(const char *line, int numberOfOperands) { /*assumes that line begins with opcode */
    char tmpLine[MAX_LINE_LENGTH], *token;
    int commaCounter = how_many_commas(line);
    Error result = NoErrorsFound;
    strcpy(tmpLine, line);
    strtok(tmpLine, IGNORED_WHITE);
    token = strtok(NULL, ", \t");     /*token should be on the first operand*/
    if (token == NULL || token[0] == '\n')
        return TooFewOperands;
    if (numberOfOperands == ONE_OPERAND) {
        token = strtok(NULL, IGNORED_WHITE);
        if (commaCounter > 0)
            result = IllegalComma;
        if (token == NULL || token[0] == '\n')
            return result;
        return TooManyOperands;
    }
    if (numberOfOperands == TWO_OPERANDS) {
        token = strtok(NULL, IGNORED_WHITE);           /*token should be on the second operand*/
        if (token == NULL || token[BEGINNING] == '\n')
            return TooFewOperands;
        token = strtok(NULL, ", \t\n");
        if (token != NULL)
            return TooManyOperands;
        if (commaCounter > 1)
            result = IllegalComma;
        if (commaCounter < 1)
            result = MissingComma;
        return result;
    }
    return NoErrorsFound;
}

int how_many_commas(const char *string) {
    int counter = 0, i;
    for (i = 0; i < strlen(string); i++)
        if (string[i] == ',')
            counter++;
    return counter;
}

Error check_zero_operands_syntax(char const *line) {    /*line begins with the op word*/
    char tmpLine[MAX_LENGTH], *token;
    Error result = NoErrorsFound;
    strcpy(tmpLine, line);
    if (strchr(tmpLine, COMMA_CHAR) != NULL)
        result = IllegalComma;
    strtok(tmpLine, " \n\t,");   /*token is still on the op word*/
    token = strtok(NULL, WHITE_DELIMITERS);  /*token should be on \n or null*/
    if (token == NULL || *token == '\n')
        return result;
    return TooManyOperands;
}

Bool is_consecutive_commas(const char *string) {
    char *doubleComma;
    doubleComma = strstr(string, ",,");
    return doubleComma == NULL ? False : True;
}

Error parser_is_valid_label(const char *label) {
    int i;
    if (strlen(label) > MAX_LABEL_LENGTH)
        return LabelTooLong;
    for (i = 0; i < strlen(label); ++i) {
        if (i == 0)
            if (isalpha(label[i]) == 0)
                return LabelNoAlphabeticStart;
        if (isalnum(label[i]) == 0)
            return LabelWithNonAlphanumeric;
    }
    return NoErrorsFound;
}

Bool parser_is_empty_line(const char *line) {
    char tmpLine[MAX_LINE_LENGTH], *token;
    strcpy(tmpLine, line);
    token = strtok(tmpLine, WHITE_DELIM_WITH_NEW_LINE);
    if (token == NULL)
        return True;
    if (token[0] == ';')
        return True;
    return False;
}

char *parser_get_operand(const char *line, int operandIndex) {
    /*assumes that line  with correct operands structure */
    char tmpLine[MAX_LENGTH], *token, *operand, *noLabelLine;
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
    if (operand[BEGINNING] == IMMEDIATE_ADDRESSING_SYMBOL)
        return Immediate;
    if (operand[BEGINNING] == RELATIVE_ADDRESSING_SYMBOL)
        return Relative;
    if (operand[BEGINNING] == REGISTER_CHAR && strlen(operand) == 2)
        return Register;
    if (isalpha(operand[BEGINNING]))
        return Direct;
    return NA;
}

size_t parser_get_size_of_element(void *element, Directive type) {
    if (type == String)
        return strlen((char *) element);
    else
        return list_get_size_of();
}

char *parser_get_extern_label(const char *line, Error *result) {
    char tmpLine[MAX_LENGTH], *token, *operand;
    strcpy(tmpLine, line);
    strtok(tmpLine, ". \n\t");/*should be on extern*/
    token = strtok(NULL, ". \n\t");/*should be on label*/
    if (token == NULL) {
        *result = MissingLabel;
        return NULL;
    }
    *result = parser_is_valid_label(token);
    if (*result != NoErrorsFound)
        return NULL;
    operand = malloc(sizeof(char) * (strlen(token) + 1));
    strcpy(operand, token);
    *result = parser_is_valid_label(operand);
    if (*result != NoErrorsFound) {
        free(operand);
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
        if (!is_number(operand[i]))
            return NA;
    }
    return operandValue;
}

Bool is_number(char c) {
    if (c >= '0' && c <= '9')
        return True;
    return False;
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

Error parser_check_string_directive_form(const char *line) {
    /*assumes data (string or data) directive*/
    char *token = get_string_of_string_directive(line), *startPtr = token;
    if (strchr(token, '\"') == NULL) {
        free(token);
        return StringWithoutQuotes;
    }
    if (token[0] != '\"') {
        free(token);
        return NoOpenQuoteMark;
    }
    if (token[strlen(token) - 2] != '\"') {
        free(token);
        return NoEndQuoteMark;
    }
    strtok(token, "\"");
    token = strtok(NULL, "\"");
    if (token == NULL) {
        free(startPtr);
        return NoErrorsFound;
    }
    if (token[0] != '\n') {
        free(startPtr);
        return StringDirectiveHasMoreThenOneArgument;
    }
    free(startPtr);
    return NoErrorsFound;
}

char *get_string_of_string_directive(const char *line) {
    char tmpLine[MAX_LINE_LENGTH], *trimmed, *token, *cleanStr, *result;
    int lengthOfDirective;
    trimmed = trim_label(line);
    cleanStr = delete_spaces(trimmed);
    strcpy(tmpLine, cleanStr);
    free(trimmed);
    free(cleanStr);
    lengthOfDirective = (strstr(tmpLine, ".string") != NULL) ? strlen(".string") : strlen(".data");
    token = tmpLine + lengthOfDirective;
    result = malloc(sizeof(char) * (strlen(token) + 1));
    strcpy(result, token);
    return result;
}

Error parser_check_data_directive_form(const char *line) {
    char tmpLine[MAX_LINE_LENGTH], *stringPtr;
    stringPtr = trim_label(line);
    strcpy(tmpLine, stringPtr);
    free(stringPtr);
    return parser_check_commas_in_data_directive(tmpLine);
}

Error check_comma_between_data_elements(const char *line) {
    Bool isNumberEnded = False, isCommaAppeared = True;
    int i;
    char *strPtr = get_string_of_string_directive(line);
    for (i = 0; i < strlen(strPtr) - 1; ++i) {
        if (isspace(strPtr[i])) {
            isNumberEnded = True;
            continue;
        }
        if (strPtr[i] == ',') {
            isNumberEnded = True;
            isCommaAppeared = True;
        }
        if (is_number(strPtr[i]) && !isCommaAppeared && isNumberEnded) {
            free(strPtr);
            return MissingComma;
        }
        if (is_number(strPtr[i]) && isCommaAppeared && isNumberEnded) {
            isCommaAppeared = False;
            isNumberEnded = False;
        }
        if (is_number(strPtr[i]) && !isNumberEnded)
            continue;
    }
    free(strPtr);
    return NoErrorsFound;
}

Error check_arguments_of_data(const char *line) {
    char tmpLine[MAX_LINE_LENGTH];
    const char *strPtr;
    int i;
    strcpy(tmpLine, line);
    strPtr = line + strlen(".data");
    for (i = 0; i < strlen(strPtr) - 1; ++i)
        if (!isspace(strPtr[i]) && !is_number(strPtr[i]) && strPtr[i] != ',' && strPtr[i] != '-' && strPtr[i] != '+')
            return WrongTypeDataArgument;
    return NoErrorsFound;
}

Error parser_check_commas_in_data_directive(const char *line) {
    /*assumes to get line of data directive without a label*/
    char *strPtr = get_string_of_string_directive(line);
    Error result;
    if (strstr(strPtr, ",,") != NULL) {
        free(strPtr);
        return ConsecutiveComma;
    }
    if (strPtr[0] == ',') {
        free(strPtr);
        return CommaAfterDirective;
    }
    if (strPtr[strlen(strPtr) - 2] == ',') {
        free(strPtr);
        return CommaAfterLast;
    }
    free(strPtr);
    result = check_comma_between_data_elements(line);
    if (result != NoErrorsFound)
        return result;
    return check_arguments_of_data(line);
}
