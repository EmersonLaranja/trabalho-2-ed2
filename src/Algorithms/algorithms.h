#ifndef ALGORITHMS_H
#define ALGORITHMS_H
#include "../DataStructures/list.h"

void dijkstra(int id, int number_vertices, double *dist, List **list);
double *dist_min_initialize(int size);

#endif