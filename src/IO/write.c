#include "write.h"

void output_statistics(Statistics *stat, char *file_name)
{
    order_path_array(stat);

    /* Inicializa arquivo em modo de escrita */
    FILE *file;
    file = fopen(file_name, "w");

    if (file == NULL)
    {
        printf("Arquivo não pode ser criado.\n");
        exit(1);
    }

    int size = get_size_array(stat);
    Path *current_path;
    double inflaction;
    for (int i = 0; i < size; i++) /* Percorre todo o array de path */
    {
        current_path = get_current_path(stat, i);
        inflaction = get_inflaction(current_path);
        /* Caso a representação inteira da inflação seja equivalente a sua ao double, imprime com menos casas decimais */
        if ((int)inflaction == inflaction)
        {
            fprintf(file, "%d %d %.1lf\n", get_origin(current_path), get_destiny(current_path), inflaction);
        }
        else /* Caso contrario, imprime com 16 casas decimais  */
        {
            fprintf(file, "%d %d %.16lf\n", get_origin(current_path), get_destiny(current_path), inflaction);
        }
    }
    fclose(file);
}