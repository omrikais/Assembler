/*Created by Omri Kaisari on 12/08/2020.*/

#include "printer.h"
#include <string.h>
#include <stdlib.h>

void showbits(unsigned int x) {
    int i;
    for (i = (sizeof(char) * 23) - 1; i >= 0; i--) {
        putchar(x & (1u << i) ? '1' : '0');
    }
    printf("\n");
}

void print_instruction_word(InstructionWord word, FILE *output) {
    int *parameters = instruction_word_get_all_parameters(word);
    int instruction = 0, i, j;
    instruction += parameters[0];
    instruction <<= 17;
    instruction += (parameters[1] << 15);
    instruction += (parameters[2] << 12);
    instruction += (parameters[3] << 10);
    instruction += (parameters[4] << 7);
    instruction += (parameters[5] << 2);
    instruction += 4;
    free(parameters);
    /*showbits(instruction);*/
    printf("%x", instruction);//need to change that - print a string to output
}

void print_operand(InstructionWord word, int operandIndex) {

}





