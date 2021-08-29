#ifndef PATH_H
#define PATH_H
#include <stdio.h>
#include <stdlib.h>
typedef struct path Path;

Path **init_path(int size);
void destroy_path_array(Path **path, int size);
Path *create_path(int origin, int destiny, double inflaction);
int get_origin(Path *path);
int get_destiny(Path *path);
double get_inflaction(Path *path);
int compare_path(const void *par1, const void *par2);

#endif