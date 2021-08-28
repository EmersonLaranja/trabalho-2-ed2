#include "graph.h"
#include "list.h"
#include <stdlib.h>

struct graph
{
    int size_graph;
    List **array;
};

Graph *create_graph(int size_graph)
{

    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->size_graph = size_graph;

    graph->array = alloc_list(size_graph);

    return graph;
}

void add_edge(Graph *graph, int src, int dest, double weight)
{

    List *new_node = new_list_node(dest, weight);
    add_list_node(graph->array[src], new_node);

    new_node = new_list_node(src, weight);
    add_list_node(graph->array[dest], new_node);
}