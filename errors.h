/**********************************************************************************************************************
 ************************************************ The errors module ***************************************************
 **********************************************************************************************************************/

#ifndef ASSEMBLER_ERRORS_H
#define ASSEMBLER_ERRORS_H

enum error_t {
    CommandNotFound,                        /*the command doesn't exist*/
    FileTypeWrong,                          /*the file extension is wrong*/
    FileNotExist,                           /*the file isn't exists*/
    NoFiles,                                /*the reading process ended*/
    TooManyOperands,                        /*the line has too many operands*/
    TooFewOperands,                         /*the line has too few operands*/
    DirectiveNotFound,                      /*the directive doesn't exist*/
    LabelNoAlphabeticStart,                 /*the label starts with a0 char that is not numeric*/
    LabelTooLong,                           /*the label is more then the allowed length*/
    LabelWithNonAlphanumeric,               /*the label contains a char that is not alphabetic*/
    IllegalComma,                           /*the line has an illegal comma in it*/
    MissingComma,                           /*the line has missing comma*/
    TooManyParametersOfExtern,              /*the extern directive has too many operands in it*/
    ConsecutiveComma,                       /*the line contains consecutive commas*/
    MissingLabel,                           /*the directive lacks label operand*/
    LabelAlreadyExists,                     /*the label was already defined earlier*/
    EntryLabelNotExists,                    /*the entry label doesn't exits*/
    NoErrorsFound,                          /*there are no errors*/
    NoMoreFiles,                            /*there are no more file to read*/
    NoEntries,                              /*there are no entries in the program*/
    TheExternOperandIsAlreadyDefined,       /*the extern operand is already defined*/
    NoOpenQuoteMark,                        /*there isn't open quotation mark*/
    NoEndQuoteMark,                         /*there isn't ending quotation mark*/
    StringDirectiveHasMoreThenOneArgument,  /*the string directive line has more than one string in it*/
    StringWithoutQuotes,                    /*the string lacks quotes*/
    CommaAfterDirective,                    /*there is a comma after directive declaration*/
    CommaAfterLast,                         /*there is comma after the last element in the line*/
    WrongTypeDataArgument,                  /*the type of the element is wrong*/
    IncompatibleAddressing,                 /*the addressing method of the operand contradicts the opcode*/
    OnlyLabel,                              /*there is in the line a label without content*/
    InvalidAddressingMethod,                /*the addressing method undefined*/
    WrongImmediateOperand,                  /*the operand is not valid*/
    BadDataElement,                         /*the data element is undefined*/
    LabelBadNameOperation,                  /*the operand has label that isn't valid*/
    LabelBadNameRegister,                   /*the operand has a register name that isn't valid*/
    EmptyDirective,                         /*the directive line has declaration without content*/
    DirectiveLabelAlreadyExistsAsCode,      /*the label of an extern already defined as local*/
    OverflowDirective,                      /*the directive has an element that overflows*/
    OverflowInstruction                     /*the instruction has an element that overflows*/
};

typedef enum error_t Error;         /*Error type definition*/

/**
 * @brief               prints an error to the stderr
 * @param error         the error to print
 * @param lineNumber    the number where the error occurs
 * @param fileName      the file where the error occurd
 */
void error_print(Error error, int lineNumber, const char *fileName);

#endif /*ASSEMBLER_ERRORS_H*/
