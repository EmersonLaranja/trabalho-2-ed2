#ifndef STATISTICS_H
#define STATISTICS_H
#include "../Algorithms/algorithms.h"
#include "path.h"
#include "data.h"

typedef struct statistics Statistics;

/** Inicializa uma estrutura Statistics.
 * @param[data] ponteiro tipo Data com os dados de entrada.
 * @return ponteiro para Statistics representando a estrutura de saida com os dados finais.
 **/
Statistics *create_statistics(Data *data);
/** Retorna o valor do atributo size_path_array da variável stat
 * @param[stat] variável a ser alterada.
 * @return valor inteiro do atributo size_path_array.
 **/
int get_size_array(Statistics *stat);
/** Retorna o valor do atributo path_array da variável stat
 * @param[stat] variável a ser alterada.
 * @return ponteiro Path do atributo path_array.
 **/
Path *get_current_path(Statistics *stat, int index);
/**
 * Desaloca a memória de uma variável do tipo Statistics.
 * @param[stat] variável a ser desalocada.
 **/
void destroy_statistics(Statistics *stat);
/** Calcula a inflação para cada estrutura Path.
 * @param[stat] ponteiro tipo Statistics com os dados de entrada.
 * @param[data] ponteiro tipo Data com os dados de entrada.
 **/
void calculate_inflaction(Statistics *stat, Data *data);
/** Calcula a distancia minimas e preenche a devida rtt.
 * @param[stat] ponteiro tipo Statistics com os dados de entrada.
 * @param[data] ponteiro tipo Data com os dados de entrada.
 **/
void calculate_distances(Statistics *stat, Data *data);
/** Faz a ordenação vetor de Path de acordo com valor da inflação.
 * @param[stat] ponteiro tipo Statistics com os dados de entrada.
 **/
void order_path_array(Statistics *stat);

#endif