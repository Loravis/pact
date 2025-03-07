#include "misc.h"
#include "../functions/functions.h"
#include <string.h>

// Finds a string within an array of strings and returns the index.
// Returns -1 if the string isn't found
int find(char** strings, int count, char* string) {
    for (int i = 0; i < count; i++) {
        if (strcmp(strings[i], string) == 0) {
            return i;
        }
    }
    return -1;
}

int arg_handler(char** args, int count) {
    // Help text option
    if (find(args, count, "help") >= 0) {
        show_help();
        return 0;
    } 
    
    // Download source files, compile and install a package.
    int index = find(args, count, "install");
    if (index >= 0) {
        if (count > index + 1) { // It's probably better to check for a string at args[index + 1] instead here
            printf("Test\n");
            return 0;
        } else {
            printf("No package name provided.\n");
            return 1;
        }
    }

    // Download and extract package databases
    index = find(args, count, "sync");
    if (index >= 0) {
        sync_db();
        return 0;
    }

    return -1;
}