
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

typedef enum addressing AddressingMethod;

#define FUNCTIONS "mov","cmp","add","sub","lea","clr","not","inc","dec","jmp","bne","jsr","red","prn","rts","stop"

#define NA -1

#define MAX_LENGTH 82

#define LABAL_DELIM ':'

#endif /*ASSEMBLER_CONSTANTS_H*/
