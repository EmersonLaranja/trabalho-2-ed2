#include <stdio.h>
#include "./IO/read.h"
#include "./DataStructures/data.h"

int main(int argc, char **argv)
{

  Data *data = read_file(argv[1]);

  show_data(data);

  //depois jogamos isso pra algum arquivo
  double rtt_sm[get_size_component(get_servers(data))][get_size_component(get_monitors(data))];
  double rtt_mc[get_size_component(get_monitors(data))][get_size_component(get_clients(data))];
  double rtt_sc[get_size_component(get_servers(data))][get_size_component(get_clients(data))];

  /*
Dijkstra logica



*/

  destroy_data(data);

  return 0;
}