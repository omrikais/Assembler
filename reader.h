/**********************************************************************************************************************
 ************************************************ The reader module ***************************************************
 **********************************************************************************************************************/

#ifndef ASSEMBLER_READER_H
#define ASSEMBLER_READER_H

#include <stdio.h>
#include "builder.h"

typedef struct reader_t *Reader;        /*the Reader type definition*/

/**
 * @brief                   created a new Reader object and allocated all its necessary memory
 * @param objectFiles       an array of the files names strings
 * @param objectFilesSize   the size of the array
 * @return                  the newly created Reader object
 */
Reader reader_create(const char **objectFiles, size_t objectFilesSize);

/**
 * @brief           deallocates the reader object
 * @param reader    the reader to destroy
 */
void reader_destroy(Reader reader);

/**
 * @brief           loads the next file to the reader
 * @param reader
 * @return          error code or NoErrorFound
 */
Error reader_load_next_file(Reader reader);

/**
 * @brief           runs the first pass
 * @param reader
 * @return          error code or NoErrorFound
 */
Error reader_run_first_pass(Reader reader);

/**
 * @brief           runs the second pass
 * @param reader
 * @return          error code or NoErrorFound
 */
Error reader_run_second_pass(Reader reader);

/**
 * @brief           frees an array of string
 * @param array     the strings array to destroy
 * @param size      the size of the given array
 */
void free_string_array(char **array, size_t size);

/**
 * @brief           return the current builder
 * @param reader
 * @return          the current builder
 */
Builder reader_get_builder(Reader reader);

/**
 * @brief           return true if an error occurred
 * @param reader
 * @return          True if an error occurred
 */
Bool reader_is_error_occurred(Reader reader);

#endif /*ASSEMBLER_READER_H*/
