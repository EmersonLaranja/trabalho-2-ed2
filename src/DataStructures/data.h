#ifndef DATA_H
#define DATA_H
#include "edges.h"
#include "component.h"

typedef struct data Data;

Data *alloc_data();
void *destroy_data(Data *);
void set_servers(Data *, Component *);
void set_clients(Data *, Component *);
void set_monitors(Data *, Component *);
void set_edges(Data *, Edges *);
void set_num_edges(Data *, int);
void set_num_vertex(Data *, int);
int get_num_edges(Data *);
int get_num_vertex(Data *);
Component *get_servers(Data *);
Component *get_clients(Data *);
Component *get_monitors(Data *);

void show_data(Data *);

#endif