/*Created by Omri Kaisari on 11/08/2020.*/

#include "reader.h"
#include <string.h>

struct reader_t {
    Builder builder;
    char **objectFiles;
    size_t objectFilesSize;
    FILE *input;
    int currentFileIndex;
};

Bool is_valid_files_names(const char **files, size_t numberOfFiles);

char **copy_char_array(const char **charArray, size_t size);

void free_string_array(char **array, size_t size);

Reader reader_create(const char **objectFiles, size_t objectFilesSize, FILE *input, Error *error) {
    Reader reader;
    if (is_valid_files_names(objectFiles, objectFilesSize) != True) {
        *error = FileTypeWrong;
        return NULL;
    }
    reader = malloc(sizeof(struct reader_t));
    reader->builder = init();
    reader->objectFilesSize = objectFilesSize;
    reader->objectFiles = copy_char_array(objectFiles, objectFilesSize);
    reader->currentFileIndex = 0;

    reader->input = fopen(reader->objectFiles[reader->currentFileIndex], "r");
    return reader;
}

void reader_destroy(Reader reader) {
    close(reader->builder);
    free_string_array(reader->objectFiles, reader->objectFilesSize);
    free(reader);
}

Error reader_load_next_file(Reader reader) {

}

Error reader_run_first_pass(Reader reader) {

}

Bool is_valid_files_names(const char **files, size_t numberOfFiles) {
    int i, length;
    char tmpStr[MAX_LENGTH], *ending;
    for (i = 0; i < numberOfFiles; ++i) {
        strcpy(tmpStr, files[i]);
        length = strlen(tmpStr);
        ending = (tmpStr + length - ENDING_LENGTH);
        if (strcmp(ending, ASSEMBLER_ENDING_STR) != 0) {
            return False;
        }
    }
    return True;
}

char **copy_char_array(const char **charArray, size_t size) {
    int i;
    char *word;
    char **copy = malloc(sizeof(*copy) * size);
    for (i = 0; i < size; ++i) {
        copy[i] = malloc(sizeof(char) * (strlen(charArray[i]) + 1));
        strcpy(copy[i], charArray[i]);
    }
    return copy;
}

void free_string_array(char **array, size_t size) {
    int i;
    for (i = 0; i < size; ++i)
        free(array[i]);
    free(array);
}
