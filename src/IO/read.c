#include "read.h"
#include "../DataStrutures/data.h"

void file_was_opened(FILE *file)
{
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
  if (num_args < 4)
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

// void read_file(char *file_name)
// {
//   FILE *file = fopen()
// }
