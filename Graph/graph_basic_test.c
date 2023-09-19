#include    <stdio.h>
#include    <stdlib.h>
#include    "graph.h"

/* extern int     graph_create(graph*, int); */
/* extern void    graph_destroy(graph*); */
/* extern int     graph_add_edge(graph*, int, int); */
/* extern int     graph_has_edge(graph*, int, int); */
/* extern int     graph_remove_edge(graph*, int, int); */
/* extern void    graph_neighbours(graph*, int); */
/* extern void    graph_first_neighbour(graph*, int); */
/* extern void    graph_next_neighbour(graph*, int, int); */
/* extern void    graph_print(graph*); */

int main(void) 
{
    graph G;
    if (graph_create(&G, 5, UNDIRECTED_GRAPH) < 0) {
        printf("Error: graph_create failed\n");
        return -1;
    } 
    printf("graph_create success\n");
    graph_add_edge(&G, 0, 1);
    graph_add_edge(&G, 0, 2);
    graph_add_edge(&G, 0, 3);
    graph_add_edge(&G, 2, 4);
    graph_add_edge(&G, 3, 4);
    graph_add_edge(&G, 4, 1);
    graph_print(&G);
    printf("graph test neighbours\n");
    graph_neighbours(&G, 0);
    graph_neighbours(&G, 1);
    graph_neighbours(&G, 2);
    graph_neighbours(&G, 3);
    graph_neighbours(&G, 4);
    printf("graph test first neighbour\n");
    printf("first neighbour of 0 is %d\n", graph_first_neighbour(&G, 0));
    printf("first neighbour of 1 is %d\n", graph_first_neighbour(&G, 1));
    printf("first neighbour of 2 is %d\n", graph_first_neighbour(&G, 2));
    printf("first neighbour of 3 is %d\n", graph_first_neighbour(&G, 3));
    printf("first neighbour of 4 is %d\n", graph_first_neighbour(&G, 4));
    printf("-----------------------------\n");
    printf("graph test next neighbour\n");
    printf("next neighbour of 0 after 1 is %d\n", graph_next_neighbour(&G, 0, 1));
    printf("next neighbour of 0 after 2 is %d\n", graph_next_neighbour(&G, 0, 2));
    printf("next neighbour of 0 after 3 is %d\n", graph_next_neighbour(&G, 0, 3));
    printf("next neighbour of 1 after 0 is %d\n", graph_next_neighbour(&G, 1, 0));
    printf("next neighbour of 1 after 4 is %d\n", graph_next_neighbour(&G, 1, 4));
    printf("next neighbour of 2 after 0 is %d\n", graph_next_neighbour(&G, 2, 0));
    printf("next neighbour of 2 after 4 is %d\n", graph_next_neighbour(&G, 2, 4));
    printf("next neighbour of 3 after 0 is %d\n", graph_next_neighbour(&G, 3, 0));
    printf("-----------------------------\n");
    printf("graph test remove edge\n");
    printf("remove edge 0-1\n");
    graph_remove_edge(&G, 0, 1);
    printf("After remove edge 0-1\n");
    graph_print(&G);
    graph_destroy(&G);
}
