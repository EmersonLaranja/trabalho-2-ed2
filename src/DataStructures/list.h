#ifndef LIST_H
#define LIST_H

#include "item.h"

#include "item.h"
#include "heap.h"

typedef struct list List;
typedef struct node Node;

/**
 * Inicializa lista encadeada.
 * @return ponteiro simples de Lista representando lista inicializada.
 **/
List *init_list();

/** Insere novo nó na lista encadeada
 * @param[list] variável a ser alterada.
 * @param[vertices] variável a ser inserida como atributo.
 * @return ponteiro simples de Lista representando lista alterada.
 **/
List *insert_node(List *list, Item vertices);

/** Recupera item de um nó.
 * @param[node] variável a ser consultada.
 * @return variavel do tipo Item representando o atributo vertices da variavel node
 **/
Item return_item(Node *node);

/** Desaloca memória alocada em list.
 * @param[list] variável a ser liberada.
 **/
void free_list(List *list);

/** Desaloca memória alocada em list.
 * @param[list] variável a ser liberada.
 * @param[size] tamanho da lista.
 **/
void free_array_list(List **list, int size);

/** Atualiza vetor de distancias mínimas, alterando também a posição relativa dos nós no heap.
 * @param[list] variável a ser percorrida.
 * @param[id_min] id do nó.
 * @param[min_dist] vetor de distâncias minimas.
 * @param[min_heap] heap.
 **/
void update_dist(List **list, int id_min, double *min_dist, Wrapper *min_heap);

/** Lê o arquivo de entrada capturando todas as arestas
 * @param[num_edges] número de arestas.
 * @param[num_vertices] número de vértices.
 * @param[file] arquivo a ser lido.
 * @return ponteiro duplo de List representando as arestas.
 **/
List **read_edges(int num_edges, int num_vertices, FILE *file);
#endif