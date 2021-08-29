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
  path->origin = destiny;
  path->inflaction = inflaction;

  return path;
}
Path **init_path(int size)
{
  return (Path **)malloc(size * sizeof(Path *));
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

int compare_path(const void *par1, const void *par2)
{
  /* *(Path **)par1 faz com que peguemos o conteúdo do ponteiro,
     * ou seja, é o Path* do vetor que é apontado por par1. */
  Path *p1 = *(Path **)par1;
  Path *p2 = *(Path **)par2;

  if (p1->inflaction > p2->inflaction)
  {
    return 1;
  }
  else if (p1->inflaction < p2->inflaction)
  {
    return -1;
  }
  else
  {
    return 0;
  }
}