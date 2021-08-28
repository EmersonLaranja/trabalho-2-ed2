#ifndef COMPONENT_H
#define COMPONENT_H

typedef struct component Component;

Component *create_component(int, int *);
void destroy_component(Component *);
void show_component(Component *);
int get_size_component(Component *component);
#endif