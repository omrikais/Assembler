/**********************************************************************************************************************
 ************************************************ The constants header ************************************************
 **********************************************************************************************************************/

#ifndef ASSEMBLER_CONSTANTS_H
#define ASSEMBLER_CONSTANTS_H

/**
 * @brief this file includes all the relevant macros and enum types that are used in the assembly program
 */


/*all the commands strings*/
#define FUNCTIONS "mov","cmp","add","sub","lea","clr","not","inc","dec","jmp","bne","jsr","red","prn","rts","stop"
/*the opcodes of the commands in the same order of the functions macro; the second number is the function number
 * if it is the case of an command that has function number */
#define FUNCTIONS_NUMBERS 0,1,21,22,4,51,52,53,54,91,92,93,12,13,14,15
/*the number of operands allowed to each command at the same order of the functions macro*/
#define NUMBER_OF_OPERANDS 2,2,2,2,2,1,1,1,1,1,1,1,1,1,0,0
/*the total number of commands*/
#define NUMBER_OF_FUNCTIONS 16
/*to total number of directives*/
#define NUMBER_OF_DIRECTIVE 4
/*the first address of the program*/
#define BEGIN_ADDRESS 100
/*the strings of the allowed directives at the assembly language*/
#define DIRECTIVES "data","string","entry","extern"
/*an error code for int return type functions*/
#define NA (-1)
/*an error code for long int return type function*/
#define NA_NUMBER 67108864
/*the maximal number that can be stored in a 24 bits*/
#define MAX_24_BIT_NUMBER 8388607
/*the maximal number that can be stored in a 21 bits*/
#define MAX_21_BIT_NUMBER 1048575
/*the max length of a line in a source assembly code file */
#define MAX_LENGTH 82
/*how relevant parameters has an instruction word in terms of printing*/
#define WORD_PARAMETERS 6
/*the label delimiter character*/
#define LABEL_DELIM_CHAR ':'
/*the label delimiter string*/
#define LABEL_DELIM ":"
/*white delimiters within a line*/
#define WHITE_DELIMITERS " \t"
/*the new line string*/
#define NEW_LINE_DELIM "\n"
/*the new line character*/
#define NEW_LINE_CHAR '\n'
/*the directive delimiter string*/
#define DIRECTIVE_DELIM "."
/*the directive delimiter character*/
#define DIRECTIVE_CHAR '.'
/*the comma character*/
#define COMMA_CHAR ','
/*a double comma string*/
#define DOUBLE_COMMA ",,"
/*the immediate addressing method symbol*/
#define IMMEDIATE_ADDRESSING_SYMBOL '#'
/*the relative addressing method symbol*/
#define RELATIVE_ADDRESSING_SYMBOL '&'
/*the register character*/
#define REGISTER_CHAR 'r'
/*the string delimiter string*/
#define STRING_DELIM "\""
/*the string delimiter character*/
#define STRING_DELIM_CHAR '\"'
/*the length of a file extension string*/
#define ENDING_LENGTH 3
/*the extension of an assembly source code file*/
#define ASSEMBLER_FILE_EXTENSION ".as"
/*the extension of an assembly object file*/
#define OBJECT_FILE_EXTENSION ".ob"
/*the extension of an assembly entry  file*/
#define ENTRY_FILE_EXTENSION ".ent"
/*the extension of an assembly extern  file*/
#define EXTERN_FILE_EXTENSION ".ext"
/*the source operand index*/
#define SOURCE_INDEX   1
/*the destination operand index*/
#define DESTINATION_INDEX   2
/*the maximum length of an input line for internal purposes*/
#define MAX_LINE_LENGTH 255
/*the first file index in a program arguments array*/
#define FIRST_FILE_INDEX 1
/*the first element index in a linked list*/
#define FIRST_ELEMENT 1
/*an opcode with no operands*/
#define NO_OPERANDS 0
/*an opcode with one operand*/
#define ONE_OPERAND 1
/*an opcode with two operands*/
#define TWO_OPERANDS 2
/*all the white delimiters*/
#define WHITE_DELIM_WITH_NEW_LINE " \t\n"
/*all the delimiters within directive line*/
#define DIRECTIVE_DELIMITERS ". \n\t"
/*the entry directive string*/
#define ENTRY ".entry"
/*the data directive string*/
#define DATA ".data"
/*the string directive string*/
#define STRING ".string"
/*all the characters that are ignorable in a source code line*/
#define IGNORED_DELIM "\n: \t"
/*all the characters that are ignorable in a directive line*/
#define IGNORED "., \n\t"
/*all the delimiters in a line that contains a label*/
#define LABEL_LINE_DELIMITERS ":, \n"
/*all the delimiters in an instruction line*/
#define INSTRUCTION_LINE_DELIMITERS " \n\t,"
/*all the delimiters within a directive line*/
#define IGNORED_WHITE ", \t"
/*the string end character in a chars array*/
#define STRING_END '\0'
/*the plus character*/
#define PLUS_CHAR '+'
/*the minus character*/
#define MINUS_CHAR '-'
/*the default beginning index*/
#define BEGINNING 0
/*hte maximal label length*/
#define MAX_LABEL_LENGTH 31
/*the minimum register number*/
#define MINIMAL_REGISTER 0
/*the maximum register number*/
#define MAXIMAL_REGISTER 7
/*the minimum register number character*/
#define MINIMAL_REGISTER_CHAR '0'
/*the maximum register number character*/
#define MAXIMAL_REGISTER_CHAR '7'
/*the maximal length of an register addressing method string*/
#define MAX_REGISTER_OPERAND_STR_LENGTH 2
/*the position to which the opcode needs to shift bitwise*/
#define OPCODE_SHIFT 18
/*the position to which the source addressing method needs to shift bitwise*/
#define SOURCE_METHOD_SHIFT 16
/*the position to which the source register needs to shift bitwise*/
#define SOURCE_REGISTER_SHIFT 13
/*the position to which the destination addressing method needs to shift bitwise*/
#define DESTINATION_METHOD_SHIFT 11
/*the position to which the destination register needs to shift bitwise*/
#define DESTINATION_REGISTER_SHIFT 8
/*the position to which the function code needs to shift bitwise*/
#define FUNC_SHIFT 3
/*the value of the ARE field in an instruction word*/
#define INSTRUCTION_ARE_VALUE 4
/*the value of the ARE field in a direct addressing operand*/
#define DIRECT_ARE 2
/*the value of the ARE field in a relative addressing operand*/
#define RELATIVE_ARE 4
/*the commant delimiter*/
#define COMMENT_DELIMITER ';'
/*the word width in the assembly language*/
#define WORD_WIDTH 24
/*no line is needed in the print*/
#define NO_LINE (-1)
#define NO_FILE (-5)

/**
 * @brief the boolean type
 */
enum boolean {
    False = 0, True = 1
};

typedef enum boolean Bool;

/**
 * @brief the addressing method type
 */
enum addressing {
    Immediate = 0, Direct = 1, Relative = 2, Register = 3
};

/**
 * @brief enum of the parameters array for printing purposes
 */
enum parameters_array_index {
    opcode = 0, sourceAddressingMethod, sourceRegister, destinationAddressingMethod, destinationRegister, func
};

/**
 * @brief the directive type
 */
enum directive {
    Data = 0, String, Entry, Extern, NoDirectiveFound
};

/**
 * @brief the  operations type
 */
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
