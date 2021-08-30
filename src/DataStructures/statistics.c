#include "statistics.h"
#include <stdlib.h>
#include <limits.h>
struct statistics
{
    double **rtt_sc;
    double **rtt_sm;
    double **rtt_cm;
    int size_s;
    int size_m;
    int size_c;
    Path **path_array;
    int size_path_array;
};

int get_size_array(Statistics *stat)
{
    return stat->size_path_array;
}

Path *get_current_path(Statistics *stat, int index)
{
    return stat->path_array[index];
}

/* Calcula o RTT com relação a todos os monitores */
double calculate_relative_rtt(Statistics *stat, int pos_s, int pos_c)
{
    double min = INT_MAX;
    double relative;
    for (int m = 0; m < stat->size_m; m++)
    {
        relative = stat->rtt_sm[pos_s][m] + stat->rtt_cm[pos_c][m];
        if (min > relative)
        {
            min = relative;
        }
    }
    return min;
}

void calculate_inflaction(Statistics *stat, Data *data)
{
    int quant = 0;
    double inflaction = 0;
    int id_services, id_clients;

    for (int s = 0; s < stat->size_s; s++)
    {
        for (int c = 0; c < stat->size_c; c++)
        {
            inflaction = calculate_relative_rtt(stat, s, c);
            inflaction /= stat->rtt_sc[s][c];

            id_services = get_element_id_component(get_servers(data), s);
            id_clients = get_element_id_component(get_clients(data), c);

            Path *path = create_path(id_services, id_clients, inflaction);
            stat->path_array[quant] = path;
            quant++;
        }
    }
}

void order_path_array(Statistics *stat)
{
    qsort(stat->path_array, stat->size_path_array, sizeof(Path *), compare_path);
}

double **alloc_matrix(int num_l, int num_c)
{
    double **matrix = (double **)malloc(sizeof(double *) * num_l);
    for (int i = 0; i < num_l; i++)
    {
        matrix[i] = (double *)malloc(sizeof(double) * num_c);
    }

    for (int i = 0; i < num_l; i++)
    {
        for (int j = 0; j < num_c; j++)
        {
            matrix[i][j] = 0;
        }
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

    stat->rtt_sm = alloc_matrix(stat->size_s, stat->size_m);
    stat->rtt_cm = alloc_matrix(stat->size_c, stat->size_m);
    stat->rtt_sc = alloc_matrix(stat->size_s, stat->size_c);

    return stat;
}

void imprimeMatriz(double **matriz, int linha, int coluna)
{
    for (int i = 0; i < linha; i++)
    {
        for (int j = 0; j < coluna; j++)
        {
            printf("%.16lf ", matriz[i][j]);
        }
        printf("\n");
    }
}

void fill_partially_rtt_c(Data *data, double *dist_min, double **rtt, int size, int i, Component *component)
{ // mantem fixa a coluna

    for (int k = 0; k < size; k++)
    {
        int pos = get_element_id_component(component, k);
        rtt[k][i] = rtt[k][i] + dist_min[pos];
    }
}

void fill_partially_rtt_l(Data *data, double *dist_min, double **rtt, int size, int i, Component *component)
{ //mantem fixa a linha

    for (int k = 0; k < size; k++)
    {
        int pos = get_element_id_component(component, k);
        rtt[i][k] = rtt[i][k] + dist_min[pos];
    }
}

// void

void calculate_distances(Statistics *stat, Data *data)
{
    double *dist_min = dist_min_initialize(get_num_vertices(data));

    for (int i = 0; i < stat->size_s; i++)
    {
        int id = get_element_id_component(get_servers(data), i);
        dijkstra(id, get_num_vertices(data), dist_min, get_edges(data));

        fill_partially_rtt_l(data, dist_min, stat->rtt_sm, stat->size_m, i, get_monitors(data));
        fill_partially_rtt_l(data, dist_min, stat->rtt_sc, stat->size_c, i, get_clients(data));
    }

    for (int i = 0; i < stat->size_c; i++)
    {
        int id = get_element_id_component(get_clients(data), i);
        dijkstra(id, get_num_vertices(data), dist_min, get_edges(data));

        fill_partially_rtt_l(data, dist_min, stat->rtt_cm, stat->size_m, i, get_monitors(data));
        fill_partially_rtt_c(data, dist_min, stat->rtt_sc, stat->size_s, i, get_servers(data));
    }

    for (int i = 0; i < stat->size_m; i++)
    {
        int id = get_element_id_component(get_monitors(data), i);
        dijkstra(id, get_num_vertices(data), dist_min, get_edges(data));

        fill_partially_rtt_c(data, dist_min, stat->rtt_sm, stat->size_s, i, get_servers(data));
        fill_partially_rtt_c(data, dist_min, stat->rtt_cm, stat->size_c, i, get_clients(data));
    }
    free(dist_min);
}

void destroy_rtt(double **matrix, int size)
{

    for (int i = 0; i < size; i++)
    {
        free(matrix[i]);
    }
    free(matrix);
}

void destroy_statistics(Statistics *stat)
{
    destroy_rtt(stat->rtt_cm, stat->size_c);
    destroy_rtt(stat->rtt_sm, stat->size_s);
    destroy_rtt(stat->rtt_sc, stat->size_s);

    destroy_path_array(stat->path_array, stat->size_path_array);

    free(stat->path_array);
    free(stat);
}