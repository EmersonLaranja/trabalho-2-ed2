/* Estrutura reaproveitada da matéria de ED1 */
#include "list.h"
#include <stdlib.h>
#include <stdio.h>

struct node
{
    Item vertice;
    Node *next;
};

struct list
{
    Node *start;
    Node *end;
};

List *init_list()
{
    List *list = (List *)malloc(sizeof(List));
    list->start = NULL;
    list->end = NULL;

    return list;
}

void insert_node(List *list, Item vertice)
{
    Node *new = (Node *)malloc(sizeof(Node));
    new->vertice = vertice;
    new->next = list->start;
    list->start = new;

    if (list->end == NULL)
    {
        list->end = new;
    }
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
        free_list(list[i]);
    }
    free(list);
}

void imprimeLista(List *list){
    Node *p;
    for (p = list->start; p != NULL; p = p->next)
    {
        printf("%d - %.8lf\n", p->vertice.id, p->vertice.value);
    }
}

void update_dist(List** list, int id_min, double* min_dist, Wrapper* min_heap){
    for(Node* p = list[id_min]->start; p !=NULL; p = p->next){
        double dist = min_dist[id_min] + p->vertice.value;
        int id = p->vertice.id;
        
        if(dist< min_dist[id]){
            min_dist[id] = dist;
            PQ_decrease_key(id, dist, min_heap);
        }
    }
}