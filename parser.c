
/*Created by Omri Kaisari on 06/08/2020.*/

#include "parser.h"
#include <string.h>
#include <stdlib.h>


Bool parserIsNewLabel(char *line) {
    if (strchr(line, LABAL_DELIM) == NULL)
        return FALSE;
    return TRUE;
}

char *parserGetLabel(char *line) {
    char *endLocation = strchr(line, LABAL_DELIM);
    char *label = malloc(sizeof(*label) * (endLocation - line));
    memcpy(label, line, endLocation - line);
    return label;
    
}






