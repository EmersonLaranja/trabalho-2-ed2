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
    double min = INT_MAX; /* Inicializando com valor muito grande */
    double relative;
    for (int m = 0; m < stat->size_m; m++)
    {
        /* Calcula o rtt relativo, que é a soma do rtt do servidor e cliente,
         * mantem os indices de servidor e cliente fixo e pelo indice de todos os monitores */
        relative = stat->rtt_sm[pos_s][m] + stat->rtt_cm[pos_c][m];
        /* Caso o novo valor relativo calculado seja menor que o 'min' atual, min pega o valor de relative */
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

    for (int s = 0; s < stat->size_s; s++) /* Perorre pelos indices de todos os servidores */
    {
        for (int c = 0; c < stat->size_c; c++) /* Perorre pelos indices de todos os clientes */
        {
            inflaction = calculate_relative_rtt(stat, s, c);
            /* Pra obter o calculo da inflacao, divide o RTT estimado pelo RTT direto entre os dois vertices */
            inflaction /= stat->rtt_sc[s][c];

            id_services = get_element_id_component(get_servers(data), s);
            id_clients = get_element_id_component(get_clients(data), c);

            /* Cria estrutura contendo o vertice de origem, destino e a inflacao entre eles, e armazena no array */
            Path *path = create_path(id_services, id_clients, inflaction);
            stat->path_array[quant] = path;
            quant++;
        }
    }
    destroy_data(data);
}

void order_path_array(Statistics *stat)
{
    /* Faz a ordenação vetor de Path utilizando a funcao compare_path como parametro */
    qsort(stat->path_array, stat->size_path_array, sizeof(Path *), compare_path);
}

double **alloc_matrix(int num_l, int num_c)
{
    double **matrix = (double **)malloc(sizeof(double *) * num_l);
    for (int i = 0; i < num_l; i++)
    {
        matrix[i] = (double *)malloc(sizeof(double) * num_c);
    }

    /* Inicializa a matriz com 0 */
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
    /* Aloca a memoria de acordo com os dados armazenados em data */
    Statistics *stat = (Statistics *)malloc(sizeof(Statistics));

    stat->size_s = get_size_component(get_servers(data));
    stat->size_m = get_size_component(get_monitors(data));
    stat->size_c = get_size_component(get_clients(data));

    /* Aloca vetor de estrurua responsável por conter a inflacao entre os vertices */
    stat->size_path_array = stat->size_s * stat->size_c;
    stat->path_array = (Path **)malloc(stat->size_path_array * sizeof(Path *));

    /* Aloca matriz RTT */
    stat->rtt_sm = alloc_matrix(stat->size_s, stat->size_m);
    stat->rtt_cm = alloc_matrix(stat->size_c, stat->size_m);
    stat->rtt_sc = alloc_matrix(stat->size_s, stat->size_c);

    return stat;
}

void fill_partially_rtt_c(Data *data, double *dist_min, double **rtt, int size, int i, Component *component)
{ /* Mantem fixa a coluna */
    for (int k = 0; k < size; k++)
    {
        int pos = get_element_id_component(component, k);
        rtt[k][i] += dist_min[pos]; /* Soma o valor do rtt atual com a distancia minima calculada */
    }
}

void fill_partially_rtt_l(Data *data, double *dist_min, double **rtt, int size, int i, Component *component)
{ /* Mantem fixa a linha */

    for (int k = 0; k < size; k++)
    {
        int pos = get_element_id_component(component, k);
        rtt[i][k] += dist_min[pos]; /* Soma o valor do rtt atual com a distancia minima calculada */
    }
}

void calculate_distances_s(Statistics *stat, Data *data, double *dist_min)
{
    for (int i = 0; i < stat->size_s; i++)
    {
        /* Faz Dijkstra com relação ao id de cada componente de servidores */ 
        int id = get_element_id_component(get_servers(data), i);
        dijkstra(id, get_num_vertices(data), dist_min, get_edges(data));

        /* Preenche as RTT's do servidor, com relação a monitor e cliente */
        fill_partially_rtt_l(data, dist_min, stat->rtt_sm, stat->size_m, i, get_monitors(data));
        fill_partially_rtt_l(data, dist_min, stat->rtt_sc, stat->size_c, i, get_clients(data));
    }
}
void calculate_distances_c(Statistics *stat, Data *data, double *dist_min)
{
    for (int i = 0; i < stat->size_c; i++)
    {
        /* Faz Dijkstra com relação ao id de cada componente de clientes */
        int id = get_element_id_component(get_clients(data), i);
        dijkstra(id, get_num_vertices(data), dist_min, get_edges(data));

        /* Preenche a RTT's do cliente, com relação a monitor e servidor */
        fill_partially_rtt_l(data, dist_min, stat->rtt_cm, stat->size_m, i, get_monitors(data));
        fill_partially_rtt_c(data, dist_min, stat->rtt_sc, stat->size_s, i, get_servers(data));
    }
}
void calculate_distances_m(Statistics *stat, Data *data, double *dist_min)
{
    for (int i = 0; i < stat->size_m; i++)
    {
        /* Faz Dijkstra com relação ao id de cada componente de monitores */
        int id = get_element_id_component(get_monitors(data), i);
        dijkstra(id, get_num_vertices(data), dist_min, get_edges(data));

        /* Preenche a RTT's do monitor, com relação a servidor e cliente */
        fill_partially_rtt_c(data, dist_min, stat->rtt_sm, stat->size_s, i, get_servers(data));
        fill_partially_rtt_c(data, dist_min, stat->rtt_cm, stat->size_c, i, get_clients(data));
    }
}

void calculate_distances(Statistics *stat, Data *data)
{
    /* Aloca vetor de distancias minimas */
    double *dist_min = dist_min_initialize(get_num_vertices(data));

    /* Calcula as distancias minimas pra servidor, monitor e cliente */
    calculate_distances_s(stat, data, dist_min);
    calculate_distances_m(stat, data, dist_min);
    calculate_distances_c(stat, data, dist_min);

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
    /* Libera toda a memoria alocada na struct Statistics */
    destroy_rtt(stat->rtt_cm, stat->size_c);
    destroy_rtt(stat->rtt_sm, stat->size_s);
    destroy_rtt(stat->rtt_sc, stat->size_s);

    destroy_path_array(stat->path_array, stat->size_path_array);

    free(stat->path_array);
    free(stat);
}