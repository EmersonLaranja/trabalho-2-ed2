#ifndef COMPONENT_H
#define COMPONENT_H

typedef struct component Component;

/** Aloca uma struct Component
 * @param[size] variavel inteiro representando o tamanho do componente.
 * @param[vector] vetor de inteiros representando o componente.
 * @return ponteiro para Component inicializado.
 **/
Component *create_component(int size, int *vector);

/** Libera a memoria alocada para uma struct Component
 * @param[component] variavel tipo Component a ser desalocada.
 **/
void destroy_component(Component *component);

/** Retorna o id do componente na posição especificada
 * @param[component] componente a ser analisado.
 * @param[position] posicao do id no vetor de inteiro do componente.
 * @return id do componente na posicao.
 **/
int get_element_id_component(Component *component, int position);

/** Retorna o tamanho do vetor de inteiro do componente
 * @param[component] componente a ser analisado.
 * @return inteiro referente ao tamanho do vetor do compo.
 **/
int get_size_component(Component *component);

#endif