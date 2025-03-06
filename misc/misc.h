#pragma once

// Ensure freeing each array element at some point
int arg_parse(char** buf, int argc, char **argv);

// Second argument should be argc - 1
int arg_handler(char** args, int count);

// Checks if PACT is running with superuser privileges. 
int check_sudo();

// Downloads a file
int download_file(char** url, char** path);