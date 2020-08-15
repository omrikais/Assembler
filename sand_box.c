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

void showbits(long x) {
    int i;
    for (i = (sizeof(char) * 32) - 1; i >= 0; i--) {
        putchar(x & (1u << i) ? '1' : '0');
    }
    printf("\n");
}

void print_int(void *n) {
    printf(" %d", *((int *) n));
}


int main() {
    char *args[] = {"valid.as"};
    long mask = 0;
    mask = ~mask;
    mask <<= 24;
    mask = ~mask;
    showbits(mask);
    assemble(args, 1);
    char str[] = "1";
    printf("%d\n", str[0]);
    return 0;
}

