#ifndef LIST_H
#define LIST_H

#include "item.h"

#include "item.h"
#include "heap.h"

typedef struct list List;
typedef struct node Node;

List *init_list();
List *insert_node(List *list, Item vertices);
Item return_item(Node *node);
void free_list(List *list);
void free_array_list(List **list, int size);
void update_dist(List **list, int id_min, double *min_dist, Wrapper *min_heap);
void show_array_list(List **edges, int num_vertices);
void show_list(List *edges);
List **read_edges(int num_edges, int num_vertices, FILE *file);
#endif