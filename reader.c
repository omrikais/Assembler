/*Created by Omri Kaisari on 11/08/2020.*/

#include <string.h>
#include "reader.h"


struct reader_t {
    Builder builder;
    char **objectFiles;
    size_t objectFilesSize;
    FILE *input;
    int nextFileIndex;
    int currentLine;
    Bool isErrorOccurred;
};

Bool is_valid_file_name(const char *file);

char **copy_char_array(const char **charArray, size_t size);

Error check_entry(Reader reader, const char *line);

Reader reader_create(const char **objectFiles, size_t objectFilesSize) {
    Reader reader;
    reader = malloc(sizeof(struct reader_t));
    reader->builder = init();
    reader->objectFilesSize = objectFilesSize;
    if (objectFilesSize == 0) {
        reader_destroy(reader);
        return NULL;
    }
    reader->objectFiles = copy_char_array(objectFiles, objectFilesSize);
    reader->nextFileIndex = 0;
    reader->currentLine = FIRST_ELEMENT;
    reader->isErrorOccurred = False;
    reader->input = NULL;
    return reader;
}

void reader_destroy(Reader reader) {
    close(reader->builder);
    free_string_array(reader->objectFiles, reader->objectFilesSize);
    free(reader);
}

Error reader_load_next_file(Reader reader) {
    close(reader->builder);
    reader->builder = init();
    reader->isErrorOccurred = False;
    if (reader->input != NULL)
        fclose(reader->input);
    if (reader->nextFileIndex >= reader->objectFilesSize)
        return NoMoreFiles;
    if (is_valid_file_name((reader->objectFiles)[reader->nextFileIndex]) != True) {
        error_print(FileTypeWrong, -1, (reader->objectFiles)[reader->nextFileIndex]);
        ++(reader->nextFileIndex);
        reader->isErrorOccurred = True;
        return FileTypeWrong;
    }
    reader->input = fopen((reader->objectFiles)[reader->nextFileIndex], "r");
    if (reader->input == NULL) {
        error_print(FileNotExist, -1, (reader->objectFiles)[reader->nextFileIndex]);
        ++(reader->nextFileIndex);
        reader->isErrorOccurred = True;
        return FileNotExist;
    }
    ++(reader->nextFileIndex);
    return NoErrorsFound;
}

Error reader_run_first_pass(Reader reader) {
    char line[MAX_LINE_LENGTH];
    Error error = NoErrorsFound;
    reader->currentLine = FIRST_ELEMENT;
    while (fgets(line, MAX_LINE_LENGTH, reader->input) != NULL) {
        int currentFile = reader->nextFileIndex - 1;
        line[MAX_LENGTH] = STRING_END;
        error = evaluate(reader->builder, line);
        if (error != NoErrorsFound) {
            error_print(error, reader->currentLine, reader->objectFiles[currentFile]);
            reader->isErrorOccurred = True;
        }
        ++reader->currentLine;
    }
    builder_update_data_symbols_location(reader->builder);
    return error;
}

Error reader_run_second_pass(Reader reader) {
    char line[MAX_LENGTH];
    int instructionNumber = FIRST_ELEMENT;
    rewind(reader->input);
    reader->currentLine = FIRST_ELEMENT;
    while (fgets(line, MAX_LENGTH - 1, reader->input) != NULL && feof(reader->input) == 0) {
        InstructionWord word;
        Error error;
        if (parser_is_empty_line(line) == True) {
            ++reader->currentLine;
            continue;
        }
        if (parser_is_entry(line) == True) {
            error = check_entry(reader, line);
            ++reader->currentLine;
            continue;
        }
        if (parser_is_directive(line) == True || parser_after_label_check(line) == OnlyLabel) {
            ++reader->currentLine;
            continue;
        }
        word = instruction_list_get_instruction(builder_get_instructions_list(reader->builder), instructionNumber);
        builder_update_instruction(word, reader->builder, &error);
        if (error != NoErrorsFound) {
            error_print(error, reader->currentLine, reader->objectFiles[reader->nextFileIndex - 1]);
            reader->isErrorOccurred = True;
        }
        ++instructionNumber;
        ++reader->currentLine;
    }
    return NoErrorsFound;
}

Error check_entry(Reader reader, const char *line) {
    Error error = evaluate_entry_directive(reader->builder, line);
    if (error != NoErrorsFound) {
        error_print(error, reader->currentLine, reader->objectFiles[reader->nextFileIndex - 1]);
        reader->isErrorOccurred = True;
    }
    return error;
}


Bool is_valid_file_name(const char *file) {
    size_t length;
    char tmpStr[MAX_LENGTH], *ending;
    strcpy(tmpStr, file);
    length = strlen(tmpStr);
    ending = (tmpStr + length - ENDING_LENGTH);
    if (strcmp(ending, ASSEMBLER_FILE_EXTENSION) != 0)
        return False;
    return True;
}

char **copy_char_array(const char **charArray, size_t size) {
    int i;
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
        return;
    for (i = 0; i < size; ++i)
        free(array[i]);
    free(array);
}

Builder reader_get_builder(Reader reader) {
    return reader->builder;
}

Bool reader_is_error_occurred(Reader reader) {
    return reader->isErrorOccurred;
}
