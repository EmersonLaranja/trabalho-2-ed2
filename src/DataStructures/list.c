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

// int main()
// {
//     List *list = init_list();
//     insert_node(list, make_item(1, 2424));
//     insert_node(list, make_item(5, 2545));
//     insert_node(list, make_item(8, 7575));
//     insert_node(list, make_item(2, 3456));
//     insert_node(list, make_item(2, 63576));
//     insert_node(list, make_item(86, 4334));

//     imprimeLista(list);
//     free_list(list);
// }