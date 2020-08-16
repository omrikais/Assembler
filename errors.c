
/*Created by Omri Kaisari on 07/08/2020.*/

#include "errors.h"
#include "constants.h"
#include <stdio.h>

#define ERRORS_SENTENCES "The specified command doesn't exists",\
"File type is not .as, please provide .as file","File doesn't exits","No Files were given as command line arguments",\
"The operation in this line has too many operands","The operation in this line has too many operands","The specified \
directive is not define","The label in this line isn't valid. Label should start with alphabetic symbol and consists\
up to 32 alphanumeric charectars","This line has too many commas","This line has missing comma","The extern directive\
in this line has too many operands. Should be only one.","This line has consecutive commas","The label of the directive\
 is missing","The label in this line already exist. Please choose another label.","There is not matching label for this\
entry directive line","","","","","This extern directive line has label that is already defined locally in the file",\
"An opening quotation mark is missing","An ending quotation mark is missing","String Directive should have only one\
 valid string as an argument", "The argument of the string directive has no quotation marks"

void error_print(Error error, int lineNumber) {
    char *errorsSentences[] = {ERRORS_SENTENCES};
    char toPrint[MAX_LINE_LENGTH];
    sprintf(toPrint, "Error in line %d: %s\n", lineNumber, errorsSentences[error]);
    fprintf(stderr, toPrint);
}


