#include <stdio.h>
#include "./IO/read.h"
#include "./DataStructures/data.h"
#include "./DataStructures/statistics.h"
#include "./IO/write.h"

int main(int argc, char **argv)
{
  Data *data = read_file(argv[1]);

  Statistics *statistics = create_statistics(data);

  calculate_distances(statistics, data);

  calculate_inflaction(statistics);

  order_path_array(statistics);

  output_statistics(statistics, argv[2]);

  destroy_statistics(statistics);
  destroy_data(data);
}
