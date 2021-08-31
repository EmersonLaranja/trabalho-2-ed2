#ifndef ALGORITHMS_H
#define ALGORITHMS_H
#include "../DataStructures/list.h"

/** Preenche o vetor de distancias minimas usando a estrutura heap
 * @param[id] indice do componente a ser avaliado.
 * @param[number_vertices] inteiro representando o numero de vertices total.
 * @param[dist] vetor que será preenchido com as minimas distancias.
 * @param[list] vetor que representa a lista de adjacencias.
 **/
void dijkstra(int id, int number_vertices, double *dist, List **list);
/** Aloca um espaço de memória para um vetor double de distancias minimas
 * @param[size] inteiro representando o tamanho do componente.
 * @return ponteiro para um vetor de double inicializado.
 **/
double *dist_min_initialize(int size);

#endif