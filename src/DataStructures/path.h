#ifndef PATH_H
#define PATH_H
#include <stdio.h>
#include <stdlib.h>
typedef struct path Path;

/** Aloca uma struct Path
 * @param[origin] variavel inteira representando o vertice de origem.
 * @param[destiny] variavel inteira representando o vertice de destino.
 * @param[inflaction] variavel double representando a inflação entre os vertices.
 * @return ponteiro para Component inicializado.
 **/
Path *create_path(int origin, int destiny, double inflaction);

/** Desaloca uma struct Path
 * @param[path] array de path a ser desalocado.
 * @param[size] variavel inteira representando o tamanho do vetor.
 **/
void destroy_path_array(Path **path, int size);

/** Retorna um inteiro representando o vertice de origem
 * @param[path] path a ser analisado.
 * @return inteiro representando o vertice de origem.
 **/
int get_origin(Path *path);

/** Retorna um inteiro representando o vertice de destino
 * @param[path] path a ser analisado.
 * @return inteiro representando o vertice de destino.
 **/
int get_destiny(Path *path);

/** Retorna um double representando o a inflação entre os vertices
 * @param[path] path a ser analisado.
 * @return double representando o a inflação entre os vertices.
 **/
double get_inflaction(Path *path);

/** Função utilizada para ordenar o array de path
 * @param[ph1] representa a primeira path.
 * @param[ph2] representa a segunda path.
 * @return inteiro referente a como vai ser ordenado.
 **/
int compare_path(const void *ph1, const void *ph2);

#endif