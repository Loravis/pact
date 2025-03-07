#include "misc.h"
#include <string.h>
#include <stdlib.h>

const unsigned int MAXARGUMENTLENGTH = 254;

int arg_parse(char** buf, int argc, char **argv) {
    for (int i = 1; i < argc; i++) {
        unsigned long length = strlen(argv[i]);
        if (length > MAXARGUMENTLENGTH) {
            length = MAXARGUMENTLENGTH;
        }
        char* str = (char*)malloc(length + 1); // Adding +1 to make space for a null terminator
        if (str == NULL) {
            return -1;
        }
        strncpy(str, argv[i], length);
        str[length] = '\0'; // Ensures the string is null terminated
        buf[i - 1] = str;
    }
    return 0;
}