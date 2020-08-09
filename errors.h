
/*Created by Omri Kaisari on 07/08/2020.*/

enum error_t {
    CommandNotFound,
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
    NoErrorsFound
};

typedef enum error_t Error;


#ifndef ASSEMBLER_ERRORS_H
#define ASSEMBLER_ERRORS_H

#endif /*ASSEMBLER_ERRORS_H*/
