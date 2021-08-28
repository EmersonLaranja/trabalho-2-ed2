#include "edges.h"
#include <stdlib.h>

struct edges
{
  int a;
  int b;
  double distance;
};

Edges *alloc_edges()
{
  return (Edges *)malloc(sizeof(Edges));
}

void destroy_edges(Edges *edges)
{
  free(edges);
}

Edges *read_edges(int num_edges, FILE *file)
{
  Edges *edges = (Edges *)malloc(sizeof(Edges) * num_edges);

  for (int i = 0; i < num_edges; i++)
  {
    fscanf(file, "%d %d %lf", &edges[i].a, &edges[i].b, &edges[i].distance);
  }

  return edges;
}

void show_edges(Edges *edges, int num_edges)
{
  for (int i = 0; i < num_edges; i++)
  {
    printf("%d %d %.17lf\n", edges[i].a, edges[i].b, edges[i].distance);
  }
}