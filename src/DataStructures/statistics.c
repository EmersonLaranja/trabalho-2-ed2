#include "statistics.h"
#include <stdlib.h>
#include <limits.h>
struct statistics
{
    double **rtt_sc;
    double **rtt_sm;
    double **rtt_mc;
    int size_s;
    int size_m;
    int size_c;
    Path **path_array;
    int size_path_array;
};

int get_size_array(Statistics* stat){
    return stat->size_path_array;
}

Path* get_current_path(Statistics *stat, int index){
    return stat->path_array[index];
}

/* Calcula o RTT com relação a todos os monitores */
double calculate_relative_rtt(Statistics *stat, int pos_s, int pos_c)
{
    double min = (double)INT_MAX;
    double relative;
    for (int m = 0; m < stat->size_m; m++)
    {
        relative = stat->rtt_sm[pos_s][m] + stat->rtt_mc[m][pos_c];
        if (min > relative)
        {
            min = relative;
        }
    }
    return min;
}

void calculate_inflaction(Statistics *stat)
{
    int quant = 0;
    double inflaction = 0;
    for (int s = 0; s < stat->size_s; s++)
    {
        for (int c = 0; c < stat->size_c; c++)
        {
            inflaction = calculate_relative_rtt(stat, s, c);
            inflaction /= stat->rtt_sc[s][c];

            Path *path = create_path(s, c, inflaction);
            stat->path_array[quant] = path;
            quant++;
        }
    }
}

void order_path_array(Statistics *stat)
{
    qsort(stat->path_array, stat->size_path_array, sizeof(Path *), compare_path);
}

double ** alloc_matrix(int num_l, int num_c){
    double** matrix = (double **)malloc(sizeof(double *) * num_l);
    for(int i = 0; i < num_l; i++){
        matrix[i] = (double *)malloc(sizeof(double) * num_c);
    }
    return matrix;
}

Statistics *create_statistics(Data *data)
{
    Statistics *stat = (Statistics *)malloc(sizeof(Statistics));

    stat->size_s = get_size_component(get_servers(data));
    stat->size_m = get_size_component(get_monitors(data));
    stat->size_c = get_size_component(get_clients(data));

    stat->size_path_array = stat->size_s * stat->size_c;
    stat->path_array = (Path **)malloc(stat->size_path_array * sizeof(Path *));


    stat->rtt_sm = alloc_matrix(stat->size_s,stat->size_m);
    stat->rtt_mc = alloc_matrix(stat->size_m,stat->size_c);
    stat->rtt_sc = alloc_matrix(stat->size_s,stat->size_c);

    return stat;
}

void imprimeMatriz(double** matriz, int linha, int coluna){
    for(int i = 0; i < linha; i++){
        for(int j = 0; j < coluna; j++){
            printf("%.16lf ", matriz[i][j]);
        }
        printf("\n");
    }
}

void calculate_distances(Statistics *stat, Data *data)
{
    double *dist_min = dist_min_initialize(get_num_vertices(data));

    for (int i = 0; i < stat->size_c; i++)
    {
        int id = get_element_id_component(get_clients(data), i);
        dijkstra(id, get_num_vertices(data), dist_min, get_edges(data));

        for (int k = 0; k < stat->size_s; k++)
        {
            int pos = get_element_id_component(get_servers(data), k);
            stat->rtt_sc[k][i] = dist_min[pos];
        }
        for (int k = 0; k < stat->size_m; k++)
        {
            int pos = get_element_id_component(get_monitors(data), k);
            stat->rtt_mc[k][i] = dist_min[pos];
        }
    }
    for (int i = 0; i < stat->size_m; i++)
    {
        int id = get_element_id_component(get_monitors(data), i);
        dijkstra(id, get_num_vertices(data), dist_min, get_edges(data));

        for (int k = 0; k < stat->size_s; k++)
        {
            int pos = get_element_id_component(get_servers(data), k);
            stat->rtt_sm[k][i] = dist_min[pos];
        }
        for (int k = 0; k < stat->size_c; k++)
        {
            int pos = get_element_id_component(get_clients(data), k);
            stat->rtt_mc[i][k] = stat->rtt_mc[i][k] + dist_min[pos];
        }
    }
    for (int i = 0; i < stat->size_s; i++)
    {
        int id = get_element_id_component(get_servers(data), i);
        dijkstra(id, get_num_vertices(data), dist_min, get_edges(data));

        for (int k = 0; k < stat->size_c; k++)
        {
            int pos = get_element_id_component(get_clients(data), k);
            stat->rtt_sc[i][k] = stat->rtt_sc[k][i] + dist_min[pos];
        }
        for (int k = 0; k < stat->size_m; k++)
        {
            int pos = get_element_id_component(get_monitors(data), k);
            stat->rtt_sm[i][k] = stat->rtt_sm[i][k] + dist_min[pos];
        }
    }
    printf("Matriz sm:\n");
    imprimeMatriz(stat->rtt_sm, stat->size_s, stat->size_m);
    printf("\nMatriz mc:\n");
    imprimeMatriz(stat->rtt_mc, stat->size_m, stat->size_c);
    printf("\nMatriz sc:\n");
    imprimeMatriz(stat->rtt_sc, stat->size_s, stat->size_c);

    free(dist_min);
}


void destroy_rtt(double** matrix, int size){

    for(int i = 0 ; i < size; i++){
        free(matrix[i]);
    }
    free(matrix);

}


void destroy_statistics(Statistics *stat)
{
    destroy_rtt(stat->rtt_mc, stat->size_m);
    destroy_rtt(stat->rtt_sm, stat->size_s);
    destroy_rtt(stat->rtt_sc, stat->size_s);

    destroy_path_array(stat->path_array, stat->size_path_array);

    free(stat->path_array);
    free(stat);
}