#ifndef COMPONENT_H
#define COMPONENT_H

typedef struct component Component;

Component *create_component(int, int *);
void destroy_component(Component *);
int get_element_id_component(Component* component, int position);
void show_component(Component *);
int get_size_component(Component *component);
#endif