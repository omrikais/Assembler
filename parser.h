
/*Created by Omri Kaisari on 06/08/2020.*/


#ifndef ASSEMBLER_PARSER_H
#define ASSEMBLER_PARSER_H

#include "constants.h"
#include "errors.h"
#include "list.h"


Bool parserIsNewLabel(char *line);

char *parserGetLabel(char *line);

Bool parserIsDirective(char *line);

Directive parserGetDirective(char *line);

Operation parseGetOperation(char *line);

int parserGetNumberOfOperands(Operation operation);

Error parserCheckOperands(const char *line, int numberOfOperands);

char *parserGetOperand(const char *line, int operandIndex);

AddressingMethod parserGetAddressingMethodOfOperand(const char *operand);

char *parserGetStingData(const char *line);

List parserGetDataArray(const char *line);

#endif /*ASSEMBLER_PARSER_H*/


