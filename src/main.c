#include <stdio.h>
#include "./IO/read.h"
#include "./DataStructures/data.h"
#include "./DataStructures/statistics.h"

int main(int argc, char **argv)
{

  Data *data = read_file(argv[1]);

  Statistics *statistics = create_statistics(data);
  // calculate_distances(statistics, data);
  // output_statistics(statistics);

  destroy_statistics(statistics);
  destroy_data(data);
}

// //depois jogamos isso pra algum arquivo

// int qtdServers = get_size_component(get_servers(data));
// int qtdMonitors = get_size_component(get_monitors(data));
// int qtdClients = get_size_component(get_clients(data));

// double rtt_sm[qtdServers][qtdMonitors];
// double rtt_mc[qtdMonitors][qtdClients];
// double rtt_sc[qtdServers][qtdClients];
// double *distances = (double *)malloc(sizeof(double) * get_num_vertices(data));

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