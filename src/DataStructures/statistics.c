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
};

/* Calcula o RTT com relação a todos os monitores */
double calculate_relative_rtt(Statistics *stat, int pos_s, int pos_c)
{
    int min = (double)INT_MAX;
    double relative;
    for (int m = 0; m < stat->size_m; m++)
    {
        relative = stat->rtt_sm[pos_s][m] + stat->rtt_mc[pos_c][m];
        if (min > relative)
        {
            min = relative;
        }
    }
    return min;
}

double calculate_inflaction(Statistics *stat)
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
            stat->path_array[quant++] = path;
        }
    }
}

void order_path_array(Statistics *stat)
{
    int size_path = stat->size_s * stat->size_c;
    qsort(stat->path_array, size_path, sizeof(Path *), compare_path);
}

Statistics *create_statistics(Data *data)
{
    Statistics *stat = (Statistics *)malloc(sizeof(Statistics));

    stat->size_s = get_size_component(get_servers(data));
    stat->size_m = get_size_component(get_monitors(data));
    stat->size_c = get_size_component(get_clients(data));

    int size_path = stat->size_s * stat->size_c;
    Path **path_array = (Path **)malloc(size_path * sizeof(Path *));

    stat->rtt_mc = (double **)malloc(sizeof(double *) * stat->size_m);
    for (int i = 0; i < stat->size_m; i++)
    {
        stat->rtt_mc[i] = (double *)malloc(sizeof(double) * stat->size_c);
    }

    stat->rtt_sm = (double **)malloc(sizeof(double *) * stat->size_s);
    for (int i = 0; i < stat->size_s; i++)
    {
        stat->rtt_sm[i] = (double *)malloc(sizeof(double) * stat->size_m);
    }

    stat->rtt_sc = (double **)malloc(sizeof(double *) * stat->size_s);
    for (int i = 0; i < stat->size_s; i++)
    {
        stat->rtt_sc[i] = (double *)malloc(sizeof(double) * stat->size_c);
    }
    return stat;
}

// static void(double *dist_min, double **matrix, int size, );
// void calculate_distances(Statistics *stat, Data *data, Component *get_function(), int get_size())
// {
//     for (int i = 0; i < get_size(); i++)
//     {
//         int id = get_element_id_component(get_function(), i);
//         dijkstra(id, get_num_vertices(data), dist_min, get_edges(data));
//     }
// }

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
            stat->rtt_sc[i][k] = dist_min[pos];
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
            stat->rtt_sc[i][k] = dist_min[pos];
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
            stat->rtt_sc[k][i] = stat->rtt_sc[k][i] + dist_min[pos];
        }
        for (int k = 0; k < stat->size_m; k++)
        {
            int pos = get_element_id_component(get_monitors(data), k);
            stat->rtt_sm[k][i] = stat->rtt_sm[k][i] + dist_min[pos];
        }
    }

    free(dist_min);
}

void destroy_statistics(Statistics *stat)
{
    for (int i = 0; i < stat->size_m; i++)
    {
        free(stat->rtt_mc[i]);
    }
    free(stat->rtt_mc);

    for (int i = 0; i < stat->size_s; i++)
    {
        free(stat->rtt_sm[i]);
    }
    free(stat->rtt_sm);

    for (int i = 0; i < stat->size_s; i++)
    {
        free(stat->rtt_sc[i]);
    }
    free(stat->rtt_sc);

    // destroy_path_array(stat->path_array, (stat->size_c * stat->size_s));
    free(stat->path_array);
    free(stat);
}