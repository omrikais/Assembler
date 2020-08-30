/*Created by Omri Kaisari on 06/08/2020.*/

#include <string.h>
#include <ctype.h>
#include "parser.h"

/************************************************** Internal functions ************************************************/

/**
 * @brief           checks if a given label is a command word
 * @param label     the label to check
 * @return          True if the label is a command word
 */
Bool is_operation_string(const char *label);

/**
 * @brief           checks if a given label is a valid register string
 * @param label     the label to check
 * @return          True if a given label is a valid register string
 */
Bool is_register_label(const char *label);

/**
 * @brief gets an input line and returns copy of the line without the label of the original line.
 *          if no label exist, return copy of the original line
 * @param line
 * @return
 */
char *trim_label(const char *line);

/**
 * @brief gets a string of assembly operation and returns the the equivalent Operation type as defined in constants.h
 * @param word  the string of the operation
 * @return      the equivalent Operation type
 */
Operation find_operation(char *word);

/**
 * @brief finds the index of a given operation on array of opcodes
 * @param array         an opcodes array of the defined operation of the assembler
 * @param operation     the operation to fine
 * @return
 */
int find_index_of_element(const int *array, Operation operation);

/**
 * @brief gets a line with zero operands operation and checks if its syntax if well built.
 * @param line  the line with zero operands operation
 * @return      error code if the syntax isn't well build or NoErrorsFound
 */
Error check_zero_operands_syntax(char const *line);

/**
 * @brief checks if an input line as in it consecutive commas
 * @param line
 * @return True if consecutives commas occurred.
 */
Bool is_consecutive_commas(const char *line);

/**
 * @brief checks an input line in terms of its numbers of operands based the opcode in it.
 * @param line
 * @param numberOfOperands  the number of operands that should appear in the line, based on its opcode
 * @return                  error code if the the actual number of operands is not accord the given number of operands
 */
Error is_too_few_or_many_operands(const char *line, int numberOfOperands);

/**
 * @brief gets an input line (an instruction line) and returns the number of comma chars in it.
 * @param line
 * @return
 */
int how_many_commas(const char *line);

/**
 * @brief get a char and checks whether it is a number char.
 * @param c
 * @return  True if c is a number char or False otherwise
 */
Bool is_number(char c);

/**
 * @brief gets a data input line and checks whether the commas between the arguments are correctly written
 * @param line
 * @return      a relevant error code or NoErrorsFound
 */
Error check_comma_between_data_elements(const char *line);

/**
 * @brief gets a data input line and checks if it includes only integers within it.
 * @param line
 * @return      a relevant error code or NoErrorsFound
 */
Error check_arguments_of_data(const char *line);

/**
 * @brief  gets a data or string directive input line and returns a string of its numbers array (if it is a data
 *              directive) or the string of it, if it is a string directive
 * @param line
 * @return      a copy of the string found in the line argument
 */
char *get_string_of_directive(const char *line, Bool deleteSpaces);

/**
 * @brief       gets a data directive input line and checks if the commas in this line are according to the syntax of
 *              the assembly language.
 * @param line  a data directive input line
 * @return      a relevant error code or NoErrorsFound
 */
Error check_commas_in_data_directive(const char *line);

/************************************************** Functions implementations *****************************************/

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

