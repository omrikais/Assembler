#include <stdio.h>
#include "errors.h"
#include "constants.h"

/*all the errors massages, the massages ordered as they appears in the enum */
#define ERRORS_SENTENCES "The specified command doesn't exists",\
"File type is not .as, please provide .as file","File doesn't exit","No Files were given as command line arguments",\
"The operation in this line has too many operands","The operation in this line has too few operands","The specified \
directive is not define","The label in this line isn't valid, it doesn't starts with an alphabetic character.",\
"The label in this line isn't valid, it consists more then 31 characters.",\
"The label in this line isn't valid, it contains non alphanumeric characters.","This line has too many commas","This line has missing comma","The extern directive\
in this line has too many operands. Should be only one.","This line has consecutive commas","The label of the directive\
 is missing","The label in this line already exist. Please choose another label.","There is not matching label for this\
 entry directive line","","","","This extern directive line has label that is already defined locally in the file",\
"An opening quotation mark is missing","An ending quotation mark is missing","String Directive should have only one\
 valid string as an argument", "The argument of the string directive has no quotation marks","A comma comes immediately\
 after a directive or operation","This line has data directive with a comma after the last element","This directive \
line has a wrong type of data element","One of the operands has incompatible addressing method with the operation",\
"A label without content is not valid","One of this line operands has undefined addressing method","Wrong type of \
immediate operand","There is invalid element in this line data array","Label name cannot be an operation name",\
"Label name cannot be a reference to a valid register","Directive declared without any parameters","The label in this \
extern directive line already exists as local label","The number width in this directive line is bigger than 24 bit",\
"The number width in immediate addressing line is bigger than 21 bit","At least one argument should be given"

/************************************************** Functions implementations *****************************************/

void error_print(Error error, int lineNumber, const char *fileName) {
    char *errorsSentences[] = {ERRORS_SENTENCES};
    char toPrint[MAX_LINE_LENGTH];
    if (lineNumber > 0)
        sprintf(toPrint, "Error in file: %s, at line %d: %s\n", fileName, lineNumber, errorsSentences[error]);
    if (lineNumber == NO_LINE)
        sprintf(toPrint, "Error in file %s: %s\n", fileName, errorsSentences[error]);
    if (lineNumber == NO_FILE)
        sprintf(toPrint, "%s\n", errorsSentences[error]);
    fprintf(stderr, "%s", toPrint);
}
