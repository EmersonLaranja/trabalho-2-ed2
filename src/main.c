#include <stdio.h>
#include <time.h>
#include "./IO/read.h"
#include "./DataStructures/data.h"
#include "./DataStructures/statistics.h"
#include "./IO/write.h"

int main(int argc, char **argv)
{
  Data *data = read_input_file(argv[1]);
  Statistics *statistics = create_statistics(data);
  calculate_distances(statistics, data);
  calculate_inflaction(statistics, data);
  output_statistics(statistics, argv[2]);
  destroy_statistics(statistics);
  return 0;
}
