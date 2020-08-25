/* Created by Omri Kaisari on 14/08/2020.*/

#include <string.h>
#include "file_generator.h"
#include "printer.h"

Error file_generator_make_as_array(const char **args, int size, char ***stringArrayPtr);

void write_output_files(const char **args, Error *error, Reader reader, int currentFileIndex);

void analyze_files(const char **args, Reader reader);

void assemble(const char **args, int size) {
    char **fileNames;
    Reader reader;
    file_generator_make_as_array(args, size, &fileNames);
    reader = reader_create((const char **) fileNames, size - 1);
    analyze_files(args, reader);
    reader_destroy(reader);
    free_string_array(fileNames, size - 1);
}

void analyze_files(const char **args, Reader reader) {
    Error error;
    int i = 1;
    while ((error = reader_load_next_file(reader)) != NoMoreFiles) {
        if (error == FileTypeWrong || error == FileNotExist)
            continue;
        error = reader_run_first_pass(reader);
        if (reader_is_error_occurred(reader)) {
            continue;
        }
        error = reader_run_second_pass(reader);
        if (reader_is_error_occurred(reader) == True) {
            continue;
        }
        write_output_files(args, &error, reader, i);
        ++i;
    }
}

void write_output_files(const char **args, Error *error, Reader reader, int currentFileIndex) {
    char fileName[MAX_LENGTH];
    FILE *outputObject, *outputExtern, *outputEntry;
    sprintf(fileName, "%s.ob", args[currentFileIndex]);
    outputObject = fopen(fileName, "w");
    sprintf(fileName, "%s.ext", args[currentFileIndex]);
    outputExtern = fopen(fileName, "w");
    print_object_file(builder_get_instructions_list(reader_get_builder(reader)),
                      builder_get_data_items_list(reader_get_builder(reader)), outputObject,
                      outputExtern);
    fclose(outputObject);
    if (ftell(outputExtern) == 0)
        remove(fileName);
    else
        fclose(outputExtern);
    sprintf(fileName, "%s.ent", args[currentFileIndex]);
    outputEntry = fopen(fileName, "w");
    (*error) = print_entry_file(builder_get_symbols_list(reader_get_builder(reader)), outputEntry);
    fclose(outputEntry);
    if ((*error) == NoEntries) {
        remove(fileName);
    }
}

Error file_generator_make_as_array(const char **args, int size, char ***stringArrayPtr) {
    char currentFileName[MAX_LENGTH];
    int i;
    if (args == NULL)
        return NoFiles;
    *stringArrayPtr = malloc(sizeof(char *) * (size - 1));
    for (i = 1; i < size; ++i) {
        strcpy(currentFileName, args[i]);
        strcat(currentFileName, ".as");
        (*stringArrayPtr)[i - 1] = malloc(sizeof(char) * (strlen(currentFileName) + 1));
        strcpy((*stringArrayPtr)[i - 1], currentFileName);
    }
    return NoErrorsFound;
}
