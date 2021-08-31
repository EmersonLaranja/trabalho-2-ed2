#ifndef READ_H
#define READ_H
#include "../DataStructures/data.h"
#include <stdlib.h>
#include <stdio.h>

/** Inicializa um arquivo em modo de leitura
 * @param[file] ponteiro tipo FILE a ser apontado para o arquivo.
 * @param[name] variável que possui nome do arquivo.
 * @return ponteiro para FILE representando arquivo a ser lido.
 **/
FILE *initialize_file(FILE *file, char *name);

/** Verifica tamanho dos argumentos
 * @param[num_args] variável que possui a quantidade de argumentos.
 **/
void verify_args_length(int num_args);

/** Verifica se um arquivo foi inicializado
 * @param[file] arquivo a ser lido.
 **/
void file_was_opened(FILE *file);

/** Lê o arquivo de entrada e preenche todas as dataStructures necessárias
 * @param[input_file] nome do arquivo de entrada.
 * @return ponteiro para Data com todos os dados do arquivo lidos.
 **/
Data *read_input_file(char *input_file);

/** Aloca um espaço para o buffer
 * @param[file] variavel representando arquivo de entrada.
 * @param[bufsize] variavel representando o tamanho do buffer.
 * @return buffer alocado.
 **/
char *define_buffer(FILE *file, size_t bufsize); //alloca um espaço para o buffer

/** Libera o espaço do buffer alocado
 * @param[buffer] variavel representando o buffer a ser liberado.
 **/
void destroy_buffer(char *buffer);

#endif /* READ_H */