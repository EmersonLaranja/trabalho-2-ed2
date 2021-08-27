#ifndef LIST_H
#define LIST_H


typedef struct list List;


List* init_list();
List* new_list_node(int dest, double weight);
void add_list_node(List* list, List*new_node);
List** alloc_list(int size_graph);
void destroy_alloc_list(List*);
void  destroy_list(List* list);

#endif