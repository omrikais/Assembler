/*Created by Omri Kaisari on 06/08/2020.*/

#ifndef ASSEMBLER_PARSER_H
#define ASSEMBLER_PARSER_H

#include "constants.h"
#include "errors.h"
#include "list.h"

/**
 * @brief gets an input line and checks if it starts with a label
 * @param line
 * @return  True if it has a label of False otherwise
 */
Bool parser_is_new_label(const char *line);

/**
 * @brief gets an input line and returns a string of a label that appears in it
 * @param line
 * @param error     an error pointer to which the functions sends a relevant error code
 * @return          a string of a label that appears in line
 */
char *parser_get_label(const char *line, Error *error);

/**
 * @brief gets an input line and checks if it is a directive line
 * @param line
 * @return      True if it is a directive line, False otherwise
 */
Bool parser_is_directive(char *line);

/**
 * @brief gets a directive input line and returns its directive type. the different directive types are defined
 *          in the constants.h file
 * @param line
 * @return      a directive type with the line's directive
 */
Directive parser_get_directive(char *line);

/**
 * @brief gets an instruction input line and returns its relevant Operation type (which is the opcode).
 *          the Operation type is defined in the constants.h header file
 * @param line
 * @return      an Operation type with operation appears in line
 */
Operation parse_get_operation(const char *line);

/**
 * @brief gets an Operation type and returns the suitable numbers of operands that need to be in a line with this
 *          particular operation
 * @param operation     the operation to check
 * @return              the number of operands that should appear in instruction line with operation
 */
int parser_get_number_of_operands(Operation operation);

/**
 * @brief gets an instruction input line and checks its operands syntax (does it have the correct number of operands,
 *          does it have the correct number of commas etc.)
 * @param line
 * @param numberOfOperands      the numbers of operands that need to be in a correct instruction line with that
 *                              operation
 * @return                      a relevant error code or NoErrorsFound
 */
Error parser_check_operands(const char *line, int numberOfOperands);

/**
 * @brief gets an instruction input line and returns a string of its operand in operandIndex (source or destination).
 * @param line
 * @param operandIndex  should get SOURCE_INDEX or DESTINATION_INDEX as defined in constants.h header file
 * @return              a string with requested operand
 */
char *parser_get_operand(const char *line, int operandIndex);

/**
 * @brief gets a string of an operand and returns its addressing method according to the operand syntax
 * @param operand
 * @return          AddressingMethod type with the addressing method of operand. AddressingMethod type is defined
 *                  in the constants.h header file
 */
AddressingMethod parser_get_addressing_method_of_operand(const char *operand);

/**
 * @brief gets a string directive input line and returns a list with all the chars that construct the string in the
 *          directive line
 * @param line
 * @return a list with all the chars that construct the string in the directive line
 */
List parser_get_string_data(const char *line);

/**
 * @brief   gets a data directive input line and returns a list with all the numbers that construct the data array in
 *          the directive line
 * @param line
 * @return a list with all the numbers that construct the data array in the directive line
 */
List parser_get_data_array(const char *line, Error *error);

/**
 * @brief gets string or data directive element (a list) and returns the size of this element. if is a string element
 *          - the length of the string will be returned; if it is a data element - the length of the numbers array will
 *          be returned.
 * @param element   a pointer to the list that contains the element
 * @param type      the type of element (in terms of its directive type)
 * @return          the size of element
 */
size_t parser_get_size_of_element(void *element, Directive type);

/**
 * @brief gets an input line and checks if it is an empty line
 * @param line
 * @return      True if is an empty line, False otherwise
 */
Bool parser_is_empty_line(const char *line);

/**
 * @brief gets an extern input directive line and returns a string with its argument (e.g the label in it).
 * @param line          an extern input directive line
 * @param result        an Error type pointer in which the function pass an error code if the label isn't valid,
 *                      or if the syntax of the operand isn't correct.
 * @return              a string with the label argument of the extern directive input line
 */
char *parser_get_extern_label(const char *line, Error *result);

/**
 * @brief   gets an operand string with a register addressing method and returns the number of the relevant register.
 *          if the number of the register is not between 0-7 an NA (-1) macro will be returned.
 * @param operand
 * @return  the number of the relevant register or NA (-1)
 */
int parser_get_register_num(const char *operand);

/**
 * @brief           gets an operand string with an immediate addressing method and returns the value of the operand
 *                  as a number (of type long, but the final output value will be of 24 bits)
 * @param operand   an operand string
 * @return          the value of the operand
 */
long parser_get_immediate_operand(const char *operand);

/**
 * @brief           gets an operand string with direct or relative addressing method and returns a string with the
 *                  label that appears in the operand.
 * @param operand   the operand string
 * @return          a string with the label that appears in the operand.
 */
char *parser_get_label_from_operand(const char *operand);

/**
 * @brief       gets an input line and checks whether it is an entry directive line
 * @param line
 * @return      True if it is an entry directive line, False otherwise
 */
Bool parser_is_entry(const char *line);

/**
 * @brief       gets a string directive  input line and checks if it is well built according to the assembly syntax
 * @param line  a string directive input line
 * @return      a relevant error code or NoErrorsFound
 */
Error parser_check_string_directive_form(const char *line);

/**
 * @brief       gets a data directive input line and checks if it is well built according to the assembly syntax
 * @param line  a data directive input line
 * @return      a relevant error code or NoErrorsFound
 */
Error parser_check_data_directive_form(const char *line);

/**
 * @brief       gets an input line and checks if it has only a label without any content in it
 * @param line
 * @return      a relevant error code or NoErrorsFound
 */
Error parser_after_label_check(const char *line);

Bool parser_is_empty_directive(const char *line, Directive directive);

#endif /*ASSEMBLER_PARSER_H*/
