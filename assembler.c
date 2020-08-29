/*Created by Omri Kaisari on 16/08/2020.*/

#include "files_handler.h"


int main(int argc, char *argv[]) {
    freopen("badpath-relative.txt", "w", stderr);
    assemble((const char **) argv, argc);
    return 0;
}

