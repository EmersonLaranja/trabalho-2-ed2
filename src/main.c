#include <stdio.h>
#include <time.h>
#include "./IO/read.h"
#include "./DataStructures/data.h"
#include "./DataStructures/statistics.h"
#include "./IO/write.h"

int main(int argc, char **argv)
{
  clock_t start, stop;
  start = clock();

  Data *data = read_file(argv[1]);

  Statistics *statistics = create_statistics(data);

  calculate_distances(statistics, data);

  calculate_inflaction(statistics, data);

  order_path_array(statistics);

  output_statistics(statistics, argv[2]);

  destroy_statistics(statistics);

  destroy_data(data);
  stop = clock();
  double time_taken = ((double)stop - start) / CLOCKS_PER_SEC;
  printf(" %.4f\n", time_taken);

  return 0;
}
