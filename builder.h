/*Created by Omri Kaisari on 09/08/2020.*/
/**********************************************************************************************************************
 ************************************************ The Builder module **************************************************
 **********************************************************************************************************************/
#ifndef ASSEMBLER_BUILDER_H
#define ASSEMBLER_BUILDER_H

#include "code_table.h"
#include "data_table.h"
#include "list.h"
#include "instruction_word.h"
#include "constants.h"
#include "symbol_table.h"
#include "errors.h"

typedef struct builder_t *Builder;      /*the Builder type definition*/

/**
 * @brief initialize a new Builder struct in which all the relevant source code lists will be stored
 * @return
 */
Builder init();

/**
 * @brief           destroys the given Builder iem
 * @param builder
 */
void close(Builder builder);

/**
 * @brief           gets a directive line and analyzes all its relevant data
 * @param builder   the current file builder
 * @param line
 * @return          error code or NoErrorFound
 */
Error evaluate_directive_line(Builder builder, char *line);

/**
 * @brief               gets an directive input line and stored its data in the data items list
 * @param builder       the current file builder
 * @param line
 * @param directive     either Data or String directives
 * @param error         error code or NoErrorFound
 */
void add_data_item_to_table(Builder builder, const char *line, Directive directive, Error *error);

/**
 * @brief           gets an instruction input line, analyzes all its data and converts it to InstructionWord item
 * @param builder   the current file builder
 * @param line
 * @return          error code or NoErrorFound
 */
Error evaluate_code_line(Builder builder, char *line);

/**
 * @brief           gets an input line and determined if it is an empty, comment, instrtuction or directive line and
 *                  then sends it to the relevant evaluate function
 * @param builder   the current file builder
 * @param line
 * @return          error code or NoErrorFound
 */
Error evaluate(Builder builder, char *line);

/**
 * @brief           gets an instruction input line and converts it to an InstructionWord item
 * @param result    an error pointer in which the relevant error will be strored
 * @param line
 * @return          the newly created InstructionWord
 */
InstructionWord fill_instruction_word(Error *result, const char *line);

/**
 * @brief           gets a directive input line and stores all its data in the relevant builder lists
 * @param builder   the current file builder
 * @param line
 * @return          error code or NoErrorFound
 */
Error evaluate_entry_directive(Builder builder, const char *line);

/**
 * @brief           updated the symbols table ofter the first pass competion
 * @param builder   the current file builder
 */
void builder_update_data_symbols_location(Builder builder);

/**
 * @brief           returns the instructions list of the builder
 * @param builder   the current file builder
 * @return          the instructions list of the builder
 */
InstructionsList builder_get_instructions_list(Builder builder);

/**
 * @brief           updates the given instruction after the first pass
 * @param word      the instruction word to be updated
 * @param builder   the current file builder
 * @param error     error code or NoErrorFound
 */
void builder_update_instruction(InstructionWord word, Builder builder, Error *error);

/**
 * @brief           returns the data items list of builder
 * @param builder   the current file builder
 * @return          the data items list of the given builder
 */
DataItemsList builder_get_data_items_list(Builder builder);

/**
 * @brief           returns the given builder symbols list
 * @param builder   the current file builder
 * @return          the given builder symbols list
 */
List builder_get_symbols_list(Builder builder);

#endif /*ASSEMBLER_BUILDER_H*/
