#include <string.h>
#include "read.h"
#include "../DataStructures/component.h"

int *read_servers(int num_servers, FILE *file)
{
  int *servers = (int *)malloc(sizeof(int) * num_servers);

  for (int i = 0; i < num_servers; i++)
  {
    fscanf(file, "%d", &servers[i]);
  }

  return servers;
}

int *read_clients(int num_clients, FILE *file)
{
  int *clients = (int *)malloc(sizeof(int) * num_clients);

  for (int i = 0; i < num_clients; i++)
  {
    fscanf(file, "%d", &clients[i]);
  }

  return clients;
}

int *read_monitors(int num_monitors, FILE *file)
{
  int *monitors = (int *)malloc(sizeof(int) * num_monitors);

  for (int i = 0; i < num_monitors; i++)
  {
    fscanf(file, "%d", &monitors[i]);
  }

  return monitors;
}

List **init_edges_array(List **edges, int num_vertices)
{
  for (int i = 0; i < num_vertices; i++)
  {
    edges[i] = NULL; //necessario para verificar se uma lista de edge já foi inicializada
  }
}

List *create_edge_list(List *edge, int destine, double weight)
{

  if (edge == NULL)
  { //se o edge de origin nao existe
    edge = init_list();
  }
  edge = insert_node(edge, make_item(destine, weight)); //inserindo todos destinos de um mesmo origin
  return edge;
}

List **read_edges(int num_edges, int num_vertices, FILE *file)
{
  List **edges = (List **)malloc(sizeof(List *) * num_vertices);
  init_edges_array(edges, num_vertices);

  int origin, destine;
  double weight;
  /* Lê o vertice de origem, destino e o peso entre eles e armazena na lista */
  for (int i = 0; i < num_edges; i++)
  {
    fscanf(file, "%d %d %lf", &origin, &destine, &weight);
    edges[origin] = create_edge_list(edges[origin], destine, weight);
  }

  return edges;
}

void file_was_opened(FILE *file)
{
  /* Caso ocorra erro ao tentar ler arquivo */
  if (file == NULL)
  {
    printf("ERRO: falha na abertura do arquivo de entrada\n");
    exit(1);
  }
}

FILE *initialize_file(FILE *file, char *name)
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

char *define_buffer(FILE *file, size_t bufsize)
{
  /* Define o buffer utilizado para leitura dos dados */
  char *buffer = NULL;
  buffer = (char *)malloc(bufsize * sizeof(char));
  return buffer;
}

void destroy_buffer(char *buffer)
{
  free(buffer);
}

Data *read_input_file(char *input_file)
{
  FILE *file;
  file = initialize_file(file, input_file);
  size_t bufsize = 1;
  char *buffer = define_buffer(file, bufsize);

  Data *data = alloc_data();
  const char *token = " "; /* Delimitador */

  /* Lê a primeira linha do arquivo, que contem o numero de vertices e arestas */
  getline(&buffer, &bufsize, file);

  int num_vertices = atoi(strtok(buffer, token));
  int num_edges = atoi(strtok(NULL, token));

  /* Armazena em data os dois dados lidos */
  set_num_edges(data, num_edges);
  set_num_vertices(data, num_vertices);

  /* Lê a segunda linha do arquivo, que contem o numero de servidores, clientes e monitores */
  getline(&buffer, &bufsize, file);

  int num_servers = atoi(strtok(buffer, token));
  int num_clients = atoi(strtok(NULL, token));
  int num_monitors = atoi(strtok(NULL, token));

  destroy_buffer(buffer);

  /* Faz a leitura de todos os servidores */
  int *vet_servers = read_servers(num_servers, file);
  Component *servers = create_component(num_servers, vet_servers);

  /* Faz a leitura de todos os clientes */
  int *vet_clients = read_clients(num_clients, file);
  Component *clients = create_component(num_clients, vet_clients);

  /* Faz a leitura de todos os monitores */
  int *vet_monitors = read_monitors(num_monitors, file);
  Component *monitors = create_component(num_monitors, vet_monitors);

  /* Lê os dados do grafo e armazena em uma lista de adjacências */
  List **edges = read_edges(num_edges, num_vertices, file);

  /* Armazena todos os dados na struct data */
  set_servers(data, servers);
  set_clients(data, clients);
  set_monitors(data, monitors);
  set_edges(data, edges);

  fclose(file);

  return data;
}
