#include "graph.h"
#include <stdlib.h>
#include <stdio.h>

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

void free_graph(Graph *g)
{
    for (int i = 0; i < g->size_graph; i++)
    {
        if (g->array[i] != NULL)
            destroy_list(g->array[i]);
    }

    free(g->array);
    free(g);
}

void print_graph(Graph *g)
{
    printf("SIZE: %d\n", g->size_graph);
    for (int i = 0; i < g->size_graph; i++)
    {
        print_list(g->array[i]);
    }
}

int get_size_graph(Graph *graph)
{
    return graph->size_graph;
}
List *get_array_graph(Graph *graph, int id)
{
    return graph->array[id];
}

void add_edge(Graph *graph, int src, int dest, double weight)
{

    List *new_node = new_list_node(dest, weight);
    add_list_node(&graph->array[src], &new_node);
}