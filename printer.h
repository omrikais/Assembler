/*Created by Omri Kaisari on 12/08/2020.*/

#ifndef ASSEMBLER_PRINTER_H
#define ASSEMBLER_PRINTER_H

#include <stdio.h>
#include "instruction_word.h"
#include "list.h"

void print_instruction_word(InstructionWord word, FILE *output);

void print_header_line(int numberOfInstructionWords, int numberOfDataWords, FILE *output);

void print_data(List *dataList, size_t sizeOfDataList, int ICF, FILE *output);


#endif /*ASSEMBLER_PRINTER_H*/
