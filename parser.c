
/*Created by Omri Kaisari on 06/08/2020.*/

#include "parser.h"
#include <string.h>
#include <stdlib.h>

Bool isAlphabetic(char c);

Bool parserIsNewLabel(char *line) {
    if (strchr(line, LABAL_DELIM) == NULL)
        return FALSE;
    return TRUE;
}

Bool parserIsDirective(char *line) {
    if (strchr(line, DIRECTIVE_CHAR) == NULL)
        return FALSE;
    return TRUE;
}


char *parserGetLabel(char *line) {
    char *endLocation = strchr(line, LABAL_DELIM);
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











