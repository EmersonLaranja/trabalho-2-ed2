#ifndef STATISTICS_H
#define STATISTICS_H
#include "../Algorithms/algorithms.h"
#include "path.h"
#include "data.h"

typedef struct statistics Statistics;

Statistics *create_statistics(Data *data);
void destroy_statistics(Statistics *stat);
void calculate_inflaction(Statistics *stat);
void calculate_distances(Statistics *stat, Data *data);

#endif