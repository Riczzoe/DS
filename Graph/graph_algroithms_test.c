#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "graph_algroithms.h"

int main(void) 
{
    graph G;
    if (graph_create(&G, 5, UNDIRECTED_GRAPH) < 0) {
        printf("Error: graph_create failed\n");
        return -1;
    } 
    printf("graph_create success\n");
    graph_add_edge(&G, 0, 4);
    graph_add_edge(&G, 1, 5);
    graph_add_edge(&G, 2, 6);
    graph_add_edge(&G, 3, 7);

    graph_add_edge(&G, 5, 6);
    graph_add_edge(&G, 6, 7);
    graph_add_edge(&G, 0, 1);
    graph_add_edge(&G, 2, 5);
    graph_add_edge(&G, 2, 6);

    graph_add_edge(&G, 2, 6);
    graph_add_edge(&G, 2, 6);
    graph_add_edge(&G, 2, 6);





    graph_add_edge(&G, 0, 1);
    graph_add_edge(&G, 0, 2);
    graph_add_edge(&G, 0, 3);
    graph_add_edge(&G, 2, 4);
    graph_add_edge(&G, 3, 4);
    graph_add_edge(&G, 4, 1);
    graph_print(&G);

    BFS(&G, 0);
    DFS(&G, 0);
}
