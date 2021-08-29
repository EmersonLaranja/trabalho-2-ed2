#ifndef LIST_H
#define LIST_H

#include "item.h"

#include "item.h"
#include "heap.h"


typedef struct list List;
typedef struct node Node;




List *init_list();
void insert_node(List *list, Item vertice);
void free_list(List * list);
void free_array_list(List** list, int size);
void update_dist(List**list, int id_min,double* min_dist, Wrapper* min_heap);
#endif