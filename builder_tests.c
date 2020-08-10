#include <stdio.h>
#include <string.h>
#include "list.h"
#include "parser.h"
#include "instruction_word.h"
#include "code_table.h"
#include "data_table.h"
#include "symbol_table.h"
#include "builder.h"

int main() {
    Builder builder = init();
    List list;
    char line[] = "   Hello:      .data 1,2,3,4,5";
    char line2[] = "              Hello: .data 2,4";
    char line3[] = "   Ho: .string \"My name is Omri\"";
    char line4[] = "   .extern Hello";
    char line5[] = "    HoHo: add &kklkl,         Hi      \n";
    InstructionWord word = NULL;
    Error error = evaluate_directive_line(builder, line);
    Error error2 = evaluate_directive_line(builder, line2);
    Error error3 = evaluate_directive_line(builder, line3);
    Error error4 = evaluate_directive_line(builder, line4);
    Error error5 = -1;
    list = get_symbol_table(builder);
    printf("%d", symbol_get_location(list_find_element(list, "Ho", (Equals) symbol_entry_compare)));
    word = fill_instruction_word(&error5, line5);
    return 0;
}
