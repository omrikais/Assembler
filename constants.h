
/* Created by Omri Kaisari on 06/08/2020.*/

#ifndef ASSEMBLER_CONSTANTS_H
#define ASSEMBLER_CONSTANTS_H

#define FUNCTIONS "mov","cmp","add","sub","lea","clr","not","inc","dec","jmp","bne","jsr","red","prn","rts","stop"
#define FUNCTIONS_NUMBERS 0,1,21,22,4,51,52,53,54,91,92,93,12,13,14,15
#define NUMBER_OF_OPERANDS 2,2,2,2,2,1,1,1,1,1,1,1,1,1,0,0
#define NUMBER_OF_FUNCTIONS 16
#define NUMBER_OF_DIRECTIVE 4
#define BEGIN_ADDRESS 100
#define DIRECTIVES "data","string","entry","extern"
#define NA (-1)
#define MAX_LENGTH 82
#define WORD_PARAMETERS 6
#define LABEL_DELIM_CHAR ':'
#define LABEL_DELIM ":"
#define WHITE_DELIMITERS " \t"
#define NEW_LINE_DELIM "\n"
#define NEW_LINE_CHAR '\n'
#define DIRECTIVE_DELIM "."
#define DIRECTIVE_CHAR '.'
#define SPACE_DELIM " "
#define COMMA_CHAR ','
#define DOUBLE_COMMA ",,"
#define IMMEDIATE_ADDRESSING_SYMBOL '#'
#define RELATIVE_ADDRESSING_SYMBOL '&'
#define REGISTER_CHAR 'r'
#define STRING_DELIM "\""
#define STRING_DELIM_CHAR '\"'
#define ENDING_LENGTH 3
#define ASSEMBLER_FILE_EXTENSION ".as"
#define OBJECT_FILE_EXTENSION ".ob"
#define ENTRY_FILE_EXTENSION ".ent"
#define EXTERN_FILE_EXTENSION ".ext"
#define SOURCE_INDEX   1
#define DESTINATION_INDEX   2
#define MAX_LINE_LENGTH 255
#define FIRST_FILE_INDEX 1
#define FIRST_ELEMENT 1
#define NO_OPERANDS 0
#define ONE_OPERAND 1
#define TWO_OPERANDS 2
#define WHITE_DELIM_WITH_NEW_LINE " \t\n"
#define DIRECTIVE_DELIMITERS ". \n\t"
#define ENTRY ".entry"
#define DATA ".data"
#define STRING ".string"
#define IGNORED_DELIM "\n: \t"
#define IGNORED "., \n\t"
#define LABEL_LINE_DELIMITERS ":, \n"
#define INSTRUCTION_LINE_DELIMITERS " \n\t,"
#define IGNORED_WHITE ", \t"
#define STRING_END '\0'
#define PLUS_CHAR '+'
#define MINUS_CHAR '-'
#define BEGINNING 0
#define MAX_LABEL_LENGTH 31
#define MINIMAL_REGISTER 0
#define MAXIMAL_REGISTER 7
#define MAX_REGISTER_OPERAND_STR_LENGTH 2
#define OPCODE_SHIFT 18
#define SOURCE_METHOD_SHIFT 16
#define SOURCE_REGISTER_SHIFT 13
#define DESTINATION_METHOD_SHIFT 11
#define DESTINATION_REGISTER_SHIFT 8
#define FUNC_SHIFT 3
#define INSTRUCTION_ARE_VALUE 4
#define COMMENT_DELIMITER ';'


enum boolean {
    False = 0, True = 1
};

typedef enum boolean Bool;

enum addressing {
    Immediate = 0, Direct = 1, Relative = 2, Register = 3
};

enum parameters_array_index {
    opcode = 0, sourceAddressingMethod, sourceRegister, destinationAddressingMethod, destinationRegister, func
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
    ONE_OPERAND_OPERATION = 9,
    JMP = 91,
    BNE = 92,
    JSR = 93,
    RED = 12,
    PRN = 13,
    RTS = 14,
    STOP = 15,
    NO_FUNCTION_OPERATIONS = 19,
    OPERATION_UNIT = 10,
    OperationNotFound
};


typedef enum addressing AddressingMethod;

typedef enum directive Directive;

typedef enum operations Operation;


#endif /*ASSEMBLER_CONSTANTS_H*/
