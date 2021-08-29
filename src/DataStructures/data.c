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
  int num_vertex;
};

Data *alloc_data()
{

  return (Data *)malloc(sizeof(Data));
}

void show_data(Data *data)
{
  show_component(data->servers);
  show_component(data->clients);
  show_component(data->monitors);
  show_array_list(data->edges, data->num_vertex);
}

void *destroy_data(Data *data)
{

  destroy_component(data->servers);
  destroy_component(data->clients);
  destroy_component(data->monitors);
  free_array_list(data->edges, data->num_vertex);
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

void set_num_vertex(Data *data, int num_vertex)
{
  data->num_vertex = num_vertex;
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

int get_num_edges(Data *data)
{
  return data->num_edges;
};
int get_num_vertex(Data *data)
{
  return data->num_vertex;
};
