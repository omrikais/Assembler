
/* Created by Omri Kaisari on 06/08/2020.*/

#ifndef ASSEMBLER_CONSTANTS_H
#define ASSEMBLER_CONSTANTS_H

enum boolean {
    FALSE, TRUE
};

typedef enum boolean Bool;

enum addressing {
    IMMEDIATE = 0, DIRECT = 1, RELATIVE = 2, REGISTER = 3
};

enum directive {
    DATA = 0, STRING, ENTRY, EXTERN, NO_DIRECTIVE_FOUND
};

typedef enum addressing AddressingMethod;

typedef enum directive Directive;

#define FUNCTIONS "mov","cmp","add","sub","lea","clr","not","inc","dec","jmp","bne","jsr","red","prn","rts","stop"
#define DIRECTIVES "data","string","entry","extern"
#define NA -1
#define MAX_LENGTH 82
#define LABAL_DELIM ':'
#define WHITH_DELIMITERS " \t"
#define DIRECTIVE_DELIM "."
#define DIRECTIVE_CHAR '.'

#endif /*ASSEMBLER_CONSTANTS_H*/
