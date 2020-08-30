/**********************************************************************************************************************
 ************************************************ The instruction word module ******************************************
 **********************************************************************************************************************/

#ifndef ASSEMBLER_INSTRUCTION_WORD_H
#define ASSEMBLER_INSTRUCTION_WORD_H

#include "constants.h"

typedef struct instruction_word_t *InstructionWord;     /*the InstructionWord type definition*/

/**
 * @brief                                   creates a new InstructionWord allocates and allocates its memory
 * @param opcode                            the opcode of the word
 * @param func                              the function code' if relevant
 * @param sourceAddressingMethod            the source addressing method
 * @param sourceRegister                    the source register, if relevant
 * @param destinationAddressingMethod       the destination addressing method
 * @param destinationRegister               the destination register, if relevant
 * @param sourceOperandContent              the content (as long int) of the word source operand
 * @param destinationOperandContent         the content (as long int) of the word destination operand
 * @return                                  the newly created word
 */
InstructionWord instruction_word_create(int opcode, int func, int sourceAddressingMethod, int sourceRegister,
                                        int destinationAddressingMethod, int destinationRegister,
                                        long sourceOperandContent, long destinationOperandContent);

/**
 * @brief       deallocates the given instruction word
 * @param word
 */
void instruction_word_destroy(InstructionWord word);

/**
 * @brief           determines the number of words (instruction word and operands) that the current instruction will
 *                  be needed
 * @param word      the word to determine its number of words
 * @return          the value of the words' number
 */
unsigned int instruction_word_determine_number_of_words(InstructionWord word);

/**
 * @brief               sets the value of the IC of the word
 * @param word
 * @param valueOfIc     the value of the IC of the word to set
 */
void instruction_word_set_ic(InstructionWord word, int valueOfIc);

/**
 * @brief       returns the number of word of the instruction
 * @param word
 * @return      the number of word of the instruction
 */
int instruction_word_get_number_of_words(InstructionWord word);

/**
 * @brief           sets the destination string of the destination operand
 * @param word
 * @param string    the string to copy to the operand
 */
void instruction_word_set_destination_string(InstructionWord word, const char *string);

/**
 * @brief           sets the source string of the destination operand
 * @param word
 * @param string    the string to copy to the operand
 */
void instruction_word_set_source_string(InstructionWord word, const char *string);

/**
 * @brief                   sets the operand content field
 * @param word
 * @param address           the address to be copied to the operand
 * @param operandIndex      either SOURCE_INDEX or DESTINATION_INDEX
 */
void instruction_word_set_operand_content(InstructionWord word, int address, int operandIndex);

/**
 * @brief       returns the destination string field content
 * @param word
 * @return      the destination string field content
 */
const char *instruction_word_get_destination_string(InstructionWord word);

/**
 * @brief       returns the IC of the word
 * @param word
 * @return      the IC of the word
 */
int instruction_word_get_ic(InstructionWord word);

/**
 * @brief       returns the source string field content
 * @param word
 * @return      the source string field content
 */
const char *instruction_word_get_source_string(InstructionWord word);

/**
 * @brief                   returns the addressing method of the suitable operand
 * @param word
 * @param operandIndex      either SOURCE_INDEX or DESTINATION_INDEX
 * @return                  the addressing method of the suitable operand
 */
int instruction_word_get_addressing_method(InstructionWord word, int operandIndex);

/**
 * @brief           returns an array with all the needed parameters for printing
 * @param word
 * @return         an array with all the needed parameters for printing
 */
long *instruction_word_get_all_parameters(InstructionWord word);

/**
 * @brief           deallocated only the word struct but not its content
 * @param word      the word to destroy
 */
void instruction_word_destroy_tmp(InstructionWord word);

/**
 * @brief                   returns the content of the given operand
 * @param word
 * @param operandIndex      either SOURCE_INDEX or DESTINATION_INDEX
 * @return                  the content of the given operand
 */
long instruction_word_get_operand_content(InstructionWord word, int operandIndex);

/**
 * @brief   returns the size of an instruction_word_t struct
 * @return
 */
size_t instruction_word_get_size();

/**
 * @brief                   sets the is_extern field of a word to True
 * @param word
 * @param operandIndex      either SOURCE_INDEX or DESTINATION_INDEX
 */
void instruction_word_set_is_extern(InstructionWord word, int operandIndex);

/**
 * @brief               returns True if the given operand is external
 * @param word
 * @param operandIndex  either SOURCE_INDEX or DESTINATION_INDEX
 * @return              True if the given operand is external
 */
Bool instruction_word_is_operand_external(InstructionWord word, int operandIndex);

/**
 * @brief                   returns True if the given operation has operand (1 or more)
 * @param operation         the operation code
 * @param operandIndex      either SOURCE_INDEX or DESTINATION_INDEX
 * @return                  True if the given operation has operand (1 or more)
 */
Bool instruction_word_has_operand(Operation operation, int operandIndex);

/**
 * @brief                   returns True if the given word has operands (1 or more)
 * @param word
 * @param operandIndex      either SOURCE_INDEX or DESTINATION_INDEX
 * @return                  True if the given word has operands (1 or more)
 */
Bool has_operand(InstructionWord word, int operandIndex);

/**
 * @brief           returns the opcode field content wo the given word
 * @param word
 * @return          the opcode field content wo the given word
 */
int instruction_word_get_opcode(InstructionWord word);

#endif /*ASSEMBLER_INSTRUCTION_WORD_H*/
