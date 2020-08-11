/*Created by Omri Kaisari on 11/08/2020.*/



#ifndef ASSEMBLER_READER_H
#define ASSEMBLER_READER_H

#include "builder.h"
#include <stdio.h>

typedef struct reader_t *Reader;

Reader reader_create(const char **objectFiles, size_t objectFilesSize, FILE *input, Error *error);

void reader_destroy(Reader reader);

Error reader_load_next_file(Reader reader);

#endif /*ASSEMBLER_READER_H*/
