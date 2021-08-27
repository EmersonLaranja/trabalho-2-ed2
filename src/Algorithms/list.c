#include "list.h"
#include <stdlib.h>

struct list
{
    int dest;
    double weight;
    List *next;
};

List *init_list()
{
    return NULL;
}
List *new_list_node(int dest, double weight)
{
    List *new_list = (List *)malloc(sizeof(List));
    new_list->dest = dest;
    new_list->weight = weight;
    new_list->next = NULL;
    return new_list;
}


void destroy_alloc_list(List *list)
{
    free(list);
}

void destroy_list(List *list)
{
    List *aux;
    for (List *p = list; p != NULL; p = p->next)
    {
        aux = p;
        p = p->next;
        free(aux);
    }
}


List **alloc_list(int size_graph)
{
    List** array_list = (List **)malloc(size_graph * sizeof(List *));
    for(int i =0 ; i< size_graph; i++){
        array_list[i]  = init_list();
    }
}

void add_list_node(List* list, List*new_node){

    new_node->next = list;
    list = new_node;

}