List parser_get_data_array(const char *line, Error *error) {
    /*assumes to get a Data directive with valid arguments*/
    char tmpLine[MAX_LENGTH], *token, *trimmed;
    List dataList = list_create();
    long currentNumber;
    trimmed = trim_label(line);
    strcpy(tmpLine, trimmed);
    free(trimmed);
    strtok(tmpLine, IGNORED);
    while ((token = strtok(NULL, IGNORED)) != NULL) {
        char *endPtr = NULL;
        currentNumber = strtol(token, &endPtr, 10);
        if (endPtr != NULL && strlen(endPtr) != 0) {
            *error = BadDataElement;
            list_destroy(dataList, NULL);
            return NULL;
        }
        if (currentNumber > MAX_24_BIT_NUMBER || currentNumber < -MAX_24_BIT_NUMBER - 1) {
            *error = OverflowDirective;
            list_destroy(dataList, NULL);
            return NULL;
        }
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
    token = strtok(NULL, IGNORED_WHITE);     /*token should be on the first operand*/
    if (token == NULL || token[0] == NEW_LINE_CHAR)
        return TooFewOperands;
    if (numberOfOperands == ONE_OPERAND) {
        token = strtok(NULL, IGNORED_WHITE);
        if (commaCounter > 0)
            result = IllegalComma;
        if (token == NULL || token[BEGINNING] == NEW_LINE_CHAR)
            return result;
        return TooManyOperands;
    }
    if (numberOfOperands == TWO_OPERANDS) {
        token = strtok(NULL, IGNORED_WHITE);           /*token should be on the second operand*/
        if (token == NULL || token[BEGINNING] == NEW_LINE_CHAR)
            return TooFewOperands;
        token = strtok(NULL, INSTRUCTION_LINE_DELIMITERS);
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

int how_many_commas(const char *line) {
    int counter = 0, i;
    for (i = 0; i < strlen(line); i++)
        if (line[i] == COMMA_CHAR)
            counter++;
    return counter;
}

Error check_zero_operands_syntax(char const *line) {    /*line begins with the op word*/
    char tmpLine[MAX_LENGTH], *token;
    Error result = NoErrorsFound;
    strcpy(tmpLine, line);
    if (strchr(tmpLine, COMMA_CHAR) != NULL)
        result = IllegalComma;
    strtok(tmpLine, INSTRUCTION_LINE_DELIMITERS);   /*token is still on the op word*/
    token = strtok(NULL, WHITE_DELIMITERS);  /*token should be on \n or null*/
    if (token == NULL || *token == NEW_LINE_CHAR)
        return result;
    return TooManyOperands;
}

Bool is_consecutive_commas(const char *line) {
    char *doubleComma;
    doubleComma = strstr(line, DOUBLE_COMMA);
    return doubleComma == NULL ? False : True;
}

Error parser_is_valid_label(const char *label) {
    int i;
    if (strlen(label) > MAX_LABEL_LENGTH)
        return LabelTooLong;
    if (is_operation_string(label))
        return LabelBadNameOperation;
    if (is_register_label(label))
        return LabelBadNameRegister;
    for (i = 0; i < strlen(label); ++i) {
        if (i == 0)
            if (isalpha(label[i]) == 0)
                return LabelNoAlphabeticStart;
        if (isalnum(label[i]) == 0)
            return LabelWithNonAlphanumeric;
    }
    return NoErrorsFound;
}

Bool is_register_label(const char *label) {
    return (strlen(label) == 2 && label[0] == REGISTER_CHAR &&
            label[1] >= MINIMAL_REGISTER_CHAR && label[1] <= MAXIMAL_REGISTER_CHAR);

}

Bool is_operation_string(const char *label) {
    char *functions[] = {FUNCTIONS};
    int i;
    for (i = 0; i < NUMBER_OF_FUNCTIONS; ++i) {
        if (strcmp(functions[i], label) == 0)
            return True;
    }
    return False;
}

Bool parser_is_empty_line(const char *line) {
    char tmpLine[MAX_LINE_LENGTH], *token;
    strcpy(tmpLine, line);
    token = strtok(tmpLine, WHITE_DELIM_WITH_NEW_LINE);
    if (token == NULL)
        return True;
    if (token[0] == COMMENT_DELIMITER)
        return True;
    return False;
}

Bool parser_is_empty_directive(const char *line, Directive directive) {
    char *directives[] = {DIRECTIVES};
    char tmpLine[MAX_LINE_LENGTH], *trimmed, *directiveStr, *lineStr, *noSpacesLine;
    directiveStr = directives[directive];
    trimmed = trim_label(line);
    strcpy(tmpLine, trimmed);
    free(trimmed);
    noSpacesLine = delete_spaces(tmpLine);
    lineStr = noSpacesLine + strlen(directiveStr) + 1;
    if (strtok(lineStr, DIRECTIVE_DELIMITERS) == NULL) {
        free(noSpacesLine);
        return True;
    }
    free(noSpacesLine);
    return False;
}

char *parser_get_operand(const char *line, int operandIndex) {
    /*assumes that line  with correct operands structure */
    char tmpLine[MAX_LENGTH], *token, *operand, *noLabelLine;
    noLabelLine = trim_label(line);
    strcpy(tmpLine, noLabelLine);
    free(noLabelLine);
    strtok(tmpLine, LABEL_LINE_DELIMITERS);
    token = strtok(NULL, LABEL_LINE_DELIMITERS);/*token now is on the first argument*/
    if (operandIndex == SOURCE_INDEX) {
        operand = delete_spaces(token);
        return operand;
    }
    token = strtok(NULL, LABEL_LINE_DELIMITERS);/*token now is on the second argument*/
    operand = delete_spaces(token);
    return operand;
}

AddressingMethod parser_get_addressing_method_of_operand(const char *operand) {
    /*assumes that operand is an operand string with no spaces*/
    if (operand[BEGINNING] == IMMEDIATE_ADDRESSING_SYMBOL)
        return Immediate;
    if (operand[BEGINNING] == RELATIVE_ADDRESSING_SYMBOL)
        return Relative;
    if (operand[BEGINNING] == REGISTER_CHAR && strlen(operand) == MAX_REGISTER_OPERAND_STR_LENGTH)
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
    char tmpLine[MAX_LENGTH], *token, *operand, *trimmed;
    trimmed = trim_label(line);
    strcpy(tmpLine, trimmed);
    free(trimmed);
    strtok(tmpLine, DIRECTIVE_DELIMITERS);/*should be on extern*/
    token = strtok(NULL, DIRECTIVE_DELIMITERS);/*should be on label*/
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
    if (strtok(NULL, WHITE_DELIM_WITH_NEW_LINE) != NULL) {
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
    if (registerNumber < MINIMAL_REGISTER || registerNumber > MAXIMAL_REGISTER)
        return NA;
    return (int) registerNumber;
}

long parser_get_immediate_operand(const char *operand) {
    char *ptr = NULL;
    int i;
    long operandValue = strtol(operand + 1, &ptr, 10);
    if (strlen(operand) <= 1)
        return NA_NUMBER;
    for (i = FIRST_ELEMENT; i < (strlen(operand) - 1); ++i) {
        if (i == FIRST_ELEMENT && operand[i] == MINUS_CHAR)
            continue;
        if (!is_number(operand[i]))
            return NA_NUMBER;
    }
    if (ptr != NULL && (strlen(ptr) != 0)) {
        if (*ptr != COMMA_CHAR || *ptr != NEW_LINE_CHAR)
            return NA_NUMBER;
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
    if (operand[BEGINNING] == RELATIVE_ADDRESSING_SYMBOL)
        ++toCopy;
    label = malloc(sizeof(char) * (strlen(toCopy) + 1));
    strcpy(label, toCopy);
    return label;
}

Error parser_check_string_directive_form(const char *line) {
    /*assumes data (string or data) directive*/
    char *token = get_string_of_directive(line, True), *startPtr = token;
    if (strchr(token, STRING_DELIM_CHAR) == NULL) {
        free(token);
        return StringWithoutQuotes;
    }
    if (token[BEGINNING] != STRING_DELIM_CHAR) {
        free(token);
        return NoOpenQuoteMark;
    }
    if (token[strlen(token) - 2] != STRING_DELIM_CHAR) {
        free(token);
        return NoEndQuoteMark;
    }
    strtok(token, STRING_DELIM);
    token = strtok(NULL, STRING_DELIM);
    if (token == NULL) {
        free(startPtr);
        return NoErrorsFound;
    }
    if (token[BEGINNING] != NEW_LINE_CHAR) {
        free(startPtr);
        return StringDirectiveHasMoreThenOneArgument;
    }
    free(startPtr);
    return NoErrorsFound;
}

char *get_string_of_directive(const char *line, Bool deleteSpaces) {
    char tmpLine[MAX_LINE_LENGTH], *trimmed, *token, *cleanStr, *result;
    int lengthOfDirective;
    trimmed = trim_label(line);
    if (deleteSpaces) {
        cleanStr = delete_spaces(trimmed);
        strcpy(tmpLine, cleanStr);
        free(cleanStr);
    } else
        strcpy(tmpLine, trimmed);
    free(trimmed);
    lengthOfDirective = (strstr(tmpLine, STRING) != NULL) ? strlen(STRING) : strlen(DATA);
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
    return check_commas_in_data_directive(tmpLine);
}

Error check_comma_between_data_elements(const char *line) {
    Bool isNumberEnded = False, isCommaAppeared = True;
    int i;
    char *strPtr = get_string_of_directive(line, False);
    for (i = 0; i < strlen(strPtr) - 1; ++i) {
        if (isspace(strPtr[i])) {
            isNumberEnded = True;
            continue;
        }
        if (strPtr[i] == COMMA_CHAR) {
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
    char tmpLine[MAX_LINE_LENGTH], *noSpacesLine;
    const char *strPtr;
    int i;
    noSpacesLine = delete_spaces(line);
    strcpy(tmpLine, noSpacesLine);
    strPtr = tmpLine + strlen(DATA);
    for (i = 0; i < strlen(strPtr) - 1; ++i)
        if (!isspace(strPtr[i]) && !is_number(strPtr[i]) && strPtr[i] != COMMA_CHAR && strPtr[i] != MINUS_CHAR &&
            strPtr[i] != PLUS_CHAR) {
            free(noSpacesLine);
            return WrongTypeDataArgument;
        }
    free(noSpacesLine);
    return NoErrorsFound;
}

Error check_commas_in_data_directive(const char *line) {
    /*assumes to get line of data directive without a label*/
    char *strPtr = get_string_of_directive(line, True);
    Error result;
    if (strstr(strPtr, DOUBLE_COMMA) != NULL) {
        free(strPtr);
        return ConsecutiveComma;
    }
    if (strPtr[BEGINNING] == COMMA_CHAR) {
        free(strPtr);
        return CommaAfterDirective;
    }
    if (strPtr[strlen(strPtr) - 2] == COMMA_CHAR) {
        free(strPtr);
        return CommaAfterLast;
    }
    free(strPtr);
    result = check_comma_between_data_elements(line);
    if (result != NoErrorsFound)
        return result;
    return check_arguments_of_data(line);
}
