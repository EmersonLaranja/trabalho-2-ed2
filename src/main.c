#include <stdio.h>
#include "./IO/read.h"
#include "./DataStructures/data.h"

int main(int argc, char **argv)
{

  Data* data = read_file(argv[1]);

  show_data(data);

  
  destroy_data(data);

  return 0;
}