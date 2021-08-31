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

Item get_item_list(Node *node)
{
    return node->vertices;
}

Node *get_start_node(List *list)
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
    /* Cria novo nó pertencente ao item */
    Node *new = (Node *)malloc(sizeof(Node));
    new->vertices = vertices; /* Armazena item na lista */
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
    while (p != NULL) /* Percorre todos os nós da lista e libera */
    {
        t = p->next;
        free(p);
        p = t;
    }
    free(list); /* Libera a lista */
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

void update_dist(List **list, int id_min, double *min_dist, Wrapper *min_heap)
{
    /* Percorre todos os nós da lista do id especificado como parametro */
    for (Node *aux = list[id_min]->start; aux != NULL; aux = aux->next)
    {
        /* Atribui a dist o valor da distancia do source até o nó aux avaliado */
        double dist = min_dist[id_min] + aux->vertices.value;
        int id = aux->vertices.id;

        if (dist < min_dist[id]) /* Se a distancia calculada em dist for menor que a distancia atual no min_dist, atualiza */
        {
            min_dist[id] = dist;
            PQ_decrease_key(id, dist, min_heap); /* atualiza o valor da heap */
        }
    }
}