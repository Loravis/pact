#include <stdio.h>
#include "../misc/misc.h"

int sync_db() {
    char* main_db = "https://github.com/Loravis/pact_db/archive/refs/heads/main.zip";
    char* database_directory = "/var/pact/pact_db";
    char* temp_path = "./download.zip";

    if(check_sudo() != 0) {
        return 1;
    }

    printf("Synchronizing local package database...\n");

    int res = download_file(&main_db, &temp_path);
    if (res != 0) {
        printf("Error while downloading files: curl exited with code %d.\n", res);
    }

    // Todo: unzip

    return 0;
}