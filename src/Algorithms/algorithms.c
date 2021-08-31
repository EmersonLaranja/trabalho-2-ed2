#include "algorithms.h"
#include <limits.h>
#include <stdio.h>
#include "../IO/read.h"
#include "../DataStructures/data.h"
#include "../DataStructures/statistics.h"

void dijkstra(int id, int number_vertices, double *dist, List **list)
{
    Wrapper *min_heap = PQ_init(number_vertices);

    for (int i = 0; i < number_vertices; i++)
    {
        dist[i] = (double)INT_MAX;
        PQ_insert(make_item(i, dist[i]), min_heap);
    }
    PQ_decrease_key(id, 0, min_heap);
    dist[id] = 0;

    while (!PQ_empty(min_heap))
    {
        Item min = PQ_delmin(min_heap);
        update_dist(list, min.id, dist, min_heap);
    }
    PQ_finish(min_heap);
}

double *dist_min_initialize(int size)
{
    double *dist_min = (double *)malloc(sizeof(double) * size);

    /* Inicializa vetor com 0 */
    for (int i = 0; i < size; i++)
    {
        dist_min[i] = 0;
    }

    return dist_min;
}