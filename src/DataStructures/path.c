#include "path.h"

struct path
{
  int origin;
  int destiny;
  double inflaction;
};

Path *create_path(int origin, int destiny, double inflaction)
{
  Path *path = (Path *)malloc(sizeof(Path));
  path->origin = origin;
  path->destiny = destiny;
  path->inflaction = inflaction;

  return path;
}

void destroy_path_array(Path **path, int size)
{
  for (int i = 0; i < size; i++)
  {
    free(path[i]);
  }
}

// ------getters---------
int get_origin(Path *path)
{
  return path->origin;
}
int get_destiny(Path *path)
{
  return path->destiny;
}

double get_inflaction(Path *path)
{
  return path->inflaction;
}

int compare_path(const void *ph1, const void *ph2)
{
  /* *(Path **)ph1 faz com que peguemos o conteúdo do ponteiro,
     * ou seja, é o Path* do vetor que é apontado por ph1. */
  Path *p1 = *(Path **)ph1;
  Path *p2 = *(Path **)ph2;

  /* Ordem crescente */
  if (p1->inflaction > p2->inflaction) /* Primeiro criterio de ordenação: Inflação */
  {
    return 1;
  }
  else if (p1->inflaction < p2->inflaction)
  {
    return -1;
  }
  else
  {
    if (p1->origin > p2->origin)
    /* Segundo criterio de ordenação: Vertice de origem */
    {
      return 1;
    }
    else if (p1->origin < p2->origin)
    {
      return -1;
    }
    else
    { /* Terceiro criterio de ordenação: Vertice de destino */

      if (p1->destiny > p2->destiny)
      {
        return 1;
      }
      else if (p1->destiny < p2->destiny)
      {
        return -1;
      }
    }
  }
}