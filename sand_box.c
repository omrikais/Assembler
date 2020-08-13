/*Created by Omri Kaisari on 13/08/2020.*/
#include <stdio.h>
#include <string.h>
#include "list.h"
#include "parser.h"
#include "instruction_word.h"
#include "code_table.h"
#include "data_table.h"
#include "symbol_table.h"
#include "printer.h"
#include "builder.h"
#include "reader.h"

void print_int(void *n) {
    printf(" %d", *((int *) n));
}


int main() {
    InstructionWord word = instruction_word_create(12, 4, 1, 2, 3, 2, 3, 2);
    print_instruction_word(word, stdout);
    return 0;
}

