#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include <float.h>
#include "../DataStructures/heap.h"

void printArr(double dist[], int n)
{
  printf("Vertex   Distance from Source\n");
  for (int i = 0; i < n; ++i)
    printf("%d \t\t %.16lf\n", i, dist[i]);
}

void dijkstra(Graph *graph, int src)
{

  int number_vertices_graph = get_size_graph(graph);
  double *dist = (double *)malloc(sizeof(double) * number_vertices_graph);

  Wrapper *min_heap = PQ_init(number_vertices_graph);

  for (int i = 0; i < number_vertices_graph; i++)
  {
    dist[i] = FLT_MAX;
    PQ_insert(make_item(i, dist[i]), min_heap);
  }

  PQ_decrease_key(src, 0, min_heap);

  while (!PQ_empty(min_heap))
  {

    Item min = PQ_delmin(min_heap);
    int id_min_node = min.id;

    List *pCrawl = get_array_graph(graph, id_min_node);

    while (pCrawl != NULL)
    {

      int dest = get_list_dest(pCrawl);

      //!: fazer uma funÃ§ao retorna bool
      /*v==dest u==id_min_node*/
      if (is_in_min_heap(min_heap, dest) &&
          dist[id_min_node] != FLT_MAX &&
          get_list_weight(pCrawl) + dist[id_min_node] < dist[dest])
      {
        dist[dest] = dist[id_min_node] + get_list_weight(pCrawl);

        PQ_decrease_key(dest, dist[dest], min_heap);
      }
      pCrawl = get_list_next(pCrawl);
    }
  }
  printArr(dist, get_size_graph(graph));
}

int main(int argc, char **argv)
{
  int V = 9;
  Graph *graph = create_graph(V);
  add_edge(graph, 0, 1, 4);
  add_edge(graph, 0, 7, 8);
  add_edge(graph, 1, 2, 8);
  add_edge(graph, 1, 7, 11);
  add_edge(graph, 2, 3, 7);
  add_edge(graph, 2, 8, 2);
  add_edge(graph, 2, 5, 4);
  add_edge(graph, 3, 4, 9);
  add_edge(graph, 3, 5, 14);
  add_edge(graph, 4, 5, 10);
  add_edge(graph, 5, 6, 2);
  add_edge(graph, 6, 7, 1);
  add_edge(graph, 6, 8, 6);
  add_edge(graph, 7, 8, 7);

  dijkstra(graph, 0);

  return 0;
}