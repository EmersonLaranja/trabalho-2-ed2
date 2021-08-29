#ifndef DATA_H
#define DATA_H
#include "component.h"
#include "list.h"

typedef struct data Data;

Data *alloc_data();
void *destroy_data(Data *);
void set_servers(Data *, Component *);
void set_clients(Data *, Component *);
void set_monitors(Data *, Component *);
void set_edges(Data *, List **);
void set_num_edges(Data *, int);
void set_num_vertices(Data *, int);
int get_num_edges(Data *);
int get_num_vertices(Data *);
List **get_edges(Data *data);
Component *get_servers(Data *);
Component *get_clients(Data *);
Component *get_monitors(Data *);

void show_data(Data *);

#endif