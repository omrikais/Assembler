/*Created by Omri Kaisari on 13/08/2020.*/
#include <stdio.h>
#include "list.h"
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
    char *args[] = {"./valid"};
    assemble(args, 1);
    return 0;
}

