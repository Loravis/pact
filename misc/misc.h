#pragma once

// Ensure freeing each array element at some point
int arg_parse(char** buf, int argc, char **argv);

// Second argument should be argc - 1
int arg_handler(char** args, int count);