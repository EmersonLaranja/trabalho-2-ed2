#ifndef STATISTICS_H
#define STATISTICS_H
#include "../Algorithms/algorithms.h"
#include "path.h"
#include "data.h"

typedef struct statistics Statistics;

Statistics *create_statistics(Data *data);
int get_size_array(Statistics *stat);
Path *get_current_path(Statistics *stat, int index);
void destroy_statistics(Statistics *stat);
void calculate_inflaction(Statistics *stat, Data *data);
void calculate_distances(Statistics *stat, Data *data);
void order_path_array(Statistics *stat);

#endif