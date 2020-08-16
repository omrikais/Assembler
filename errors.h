
/*Created by Omri Kaisari on 07/08/2020.*/




#ifndef ASSEMBLER_ERRORS_H
#define ASSEMBLER_ERRORS_H

enum error_t {
    CommandNotFound,
    FileTypeWrong,
    FileNotExist,
    NoFiles,
    TooManyOperands,
    TooFewOperands,
    DirectiveNotFound,
    IllegalLabel,
    IllegalComma,
    MissingComma,
    TooManyParametersOfExtern,
    ConsecutiveComma,
    MissingLabel,
    LabelAlreadyExists,
    EntryLabelNotExists,
    NoErrorsFound,
    NoMoreFiles,
    NoEntries,
    ExternOrInternLabelNotFound
};

typedef enum error_t Error;

void error_print(Error error, int lineNumber);

#endif /*ASSEMBLER_ERRORS_H*/
