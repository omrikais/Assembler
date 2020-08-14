/* Created by Omri Kaisari on 14/08/2020.*/

#include "file_generator.h"
#include "printer.h"

Error assemble(const char **args, int size) {
    Error error;
    Builder builder = init();
    Reader reader = reader_create(args, size, &error, builder);
    char fileName[MAX_LENGTH];
    int i = 0;
    FILE *output;
    if (reader == NULL)
        return error;
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
        output = fopen(fileName, "w");
        print_object_file(builder_get_instructions_list(builder), builder_get_data_items_list(builder), output);
        /*TODO: generate files here*/
    }
    return NoErrorsFound;
}
