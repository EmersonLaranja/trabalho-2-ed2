#include <stdio.h>
#include <time.h>
#include "./IO/read.h"
#include "./DataStructures/data.h"
#include "./DataStructures/statistics.h"
#include "./IO/write.h"

int main(int argc, char **argv)
{
  Data *data = read_input_file(argv[1]);            /* Lê os dados de entrada e armazena em data */
  Statistics *statistics = create_statistics(data); /* Aloca memoria pra struct Statistics */
  calculate_distances(statistics, data);            /* Calcula as distancias e armazena nos RTT's */
  calculate_inflaction(statistics, data);           /* Faz o calculo da inflacao entre os vertices */
  output_statistics(statistics, argv[2]);           /* Escreve os dados calculados em um arquivo de saida */
  destroy_statistics(statistics);                   /* Libera toda a memoria alocada */
  return 0;
}
