#ifndef DATA_H
#define DATA_H
#include "component.h"
#include "list.h"

typedef struct data Data;


/**
 * Aloca um ponteiro para a estrutura Data.
 * @return ponteiro alocado da estrutura Data.
 **/
Data *alloc_data();

/**
 * Desaloca a memória de uma variável do tipo Data.
 * @param[data] variável a ser desalocada.
 **/
void *destroy_data(Data * data);

/**
 * Altera o valor do atributo servers da variável data  
 * @param[data] variável a ser alterada.
 * @param[servers] variável de referência.
 **/
void set_servers(Data *data, Component *servers);

/**
 * Altera o valor do atributo clients da variável data  
 * @param[data] variável a ser alterada.
 * @param[clients] variável de referência.
 **/
void set_clients(Data * data, Component * clients);

/**
 * Altera o valor do atributo monitors da variável data  
 * @param[data] variável a ser alterada.
 * @param[monitors] variável de referência.
 **/
void set_monitors(Data * data, Component * monitors);

/**
 * Altera o valor do atributo edges da variável data  
 * @param[data] variável a ser alterada.
 * @param[edges] variável de referência.
 **/
void set_edges(Data *, List **edges);

/**
 * Altera o valor do atributo num_edges da variável data  
 * @param[data] variável a ser alterada.
 * @param[num_edges] variável de referência.
 **/
void set_num_edges(Data * data, int num_edges);

/**
 * Altera o valor do atributo num_vertices da variável data  
 * @param[data] variável a ser alterada.
 * @param[num_vertices] variável de referência.
 **/
void set_num_vertices(Data * data, int num_vertices);

/**
 * Retorna o valor do atributo num_edges da variável data 
 * @param[data] variável a ser alterada.
 * @return valor inteiro do atributo num_edges.
 **/
int get_num_edges(Data * data);

/**
 * Retorna o valor do atributo num_vertices da variável data 
 * @param[data] variável a ser consultada.
 * @return valor inteiro do atributo num_vertices.
 **/
int get_num_vertices(Data * data);
/**
 * Retorna o atributo edges da variável data 
 * @param[data] variável a ser consultada.
 * @return ponteiro duplo de List representando o atributo edges.
 **/
List **get_edges(Data *data);

/**
 * Retorna o atributo servers da variável data 
 * @param[data] variável a ser consultada.
 * @return ponteiro simples de Component representando o atributo servers.
 **/
Component *get_servers(Data * data);

/**
 * Retorna o atributo clients da variável data 
 * @param[data] variável a ser consultada.
 * @return ponteiro simples de Component representando o atributo clients.
 **/
Component *get_clients(Data * data);

/**
 * Retorna o atributo monitors da variável data 
 * @param[data] variável a ser consultada.
 * @return ponteiro simples de Component representando o atributo monitors.
 **/
Component *get_monitors(Data * data);

#endif