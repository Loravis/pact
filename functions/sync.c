#include <git2.h>
#include <git2/remote.h>
#include <stdio.h>
#include "../misc/misc.h"

// Print libgit2 error messages for debugging
void print_libgit2_error(char* action) {
    printf("Error while %s: ", action);
    printf("libgit2 error: %s\n", git_error_last()->message);
}

int sync_db() {
    // PACT currently only supports pulling a 
    const char* main_db = "https://github.com/Loravis/pact_db";
    const char* database_directory = "/var/pact/pact_db";

    if(check_sudo() != 0) {
        return 1;
    }

    printf("Synchronizing local package database...\n");

    // TODO: Download files

    return 0;
}