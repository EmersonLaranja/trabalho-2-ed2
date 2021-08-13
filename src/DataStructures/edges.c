#include "edges.h"
#include <stdlib.h>
#include <stdio.h>

struct edges
{
  int a;
  int b;
  double distance;
};


Edges* alloc_edges(){

  return (Edges*) malloc(sizeof(Edges));

}

Edges* read_edges(int num_edges, FILE* file){
  Edges* edges = (int*) malloc(sizeof(int)* num_edges);

  for(int i = 0; i < num_edges; i++){
      sscanf("%d %d %lf", &edges->a, &edges->b, &edges->distance);
  }
  
  return edges;
}

