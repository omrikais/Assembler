/* Created by Omri Kaisari on 14/08/2020.*/

#include <string.h>
#include "files_handler.h"
#include "printer.h"

/************************************************** Internal functions ************************************************/

/**
 * @brief gets a stings array as given to main and converts it to appropriate file-name strings array
 * @param args              the given array to main
 * @param size              the size of args
 * @param stringArrayPtr    pointer to which the functions returns the file name array
 * @return
 */
Error file_generator_make_as_array(const char **args, int size, char ***stringArrayPtr);

/**
 * @brief creates all the needed output files and checks if ext. and ent. are needed
 * @param args              the file name array of the input files
 * @param error             an error pointer to which error code might be returned
 * @param reader            a reader type with all the needed information for producing the files
 * @param currentFileIndex  the index of the current input file in args
 */
void write_output_files(const char **args, Error *error, Reader reader, int currentFileIndex);

/**
 * @brief checks the file naming correctness and runs the first and the second pass of the assembly process.
 *          it also sends the relevant parameters to write_output_files in order to produce the needed output files
 * @param args      the file name array of the input files
 * @param reader    a reader type with all the needed information for producing the files
 */
void analyze_files(const char **args, Reader reader);

void analyze_files(const char **args, Reader reader) {
    Error error;
    int i = FIRST_FILE_INDEX;
    while ((error = reader_load_next_file(reader)) != NoMoreFiles) {
        if (error == FileTypeWrong || error == FileNotExist) {
            ++i;
            continue;
        }
        error = reader_run_first_pass(reader);
        if (reader_is_error_occurred(reader)) {
            ++i;
            continue;
        }
        error = reader_run_second_pass(reader);
        if (reader_is_error_occurred(reader)) {
            ++i;
            continue;
        }
        write_output_files(args, &error, reader, i);
        ++i;
    }
}

void write_output_files(const char **args, Error *error, Reader reader, int currentFileIndex) {
    char fileName[MAX_LENGTH];
    FILE *outputObject, *outputExtern, *outputEntry;
    sprintf(fileName, "%s%s", args[currentFileIndex], OBJECT_FILE_EXTENSION);
    outputObject = fopen(fileName, "w");
    sprintf(fileName, "%s%s", args[currentFileIndex], EXTERN_FILE_EXTENSION);
    outputExtern = fopen(fileName, "w");
    print_object_and_extern_files(builder_get_instructions_list(reader_get_builder(reader)),
                                  builder_get_data_items_list(reader_get_builder(reader)), outputObject,
                                  outputExtern);
    fclose(outputObject);
    if (ftell(outputExtern) == 0)
        remove(fileName);
    else
        fclose(outputExtern);
    sprintf(fileName, "%s%s", args[currentFileIndex], ENTRY_FILE_EXTENSION);
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
    for (i = FIRST_FILE_INDEX; i < size; ++i) {
        strcpy(currentFileName, args[i]);
        strcat(currentFileName, ASSEMBLER_FILE_EXTENSION);
        (*stringArrayPtr)[i - 1] = malloc(sizeof(char) * (strlen(currentFileName) + 1));
        strcpy((*stringArrayPtr)[i - 1], currentFileName);
    }
    return NoErrorsFound;
}

/************************************************** Functions implementations *****************************************/

void assemble(const char **args, int size) {
    char **fileNames;
    Reader reader;
    if (size == 1) {
        error_print(NoInputFiles, NO_FILE, NULL);
        return;
    }
    file_generator_make_as_array(args, size, &fileNames);
    reader = reader_create((const char **) fileNames, size - 1);
    analyze_files(args, reader);
    reader_destroy(reader);
    free_string_array(fileNames, size - 1);
}
