#include <stdio.h>
#include <string.h>
#include "list.h"
#include "parser.h"
#include "instruction_word.h"
#include "code_table.h"
#include "data_table.h"
#include "symbol_table.h"
#include "builder.h"

void print_int(void *n) {
    printf(" %d", *((int *) n));
}

void print_float(void *f) {
    printf(" %f", *(float *) f);
}

int main() {
    Builder builder = init();
    char line[] = "   Hello:      .data 1,2,3,4,5";
    char line2[] = "              Hello: .data 2,4";
    char line3[] = "   Ho: .string \"My name is Omri\"";
    char line4[] = "   .extern Hello";
    char line5[] = "    HoHo: add &kklkl,         Hi      \n";
    char line6[] = "X: .string \"Hello, World! *()\"";
    char line7[] = "label00: .data -1, 1, -2, 78, 90, 45328, -95743";
    char line8[] = "mov #0, label00";
    char line9[] = "mov #-1, r0";
    char line10[] = "cmp #-1, r0";
    char line11[] = "add #3957, label00";
    char line12[] = "sub fasdiu3245dghfgshdsf78dhkj12345, label11";
    char line13[] = "not X";
    char line14[] = "C0: jmp label00";
    char line15[] = "rts";
    char line16[] = "label01: .data -000000, +000000, +000001, -000004";
    InstructionWord word = NULL;
    Error error6 = evaluate(builder, line6);
    Error error7 = evaluate(builder, line7);
    Error error8 = evaluate(builder, line8);
    Error error9 = evaluate(builder, line9);
    Error error10 = evaluate(builder, line10);
    Error error11 = evaluate(builder, line11);
    Error error12 = evaluate(builder, line12);
    Error error13 = evaluate(builder, line13);
    Error error14 = evaluate(builder, line14);
    Error error15 = evaluate(builder, line15);
    Error error16 = evaluate(builder, line16);
    List dataItemsList = data_items_list_get_data(get_data_list(builder), 1);
    print_list(dataItemsList, print_int);
    close(builder);
    return 0;
}
