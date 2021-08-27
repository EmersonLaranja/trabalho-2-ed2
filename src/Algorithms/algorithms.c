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

  for(int i = 0; i< number_vertices_graph; i++){

    dist[i] = INT_MAX; 



  }






}

int main(int argc, char **argv)
{

  return 0;
}