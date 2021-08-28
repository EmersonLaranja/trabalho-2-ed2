#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

struct wrapper
{
    Item *pq;
    int *map;
    int N;
};

Item make_item(int id, double value) {
    Item t;
    id(t) = id;
    value(t) = value;
    return t;
}


void swap(int i, int j, Wrapper *wrapper)
{
    exch(wrapper->pq[i], wrapper->pq[j]);
    wrapper->map[id(wrapper->pq[i])] = i;
    wrapper->map[id(wrapper->pq[j])] = j;
}

void fix_up(int k, Wrapper *wrapper)
{
    Item *a = wrapper->pq;
    while (k > 1 && more(a[k / 2], a[k]))
    {
        swap(k, k / 2, wrapper);
        k = k / 2;
    }
}

void fix_down(int k, Wrapper *wrapper)
{
    Item *a = wrapper->pq;
    int sz = wrapper->N;
    while (2 * k <= sz)
    {
        int j = 2 * k;
        if (j < sz && more(a[j], a[j + 1]))
        {
            j++;
        }
        if (!more(a[k], a[j]))
        {
            break;
        }
        swap(k, j, wrapper);
        k = j;
    }
}

Wrapper *PQ_init(int maxN)
{
    Wrapper *wrapper = (Wrapper *)malloc(sizeof(Wrapper));
    wrapper->pq = (Item *)malloc((maxN + 1) * sizeof(Item));
    wrapper->map = (int *)malloc((maxN + 1) * sizeof(int));
    wrapper->N = 0;
    return wrapper;
}

void PQ_insert(Item v, Wrapper *wrapper)
{
    wrapper->N++;
    wrapper->pq[wrapper->N] = v;
    wrapper->map[id(v)] = wrapper->N;
    fix_up(wrapper->N, wrapper);
}

Item PQ_delmin(Wrapper *wrapper)
{
    Item min = wrapper->pq[1];
    swap(1, wrapper->N, wrapper);
    wrapper->N--;
    fix_down(1, wrapper);
    return min;
}

Item PQ_min(Wrapper *wrapper)
{
    return wrapper->pq[1];
}

void PQ_decrease_key(int id, double value, Wrapper *wrapper)
{
    int i = wrapper->map[id];
    value(wrapper->pq[i]) = value;
    fix_up(i, wrapper);
}

bool PQ_empty(Wrapper *wrapper)
{
    return wrapper->N == 0;
}

int PQ_size(Wrapper *wrapper)
{
    return wrapper->N;
}

void PQ_finish(Wrapper *wrapper)
{
    free(wrapper->pq);
    free(wrapper->map);
    free(wrapper);
}