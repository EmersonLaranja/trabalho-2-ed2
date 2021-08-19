#ifndef READ_H
#define READ_H
#include "../DataStructures/data.h"
#include <stdlib.h>
#include <stdio.h>


FILE* initialize_file(FILE *file, char *name);
void verify_args_length(int num_args);
void file_was_opened(FILE *file);
Data* read_file(char* input_file);
char * define_buffer (FILE * file, size_t bufsize);
void destroy_buffer(char*);


#endif /* READ_H */