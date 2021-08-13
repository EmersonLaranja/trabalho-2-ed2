#include "read.h"
#include <stdlib.h>
#include "../DataStructures/edges.h"

int* read_servers(int num_servers, FILE* file){
  int* servers = (int*) malloc(sizeof(int)* num_servers);

  for(int i = 0; i < num_servers; i++){
      sscanf("%d", servers[i]);
  }
  
  return servers;
}

int* read_clients(int num_clients, FILE* file){
  int* clients = (int*) malloc(sizeof(int)* num_clients);

  for(int i = 0; i < num_clients; i++){
      sscanf("%d", clients[i]);
  }

  return clients;
}

int* read_monitors(int num_monitors, FILE* file){
  int* monitors = (int*) malloc(sizeof(int)* num_monitors);

  for(int i = 0; i < num_monitors; i++){
      sscanf("%d", monitors[i]);
  }

  return monitors;
}


void file_was_opened(FILE *file)
{
  if (file == NULL)
  {
    printf("ERRO: falha na abertura do arquivo de entrada\n");
    exit(1);
  }
}

FILE* initialize_file(FILE *file, char *name)
{
  /* Inicializa arquivo em modo de leitura */
  file = fopen(name, "r");
  file_was_opened(file);

  return file;
}

void verify_args_length(int num_args)
{
  if (num_args < 3)
  {
    printf("ERRO: Quantidade de argumentos inválidos\n");
    exit(1);
  }

  if (num_args <= 1)
  {
    printf("ERRO: O diretorio de arquivos de configuracao nao foi informado\n");
    exit(1);
  }
}

char * define_buffer (FILE * file, size_t bufsize){
    char * buffer = NULL;
    buffer = (char *)malloc(bufsize * sizeof(char));
    return buffer;
}

Data* read_file(char* input_file){
  FILE* file; 
  initialize_file(file, input_file);
  size_t bufsize = 1;
  char * buffer = define_buffer(file, bufsize);

  Data* data = alloc_data();
  const char token = ' ';

  getline(&buffer, &bufsize, file);
  
  int num_vertex = atoi(strtok(buffer, token));
  int num_edges = atoi(strtok(NULL, token));

  getline(&buffer, &bufsize, file);

  int num_servers = atoi(strtok(buffer, token));
  int num_clients = atoi(strtok(NULL, token));
  int num_monitors = atoi(strtok(NULL, token));  
  
  int* servers = read_servers(num_servers, file);
  int* clients = read_clients(num_clients, file);
  int* monitors = read_monitors(num_monitors, file);
  Edges* edges = read_edges(num_edges, file);
  
  set_servers(data, servers);
  set_clients(data, clients);
  set_monitors(data, monitors);
  set_edges(data, edges);
 
  return data;  
}

