#ifndef EDGES_H
#define EDGES_H
#include <stdio.h>


typedef struct edges Edges;

Edges* alloc_edges();
Edges* read_edges(int num_edges, FILE* file);
void destroy_edges(Edges*);
void show_edges(Edges*,int num_edges);

#endif