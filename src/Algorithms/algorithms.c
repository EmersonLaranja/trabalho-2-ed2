#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include <limits.h>
#include "../DataStructures/heap.h"

void dijkstra(Graph *graph, int src)
{

  int number_vertices_graph = get_size_graph(graph);
  double *dist = (double *)malloc(sizeof(double) * number_vertices_graph);

  Wrapper *minHeap = PQ_init(number_vertices_graph);

  for (int i = 0; i < number_vertices_graph; i++)
  {
    dist[i] = INT_MAX;
    PQ_insert(make_item(i, dist[i]), minHeap);
  }

  PQ_decrease_key(src, 0, minHeap);

  while (!PQ_empty(minHeap))
  {

    Item min = PQ_delmin(minHeap);
    int id_min_node = min.id;    

    List* pCrawl = get_array_graph(graph, id_min_node);

    while(pCrawl!= NULL){

      int dest = get_list_dest(pCrawl);

      //if(dist[id_min_node]!=INT_MAX &&){ }

      



    }

  }
}

int main(int argc, char **argv)
{

  return 0;
}