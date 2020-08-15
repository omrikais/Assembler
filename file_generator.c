/* Created by Omri Kaisari on 14/08/2020.*/

#include "file_generator.h"
#include "printer.h"
#include <string.h>

Error file_generator_make_as_array(const char **args, int size, char ***stringArrayPtr);

Error assemble(const char **args, int size) {
    Error error;
    Builder builder = init();
    char **fileNames;
    Reader reader;
    char fileName[MAX_LENGTH];
    error = file_generator_make_as_array(args, size, &fileNames);
    reader = reader_create((const char **) fileNames, size, &error, builder);
    int i = 0;
    FILE *outputObject, *outputExtern, *outputEntry;
    if (reader == NULL) {
        return error;
    }
    while (reader_load_next_file(reader) != NoMoreFiles) {
        error = reader_run_first_pass(reader);
        if (error != NoErrorsFound) {
            /*TODO:error handling*/
        }
        error = reader_run_second_pass(reader);
        if (error != NoErrorsFound) {
            /*TODO: error handling*/
        }
        sprintf(fileName, "%s.ob", args[i]);
        outputObject = fopen(fileName, "w");
        sprintf(fileName, "%s.ext", args[i]);
        outputExtern = fopen(fileName, "w");
        print_object_file(builder_get_instructions_list(builder), builder_get_data_items_list(builder), outputObject,
                          outputExtern);
        fclose(outputObject);
        if (ftell(outputExtern) == 0)
            remove(fileName);
        else
            fclose(outputExtern);
        sprintf(fileName, "%s.ent", args[i]);
        outputEntry = fopen(fileName, "w");
        error = print_entry_file(builder_get_symbols_list(builder), outputEntry);
        fclose(outputEntry);
        if (error == NoEntries) {
            remove(fileName);
        }
    }
    reader_destroy(reader);
    free_string_array(fileNames, size);
    return NoErrorsFound;
}

Error file_generator_make_as_array(const char **args, int size, char ***stringArrayPtr) {
    char currentFileName[MAX_LENGTH];
    int i;
    if (args == NULL)
        return NoFiles;
    *stringArrayPtr = malloc(sizeof(char *) * size);
    for (i = 0; i < size; ++i) {
        strcpy(currentFileName, args[i]);
        strcat(currentFileName, ".as");
        (*stringArrayPtr)[i] = malloc(sizeof(char) * (strlen(currentFileName) + 1));
        strcpy((*stringArrayPtr)[i], currentFileName);
    }
    return NoErrorsFound;
}
