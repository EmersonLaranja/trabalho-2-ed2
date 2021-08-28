#ifndef GRAPH_H
#define GRAPH_H
#include "list.h"


typedef struct graph Graph;

Graph* create_graph(int size_graph);
void add_edge(Graph* graph, int src, int dest, double weight);
int get_size_graph(Graph* graph);
List* get_array_graph(Graph* graph,int id);


#endif