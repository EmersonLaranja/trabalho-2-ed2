#include <stdio.h>
#include "./IO/read.h"
#include "./DataStructures/data.h"
//se der problema trocar a ordem de insercao na lista


int main(int argc, char **argv)
{

  Data *data = read_file(argv[1]);

  show_data(data);

  




  destroy_data(data);
  return 0;
}


// //depois jogamos isso pra algum arquivo

  // int qtdServers = get_size_component(get_servers(data));
  // int qtdMonitors = get_size_component(get_monitors(data));
  // int qtdClients = get_size_component(get_clients(data));

  // double rtt_sm[qtdServers][qtdMonitors];
  // double rtt_mc[qtdMonitors][qtdClients];
  // double rtt_sc[qtdServers][qtdClients];
  // double *distances = (double *)malloc(sizeof(double) * get_num_vertex(data));

  // for (int i = 0; i < qtdServers; i++)
  // {
  //   // distances = dijkstra retornando as distancias minimas

  //   //S2C
  //   for (int j = 0; j < qtdClients; j++)
  //   {
  //     // rtt_sc[i][j] = distances[vetor_de_clientes_na_posicao_i]
  //   }
  //   //S2M
  //   for (int j = 0; j < qtdMonitors; j++)
  //   {
  //     // rtt_sc[i][j] = distances[vetor_de_monitores_na_posicao_i]
  //   }
  // }
  // free(distances);