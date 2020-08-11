/*Created by Omri Kaisari on 11/08/2020.*/

#include "reader.h"
#include <string.h>

struct reader_t {
    Builder builder;
    char **objectFiles;
    size_t objectFilesSize;
    FILE *input;
    int nextFileIndex;
};

Bool is_valid_file_name(const char *file);

char **copy_char_array(const char **charArray, size_t size);

void free_string_array(char **array, size_t size);

Reader reader_create(const char **objectFiles, size_t objectFilesSize, FILE *input, Error *error) {
    Reader reader;
    reader = malloc(sizeof(struct reader_t));
    reader->builder = init();
    reader->objectFilesSize = objectFilesSize;
    if (objectFilesSize == 0) {
        *error = NoFiles;
        reader_destroy(reader);
        return NULL;
    }
    reader->objectFiles = copy_char_array(objectFiles, objectFilesSize);
    reader->nextFileIndex = 0;
    return reader;
}

void reader_destroy(Reader reader) {
    close(reader->builder);
    free_string_array(reader->objectFiles, reader->objectFilesSize);
    free(reader);
}

Error reader_load_next_file(Reader reader) {
    if (reader->nextFileIndex != 0 && (reader->nextFileIndex < reader->objectFilesSize) &&
        (is_valid_file_name((reader->objectFiles)[reader->nextFileIndex - 1])))
        fclose(reader->input);
    if (reader->nextFileIndex >= reader->objectFilesSize)
        return NoMoreFiles;
    if (is_valid_file_name((reader->objectFiles)[reader->nextFileIndex]) != True) {
        ++(reader->nextFileIndex);
        return FileTypeWrong;
    }
    reader->input = fopen((reader->objectFiles)[reader->nextFileIndex], "r");
    ++(reader->nextFileIndex);
    return NoErrorsFound;
}

Error reader_run_first_pass(Reader reader) {
    char line[MAX_LENGTH];
    Error error;
    while (fgets(line, MAX_LENGTH - 1, reader->input) != NULL && feof(reader->input) == 0) {
        error = evaluate(reader->builder, line);
        if (error != NoErrorsFound)
            return error;                /*temporary, should continue and print error message*/
    }
    /*should update the DC by The IC value*/
    return NoErrorsFound;
}

Bool is_valid_file_name(const char *file) {
    int length;
    char tmpStr[MAX_LENGTH], *ending;
    strcpy(tmpStr, file);
    length = strlen(tmpStr);
    ending = (tmpStr + length - ENDING_LENGTH);
    if (strcmp(ending, ASSEMBLER_ENDING_STR) != 0) {
        return False;
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
    if (array == NULL)
        return;;
    for (i = 0; i < size; ++i)
        free(array[i]);
    free(array);
}
