#include "statistics.h"
#include <stdlib.h>

struct statistics
{
    double **rtt_sc;
    double **rtt_sm;
    double **rtt_mc;
};

Statistics *create_statistics(int size_s, int size_m, int size_c)
{
    Statistics *stat = (Statistics *)malloc(sizeof(Statistics));

    stat->rtt_mc = (double **)malloc(sizeof(double *) * size_m);
    for (int i = 0; i < size_m; i++)
    {
        stat->rtt_mc[i] = (double *)malloc(sizeof(double) * size_c);
    }

    stat->rtt_sm = (double **)malloc(sizeof(double *) * size_s);
    for (int i = 0; i < size_s; i++)
    {
        stat->rtt_sm[i] = (double *)malloc(sizeof(double) * size_m);
    }

    stat->rtt_sc = (double **)malloc(sizeof(double *) * size_s);
    for (int i = 0; i < size_s; i++)
    {
        stat->rtt_sc[i] = (double *)malloc(sizeof(double) * size_c);
    }
    return stat;
}

void destroy_statistics(Statistics *stat, int size_s, int size_m, int size_c)
{
    for (int i = 0; i < size_m; i++)
    {
        free(stat->rtt_mc[i]);
    }
    free(stat->rtt_mc);

    for (int i = 0; i < size_m; i++)
    {
        free(stat->rtt_sm[i]);
    }
    free(stat->rtt_sm);
    
    for (int i = 0; i < size_c; i++)
    {
        free(stat->rtt_sc[i]);
    }
    free(stat->rtt_sc);
    
    free(stat);
}