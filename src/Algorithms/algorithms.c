#include "algorithms.h"
#include "list.h"

void dijkstra(int id, List** list,  ){



}
// }



// void dijkstra(Graph *graph, int src)
// {
//   int number_vertices_graph = get_size_graph(graph);
//   double *dist = (double *)malloc(sizeof(double) * number_vertices_graph);

//   Wrapper *min_heap = PQ_init(number_vertices_graph);

//   for (int i = 0; i < number_vertices_graph; i++)
//   {
//     dist[i] = FLT_MAX;
//     PQ_insert(make_item(i, dist[i]), min_heap);
//   }

//   PQ_decrease_key(src, 0, min_heap);

//   while (!PQ_empty(min_heap))
//   {

//     Item min = PQ_delmin(min_heap);
//     int id_min_node = min.id;

//     List *pCrawl = get_array_graph(graph, id_min_node);

//     while (pCrawl != NULL)
//     {

//       int dest = get_list_dest(pCrawl);

//       //!: fazer uma funÃ§ao retorna bool
//       /*v==dest u==id_min_node*/
//       if (is_in_min_heap(min_heap, dest) &&
//           dist[id_min_node] != FLT_MAX &&
//           get_list_weight(pCrawl) + dist[id_min_node] < dist[dest])
//       {
//         dist[dest] = dist[id_min_node] + get_list_weight(pCrawl);

//         PQ_decrease_key(dest, dist[dest], min_heap);
//       }
//       pCrawl = get_list_next(pCrawl);
//     }
//   }
//   printArr(dist, get_size_graph(graph));
// }
