
/*Created by Omri Kaisari on 08/08/2020.*/

#include "code_table.h"

/**
 * @brief   the code list struct stored all the instuction word of a give source code assembly file.
 *          the list is implemented as a simple one direction linked list
 */
struct code_list_t {
    List instructions;              /*a linked list of InstructionWord elements*/
    int ic;                         /*The current IC, i.e. the last IC after adding the last word*/
    int numberOfInstructions;       /*the total number of instructions word*/
};

/************************************************** Functions implementations *****************************************/

InstructionsList instruction_list_create() {
    InstructionsList instructions = malloc(sizeof(struct code_list_t));
    instructions->instructions = list_create();
    instructions->ic = BEGIN_ADDRESS;
    instructions->numberOfInstructions = 0;
    return instructions;
}

int instruction_list_get_number_of_instructions(InstructionsList instructions) {
    return instructions->numberOfInstructions;
}


int instruction_list_get_ic(InstructionsList instructions) {
    return instructions->ic;
}

void instruction_list_add_instruction(InstructionsList instructions, InstructionWord word) {
    /*assumes that word is a valid instruction word with all its elements*/
    list_insert_node_at_end(instructions->instructions, word, instruction_word_get_size());
    ++(instructions->numberOfInstructions);
    (instructions->ic) += instruction_word_get_number_of_words(word);
}

void instruction_list_destroy(InstructionsList instructions) {
    list_destroy(instructions->instructions, (DestroyFunction) instruction_word_destroy);
    free(instructions);
}

InstructionWord instruction_list_get_instruction(InstructionsList instructions, int i) {
    return (InstructionWord) list_get_data_element_at_index(instructions->instructions, i);
}












