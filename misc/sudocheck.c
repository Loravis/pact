#include <unistd.h>
#include <stdio.h>

int check_sudo() {
    int uid = getuid();
    if (uid != 0) {
        printf("Error: This operation requires elevated privileges. Ensure you run this command as a root user\n");
        return 1;
    }

    return 0;
}