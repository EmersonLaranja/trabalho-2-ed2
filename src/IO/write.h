#ifndef WRITE_H
#define WRITE_H

#include "../DataStructures/statistics.h"

/** Inicializa um arquivo de saida
 * @param[stat] variável que possui dados estatisticos pedidos.
 * @param[file] ponteiro tipo FILE a ser apontado para o arquivo.
 **/
void output_statistics(Statistics *stat, char *file);

#endif
