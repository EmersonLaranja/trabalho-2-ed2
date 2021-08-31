#include "component.h"
#include <stdlib.h>
#include <stdio.h>

struct component
{
    int *vector;
    int size;
};

Component *create_component(int size, int *vector)
{
    Component *component = (Component *)malloc(sizeof(Component));
    component->size = size;
    component->vector = vector;
}

int get_size_component(Component *component)
{
    return component->size;
}

void destroy_component(Component *component)
{
    free(component->vector);
    free(component);
}

void show_component(Component *component)
{
    for (int i = 0; i < component->size; i++)
    {
        printf("%d ", component->vector[i]);
    }
    printf("\n");
}

int get_element_id_component(Component* component, int position){
    /* Retorna o componente referente ao id */
    return component->vector[position];
}