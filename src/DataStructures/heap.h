#ifndef HEAP_H
#define HEAP_H

#include <stdbool.h>
#include "item.h"

typedef struct wrapper Wrapper;

Item get_item(Wrapper* wrapper, int index);
void set_map(Wrapper* wrapper, int index, int value);
Item make_item(int id, double value);
Wrapper* PQ_init(int maxN); // cria uma min PQ com capacidade maxN
void PQ_insert(Item v, Wrapper* wrapper);   // Insere Item na PQ. A maior prioridade é a do Item com menor campo 'value'
Item PQ_delmin(Wrapper* wrapper);       // Remove Item com menor campo 'value' da PQ
void PQ_decrease_key(int id, double value, Wrapper* wrapper); // Muda a prioridade do nó com identificador 'id' para 'value'
Item PQ_min(Wrapper* wrapper);          // Retorna Item com menor campo 'value' da PQ
void fix_down(int k, Wrapper* wrapper);
void fix_up(int k, Wrapper* wrapper);
bool PQ_empty(Wrapper* wrapper);        // Retorna True se a PQ não tem elementos
int  PQ_size(Wrapper* wrapper);         // Número de elementos na PQ
void PQ_finish(Wrapper* wrapper);       // Libera memória
bool is_in_min_heap(Wrapper* wrapper, int v);

#endif
