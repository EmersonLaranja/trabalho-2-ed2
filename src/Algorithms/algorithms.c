#include "algorithms.h"
#include <limits.h>
#include <stdio.h>
#include "../IO/read.h"
#include "../DataStructures/data.h"

/* Retirar o Edge / Criar Hash? */
void dijkstra(int id, int number_vertices, double *dist, List **list)
{

    Wrapper *min_heap = PQ_init(number_vertices);

    for (int i = 0; i < number_vertices; i++)
    {
        dist[i] = INT_MAX;
        PQ_insert(make_item(i, dist[i]), min_heap);
    }
    PQ_decrease_key(id, 0, min_heap);

    while (!PQ_empty(min_heap))
    {
        Item min = PQ_delmin(min_heap);
        update_dist(list, min.id, dist, min_heap);
    }
    PQ_finish(min_heap);
    free(min_heap);
}

int main(int argc, char **argv)
{
    Data *data = read_file(argv[1]);

    show_data(data);

    int S = get_size_component(get_servers(data));
    int M = get_size_component(get_monitors(data));
    int C = get_size_component(get_clients(data));
    int num_vertices = get_num_vertex(data);

    double* dist_min = (double*)malloc(sizeof(double) * num_vertices);

    // for(int i = 0; i < S; i++){
        
    //     int element_id = get_element_id_component(get_servers(data), i);
    //     // dist_min = dijkstra(element_id, num_vertices,  );
    // }

    // for(int i = 0; i < M; i++){
        
    // }
    
    // for(int i = 0; i < C; i++){
        
    // }
    destroy_data(data);
    return 0;
}
