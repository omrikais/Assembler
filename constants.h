
/* Created by Omri Kaisari on 06/08/2020.*/

#ifndef ASSEMBLER_CONSTANTS_H
#define ASSEMBLER_CONSTANTS_H
#define FUNCTIONS "mov","cmp","add","sub","lea","clr","not","inc","dec","jmp","bne","jsr","red","prn","rts","stop"
#define FUNCTIONS_NUMBERS 0,1,21,22,4,51,52,53,54,91,92,93,12,13,14,15
#define NUMBER_OF_OPERANDS 2,2,2,2,1,1,1,1,1,1,1,1,1,1,0,0
#define NUMBER_OF_FUNCTIONS 16
#define BEGIN_ADDRESS 100
#define DIRECTIVES "Data","string","entry","extern"
#define NA (-1)
#define MAX_LENGTH 82
#define LABEL_DELIM_CHAR ':'
#define LABEL_DELIM ":"
#define WHITE_DELIMITERS " \t"
#define NEW_LINE_DELIM "\n"
#define DIRECTIVE_DELIM "."
#define DIRECTIVE_CHAR '.'
#define SPACE_DELIM " "
#define COMMA_CHAR ','
#define IMMEDIATE_ADDRESSING_SYMBOL '#'
#define RELATIVE_ADDRESSING_SYMBOL '&'
#define REGISTER_CHAR 'r'
#define STRING_DELIM "\""


enum boolean {
    False, True
};

typedef enum boolean Bool;

enum addressing {
    Immediate = 0, Direct = 1, Relative = 2, Register = 3
};

enum directive {
    Data = 0, String, Entry, Extern, NoDirectiveFound
};

enum operations {
    MOV = 0,
    CMP = 1,
    ADD = 21,
    SUB = 22,
    LEA = 4,
    CLR = 51,
    NOT = 52,
    INC = 53,
    DEC = 54,
    JMP = 91,
    BNE = 92,
    JSR = 93,
    RED = 12,
    PRN = 13,
    RTS = 14,
    STOP = 15,
    OperationNotFound
};

typedef enum addressing AddressingMethod;

typedef enum directive Directive;

typedef enum operations Operation;


#endif /*ASSEMBLER_CONSTANTS_H*/
