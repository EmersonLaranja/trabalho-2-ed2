#include <stdio.h>
#include "./IO/read.h"
#include "./DataStructures/data.h"
#include "./DataStructures/statistics.h"
#include "./IO/write.h"

void output_statistics(Statistics* stat, char* output_file){
    /* Inicializa arquivo em modo de escrita */
    FILE * file;
    file = fopen(output_file, "w");

    if (file == NULL){
        printf("Arquivo não pode ser criado.\n");
        exit(1);
    }

    int size = get_size_array(stat);
    printf("%d", size);
    Path* current_path;
    for(int i = 0; i < size; i++){
        current_path = get_current_path(stat, i);
        fprintf(file, "%d %d %.16lf\n", get_origin(current_path), get_destiny(current_path), get_inflaction(current_path));
    }
    fclose(file);
}

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
