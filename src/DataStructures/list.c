/* Estrutura reaproveitada da matéria de ED1 */
#include "list.h"
#include <stdlib.h>
#include <stdio.h>

struct node
{
    Node *next;
    Item vertices;
};

struct list
{
    Node *start;
    Node *end;
};

Item return_item(Node *node)
{
    return node->vertices;
}

Node *return_start_node(List *list)
{
    return list->start;
}

List *init_list()
{
    List *list = (List *)malloc(sizeof(List));
    list->start = NULL;
    list->end = NULL;

    return list;
}

List *insert_node(List *list, Item vertices)
{
    Node *new = (Node *)malloc(sizeof(Node));
    new->vertices = vertices;
    new->next = list->start;
    list->start = new;

    if (list->end == NULL)
    {
        list->end = new;
    }
    return list;
}

void free_list(List *list)
{
    Node *p = list->start;
    Node *t;
    while (p != NULL)
    {
        t = p->next;
        free(p);
        p = t;
    }
    free(list);
}

void free_array_list(List **list, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (list[i] != NULL)
            free_list(list[i]);
    }
    free(list);
}

void show_array_list(List **edges, int num_vertices)
{
    for (int i = 0; i < num_vertices; i++)
    {
        if (edges[i] != NULL)
            show_list(edges[i]);
    }
};

void show_list(List *list)
{
    Node *p;
    for (p = list->start; p != NULL; p = p->next)
    {
        show_item(p->vertices);
    }
}

void update_dist(List **list, int id_min, double *min_dist, Wrapper *min_heap)
{
    for (Node *p = list[id_min]->start; p != NULL; p = p->next)
    {
        double dist = min_dist[id_min] + p->vertices.value;
        int id = p->vertices.id;

        if (dist < min_dist[id])
        {
            min_dist[id] = dist;
            PQ_decrease_key(id, dist, min_heap);
        }
    }
}