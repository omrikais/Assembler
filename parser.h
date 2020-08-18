
/*Created by Omri Kaisari on 06/08/2020.*/


#ifndef ASSEMBLER_PARSER_H
#define ASSEMBLER_PARSER_H

#include "constants.h"
#include "errors.h"
#include "list.h"


Bool parser_is_new_label(const char *line);

char *parser_get_label(char *line, Error *error);

Bool parser_is_directive(char *line);

Directive parser_get_directive(char *line);

Operation parse_get_operation(const char *line);

int parser_get_number_of_operands(Operation operation);

Error parser_check_operands(const char *line, int numberOfOperands);

char *parser_get_operand(const char *line, int operandIndex);

AddressingMethod parser_get_addressing_method_of_operand(const char *operand);

List parser_get_string_data(const char *line);

List parser_get_data_array(const char *line);

size_t parser_get_size_of_element(void *element, Directive type);

Bool parser_is_empty_line(const char *line);

char *parser_get_extern_label(const char *line, Error *result);

int parser_get_register_num(const char *operand);

long parser_get_immediate_operand(const char *operand);

char *parser_get_label_from_operand(const char *operand);

Bool parser_is_entry(const char *line);

Error parser_check_string_directive_form(const char *line);

Error parser_check_data_directive_form(const char *line);

Error parser_check_commas_in_data_directive(const char *line);

Error parser_is_valid_label(const char *label);

#endif /*ASSEMBLER_PARSER_H*/


