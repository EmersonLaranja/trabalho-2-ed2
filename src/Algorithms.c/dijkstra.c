
// void dijkstra(Graph *graph, int src)
// {
//   int number_vertices_graph = get_size_graph(graph);
//   double *dist = (double *)malloc(sizeof(double) * number_vertices_graph);

//   Wrapper *min_heap = PQ_init(number_vertices_graph);

//   for (int i = 0; i < number_vertices_graph; i++)
//   {
//     dist[i] = FLT_MAX;
//     PQ_insert(make_item(i, dist[i]), min_heap);
//   }

//   PQ_decrease_key(src, 0, min_heap);

//   while (!PQ_empty(min_heap))
//   {

//     Item min = PQ_delmin(min_heap);
//     int id_min_node = min.id;

//     List *pCrawl = get_array_graph(graph, id_min_node);

//     while (pCrawl != NULL)
//     {

//       int dest = get_list_dest(pCrawl);

//       //!: fazer uma funÃ§ao retorna bool
//       /*v==dest u==id_min_node*/
//       if (is_in_min_heap(min_heap, dest) &&
//           dist[id_min_node] != FLT_MAX &&
//           get_list_weight(pCrawl) + dist[id_min_node] < dist[dest])
//       {
//         dist[dest] = dist[id_min_node] + get_list_weight(pCrawl);

//         PQ_decrease_key(dest, dist[dest], min_heap);
//       }
//       pCrawl = get_list_next(pCrawl);
//     }
//   }
//   printArr(dist, get_size_graph(graph));
// }





/*
double *dixcasca(int s, int V, list **grafo, double *dist_min) {

    dist_min[s] = 0;

    PQ_Struct *pq_struct = PQ_init(V);
    PQ_insert(make_item(s, 0), pq_struct);

    for (int i = 0; i < V; ++i) {
        if (i != s) {
            dist_min[i] = INT_MAX;
            PQ_insert(make_item(i, INT_MAX), pq_struct);
        }
    }

    while (!PQ_empty(pq_struct)) {
        Item u = PQ_delmin(pq_struct);
        for (node *p = grafo[u.id]->start; p != NULL; p = p->next) {
            double dist = dist_min[u.id] + p->vertice.value;
            if (dist < dist_min[p->vertice.id]) {
                dist_min[p->vertice.id] = dist;
                PQ_decrease_key(p->vertice.id, dist, pq_struct);
            }
        }
    }
*/