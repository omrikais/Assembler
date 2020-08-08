
/*Created by Omri Kaisari on 08/08/2020.*/

#include "code_table.h"
#include <stdlib.h>


struct codeListT {
    List instructions;
    int IC;
    int numberOfInstructions;
};


InstructionsList instructionListCreate() {
    InstructionsList instructions = malloc(sizeof(struct codeListT));
    instructions->instructions = listCreate();
    instructions->IC = BEGIN_ADDRESS;
    instructions->numberOfInstructions = 0;
    return instructions;
}


int instructionListGetIC(InstructionsList instructions) {
    return instructions->IC;
}

void instructionListAddInstruction(InstructionsList instructions, InstructionWord word) {
    /*assumes that word is a valid instruction word with all its elements*/
    listInsertNodeAtEnd(instructions->instructions, word, instructionWordGetSize());
    ++(instructions->numberOfInstructions);
    instructions->IC += instructionWordGetNumberOfWords(word);
}

void instructionListDestroy(InstructionsList instructions) {
    listDestroy(instructions->instructions, (destroyFunction) instructionWordDestroy);
    free(instructions);
}

InstructionWord instructionListGetInstruction(InstructionsList instructions, int i) {
    return (InstructionWord) listGetDataElementAtIndex(instructions->instructions, i);
}











