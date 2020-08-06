
/*Created by Omri Kaisari on 06/08/2020.*/


#ifndef ASSEMBLER_PARSER_H
#define ASSEMBLER_PARSER_H

#include "constants.h"

Bool parserIsNewLabel(char *line);

char *parserGetLabel(char *line);

Bool parserIsDirective(char *line);

Directive parserGetDirective(char *line);

Operation parseGetOperation(char *line);

int parserGetNumberOfOperands(Operation operation);

#endif /*ASSEMBLER_PARSER_H*/


