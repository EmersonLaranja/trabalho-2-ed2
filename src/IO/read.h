#ifndef READ_H
#define READ_H

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>

FILE *initialize_file(FILE *file, char *name);
void verify_args_length(int num_args);
void file_was_opened(FILE *file);

#endif /* READ_H */