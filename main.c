#include "misc/misc.h"
#include <stdio.h>
#include <stdlib.h>

// TODO: sync and install commands

int main(int argc, char** argv){
    if (argc <= 1) {
        printf("No arguments provided. Run pact help to get a list of valid arguments.\n");
        return 1;
    }
    char* args[argc - 1];
    arg_parse(args, argc, argv);

    int result = arg_handler(args, argc - 1);

    // Free each array element
    unsigned long length = sizeof(args) / 8;
    for (int i = 0; i < length; i++) {
        free(args[i]);
    }

    if (result != 0) {
        return result;
    } else {
        return 0;
    }
}