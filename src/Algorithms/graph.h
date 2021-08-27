#ifndef GRAPH_H
#define GRAPH_H


typedef struct graph Graph;

Graph* create_graph(int size_graph);
void add_edge(Graph* graph, int src, int dest, double weight);

#endif