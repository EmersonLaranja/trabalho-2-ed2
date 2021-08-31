#include "data.h"
#include "list.h"
#include <stdlib.h>

struct data
{
  Component *servers;
  Component *clients;
  Component *monitors;
  List **edges;
  int num_edges;
  int num_vertices;
};

Data *alloc_data()
{

  return (Data *)malloc(sizeof(Data));
}

void *destroy_data(Data *data)
{

  destroy_component(data->servers);
  destroy_component(data->clients);
  destroy_component(data->monitors);
  free_array_list(data->edges, data->num_vertices);
  free(data);
}

// --------------setters----------------
void set_servers(Data *data, Component *servers)
{
  data->servers = servers;
}

void set_clients(Data *data, Component *clients)
{
  data->clients = clients;
}

void set_monitors(Data *data, Component *monitors)
{
  data->monitors = monitors;
}

void set_edges(Data *data, List **edges)
{
  data->edges = edges;
}
void set_num_edges(Data *data, int num_edges)
{
  data->num_edges = num_edges;
}

void set_num_vertices(Data *data, int num_vertices)
{
  data->num_vertices = num_vertices;
}

// -------------getters----------
Component *get_servers(Data *data)
{
  return data->servers;
}

Component *get_clients(Data *data)
{
  return data->clients;
}

Component *get_monitors(Data *data)
{
  return data->monitors;
}

List **get_edges(Data *data)
{
  return data->edges;
}

int get_num_edges(Data *data)
{
  return data->num_edges;
};
int get_num_vertices(Data *data)
{
  return data->num_vertices;
};
