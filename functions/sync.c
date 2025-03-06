#include <stdio.h>
#include "../misc/misc.h"

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