#include <stdio.h>
#include <string.h>
#include "list.h"
#include "parser.h"
#include "instruction_word.h"
#include "code_table.h"
#include "data_table.h"
#include "symbol_table.h"

/*Created by Omri Kaisari on 05/08/2020.*/

void print_int(void *n) {
    printf(" %d", *((int *) n));
}

void print_float(void *f) {
    printf(" %f", *(float *) f);
}


int main() {
    List list = list_create();
    int x = 1, y = 2, z = 3, u = 4;
    list_insert_node_at_end(list, &x, sizeof(x));
    list_insert_node_at_end(list, &y, sizeof(x));
    list_insert_node_at_end(list, &z, sizeof(x));
    list_insert_node_at_end(list, &u, sizeof(x));
    print_list(list, print_int);
    printf("\nThe List Size is: %d\n", list_size(list));
    list_destroy(list, free);
/*    char *label = parser_get_label("      ?sholom: sadjlaslkdjsakl");
    parser_is_new_label("hdfjksfhsdjk: sadjlaslkdjsakl");
    printf("%s\n", label);
    char string[] = "SHlom";
    char *token;
    token = strtok(string, ":");
    printf("%s", token);*/
    char str[] = "DUI:    .string hi!";
    Bool y1 = parser_is_directive(str);
    Directive x1 = parser_get_directive(str);
    char str2[] = "stop 3 2";
    Operation operation = parse_get_operation(str2);
    int y2 = parser_get_number_of_operands(operation);
    char s1[] = "hi, my \n,name is omri";
    char *token = strtok(s1, WHITE_DELIMITERS);
    printf("%s\n", token);
    token = strtok(NULL, " \t\n,");
    printf("%s\n", token);
    char line[] = "hi: inc 1,2   ";
    Error error = parser_check_operands(line, 2);
    char s2[] = "inc r33  , 2";
    char *operand = parser_get_operand(s2, 1);
    AddressingMethod addressingMethod = parser_get_addressing_method_of_operand(operand);
    printf("%s\n", operand);
    char s3[] = "Hi: .string \"Shalom\"\n";
    List arr = parser_get_string_data(s3);
    print_list(arr, print_int);
    printf("\n");
    /*printf("%s\n", (char *) arr);*/
    char s4[] = "hi: .data +4,5,6,7,9,+8\n";
    List list1 = parser_get_data_array(s4, NULL);
    print_list(list1, print_int);
    /*print_list(list1, print_int);*/
    printf("\nThe List Size is: %d\n", list_size(list1));
    InstructionWord word = instruction_word_create(12, 4, 1, 2, 3, 2, 3, 2);
    InstructionWord word2 = instruction_word_create(15, 4, 1, 2, 3, 2, 3, 2);
    InstructionsList list2 = instruction_list_create();
    instruction_list_add_instruction(list2, word);
    instruction_list_add_instruction(list2, word2);
    InstructionWord word1 = instruction_list_get_instruction(list2, 1);
    InstructionWord word3 = instruction_list_get_instruction(list2, 2);
    DataItemsList dataItemsList = data_items_list_create();
    data_items_list_add_data_element(dataItemsList, arr, parser_get_size_of_element(arr, Data));
    data_items_list_add_data_element(dataItemsList, list1, parser_get_size_of_element(list1, Data));
    List list3 = (List) data_items_list_get_data(dataItemsList, 1);
    print_list(list3, print_int);
    List symbols = list_create();
    SymbolEntry entry = symbol_entry_create("Hi", 100, Code);
    SymbolEntry entry1 = symbol_entry_create("Omri", 105, Code);
    SymbolEntry entry2 = symbol_entry_create("Marlena", 1010, Code);
    list_insert_node_at_end(symbols, entry, symbol_size_of());
    list_insert_node_at_end(symbols, entry1, symbol_size_of());
    list_insert_node_at_end(symbols, entry2, symbol_size_of());
    SymbolEntry s = list_find_element(symbols, "Marlena", (Equals) symbol_entry_compare);
    data_items_list_destroy(dataItemsList);
    char s32[] = "          \n      ;   ?        \n";
    Bool aBool = parser_is_empty_line((s32));
    return 0;
}
