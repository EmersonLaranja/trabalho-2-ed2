#include "data.h"
#include <stdlib.h>

struct data
{
  Component* servers;
  Component* clients;
  Component* monitors;
  Edges* edges;
  int num_edges;
};

Data* alloc_data(){

  return (Data*) malloc(sizeof(Data));

}
void* destroy_data(Data* data){
  
  destroy_component(data->servers);
  destroy_component(data->clients);
  destroy_component(data->monitors);
  destroy_edges(data->edges);
  free(data);
  
}

void set_servers(Data* data, Component* servers){
  data->servers = servers;
}

void set_clients(Data* data, Component* clients){
  data->clients = clients;
}

void set_monitors(Data* data, Component* monitors){
  data->monitors = monitors;
}

void set_edges(Data* data, Edges* edges){
  data->edges = edges;
}

void set_num_edges(Data* data, int num_edges){
  data->num_edges = num_edges;
}

void show_data(Data* data){
  show_component(data->servers);
  show_component(data->clients);
  show_component(data->monitors);
  show_edges(data->edges, data->num_edges);
}