#include "data.h"
#include <stdlib.h>

struct data
{
  int *servers;
  int *clients;
  int *monitors;
  Edges *edges;
};

Data* alloc_data(){

  return (Data*) malloc(sizeof(Data));

}

void set_servers(Data* data, int* servers){
  data->servers = servers;
}

void set_clients(Data* data, int* clients){
  data->clients = clients;
}

void set_monitors(Data* data, int* monitors){
  data->monitors = monitors;
}

void set_edges(Data* data, Edges* edges){
  data->edges = edges;
}



