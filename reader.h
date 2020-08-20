/*Created by Omri Kaisari on 11/08/2020.*/



#ifndef ASSEMBLER_READER_H
#define ASSEMBLER_READER_H

#include "builder.h"
#include <stdio.h>

typedef struct reader_t *Reader;

Reader reader_create(const char **objectFiles, size_t objectFilesSize, Error *error);

void reader_destroy(Reader reader);

Error reader_load_next_file(Reader reader);

Error reader_run_first_pass(Reader reader);

Error reader_run_second_pass(Reader reader);

void free_string_array(char **array, size_t size);

Builder reader_get_builder(Reader reader);

Bool reader_is_error_occurred(Reader reader);

#endif /*ASSEMBLER_READER_H*/
