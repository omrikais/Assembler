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
    char line[] = "   Hello:      .data 1,2,3,4,5";
    char line2[] = "              Hello: .data 2,4";
    char line3[] = "   Hello: .string \"My name is Omri\"";
    char line4[] = "  Hello: .string \"Hi\"";
    Error error = evaluate_directive_line(builder, line);
    Error error2 = evaluate_directive_line(builder, line2);
    Error error3 = evaluate_directive_line(builder, line3);
    Error error4 = evaluate_directive_line(builder, line4);
    return 0;
}
