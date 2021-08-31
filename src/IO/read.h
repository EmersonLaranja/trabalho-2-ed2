#ifndef READ_H
#define READ_H
#include "../DataStructures/data.h"
#include <stdlib.h>
#include <stdio.h>

FILE *initialize_file(FILE *file, char *name);   // Inicializa arquivo em modo de leitura
void verify_args_length(int num_args);           //retorna uma mensagem de erro caso não haja argumentos suficientes para execução do programa
void file_was_opened(FILE *file);                //verifica se um arquivo foi inicializado
Data *read_input_file(char *input_file);         //lê o arquivo de entrada e preenche todas as dataStructures necessárias
char *define_buffer(FILE *file, size_t bufsize); //alloca um espaço para o buffer
void destroy_buffer(char *);                     //libera o espaço do buffer alocado

#endif /* READ_H */