#ifndef DATA_H
#define DATA_H
#include "edges.h"

typedef struct data Data;

Data* alloc_data();
void set_servers(Data* ,int* );
void set_clients(Data* ,int* );
void set_monitors(Data* ,int* );
void set_edges(Data* , Edges* );

#endif