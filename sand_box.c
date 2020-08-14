/*Created by Omri Kaisari on 13/08/2020.*/
#include <stdio.h>
#include <limits.h>
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
#include "file_generator.h"

void print_int(void *n) {
    printf(" %d", *((int *) n));
}


int main() {
    char *args[] = {"valid.as"};
    assemble(args, 1);
    char str[] = "1";
    printf("%d\n", str[0]);
    return 0;
}

