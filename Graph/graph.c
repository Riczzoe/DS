#include "graph.h"
#include <stdio.h>
#include <stdlib.h>

/*
 * create_graph() - create a graph with V vertices
 *
 * Return:
 *  0  - success
 *  -1 - failure
 */
int graph_create(graph* G, int V, int type)
{
    int i;

    if (!G)
        return -1;
    if (V > MAX_VERTICES) {
        printf("Error: too many vertices, max is %d\n", MAX_VERTICES);
        return -1;
    }

    /* allocate memory for the stored nodes */
    G->V = V;
    G->type = type;
    G->nodes = (vnode *)malloc(V * sizeof(vnode));   
    if (!G->nodes) {
        printf("Error: malloc failed\n");
        return -1;
    }

    /* initialize the nodes, set the adjacencies to NULL */
    for (i = 0; i < V; i++)
        G->nodes[i].adjs = NULL;
    return 0;
}

/*
 * destroy_graph() - destroy a graph, free all memory
 */
void graph_destroy(graph* G) 
{
    int i;
    
    if (!G)
        goto donothing;
    if (!G->nodes)
        goto donothing;

    for (i = G->V - 1; i >= 0; i--) {
        if (G->nodes[i].adjs) 
            free(G->nodes[i].adjs);
    }
    free(G->nodes);

donothing:
    return;
}

/*
 * graph_add_edge() - If G is an undirected graph and there is no edge between
 * x and y(i.e. never call this function with "graph_add_edge(G, x, y)" or 
 * "graph_add_edge(G, y, x)" before), add an edge between x and y.
 *
 * If G is an directed graph and there is no edge from x to y, add an edge from
 * x to y.
 *
 * Return:
 *   0 - success
 *  -1 - failure
 */
int graph_add_edge(graph* G, int x, int y) 
{
    enode* temp;
    int times, inttemp;

    if (!G)
        return -1;
    if (x >= G->V || y >= G->V)
        return -1;
    if (x == y) {
        printf("Error: self loop is not allowed\n");
        return 0;
    }
    if (graph_has_edge(G, x, y)) {
        printf("Error: edge %d %s %d already exists\n", x, G->type ? "->" : "-", y);
        return 0;
    }
    
    times = 0;

undirected_add_second:
    temp = (enode *)malloc(sizeof(enode));
    if (!temp) {
        printf("Error: malloc failed\n");
        return -1;
    }

    temp->data = y;
    temp->next = G->nodes[x].adjs;
    G->nodes[x].adjs = temp;

    if (G->type == UNDIRECTED_GRAPH && times == 0) {
        times++;
        inttemp = x;
        x = y;
        y = inttemp;
        goto undirected_add_second;
    }

    return 0;
}

/*
 * graph_has_edge() - If G is an undirected graph, check if there is an edge
 * between x and y. If G is a directed graph, check if there is an edge from x
 * to y.
 *
 * Return:
 *   1 - there is an edge
 *   0 - there is no edge
 *  -1 - error
 */
int graph_has_edge(graph* G, int x, int y) 
{
    enode *temp;
    int times, inttemp;

    if (!G)
        return -1;
    if (x >= G->V || y >= G->V)
        return -1;

    times = 0;
undirected_check_second:
    /* Check if there is an edge from x to y */
    for (temp = G->nodes[x].adjs; temp; temp = temp->next) {
        if (temp->data == y)
            return 1;
    }

    if (G->type == UNDIRECTED_GRAPH && times == 0) {
        times++;
        inttemp = x;
        x = y;
        y = inttemp;
        goto undirected_check_second;
    }

    return 0;
}

/*
 * graph_remove_edge() - If G is an undirected graph, remove the edge between x
 * and y. If G is a directed graph, remove the edge from x to y.
 *
 * Return:
 *  0 - failure
 *  1 - success
 * -1 - error
 */
int graph_remove_edge(graph* G, int x, int y) 
{
    /* The "temp" pointer points to the *address* of the node that contains the
     * data "y".
     *
     * The "needdel" pointer points to the node that contains the data "y".
     */
    enode **temp, *needdel;
    int times;

    if (!G)
        return -1;
    if (x >= G->V || y >= G->V)
        return -1;
    if (!graph_has_edge(G, x, y)) {
        printf("Error: edge %d %s %d does not exist\n", x, G->type ? "->" : "-", y);
        return 0;
    }

    times = 1;
    temp = &(G->nodes[x].adjs);

undirected_remove_second:
    /* Walk through the adjacency list of node x, looking for the thing that
     * points to the node that contains the data "y".
     */
    while (*temp && (*temp)->data != y)
        temp = &(*temp)->next;

    /* If we reach the end of the list, it means that there is no edge from x
     * to y
     */
    if (!*temp) {
        /* If G is an undirected graph, we have done */
        if (G->type == UNDIRECTED_GRAPH) {
            printf("Error: edge %d %s %d does not exist\n", x, G->type ? "->" : "-", y);
            return 0;
        }

        /* If G is a directed graph, we need to check if there is an edge from y
         * to x
         */
        if (times == 0) {
            temp = &(G->nodes[y].adjs);
            times++;
            y = x;
            goto undirected_remove_second;
        }


        return 0;

    }

    /* Found it, just remove it and free the memory */
    needdel = *temp;
    *temp = (*temp)->next;
    free(needdel);

    return 1;
}

void graph_neighbours(graph* G, int v) 
{
    enode* temp;

    if (!G)
        return;
    if (v >= G->V) {
        printf("Error: node %d does not exist\n", v);
        return;
    }

    printf("The neighbours of node %d are: ", v);
    for (temp = G->nodes[v].adjs; temp; temp = temp->next) {
        printf("%d ", temp->data);
    }
    printf("\n");
}

NODE_TYPE graph_first_neighbour(graph* G, int v) 
{
    if (!G)
       return 0;
    if (v >= G->V)
        return 0;

    return G->nodes[v].adjs ? G->nodes[v].adjs->data : -1;
}


NODE_TYPE graph_next_neighbour(graph* G, int x, int y) 
{
    enode* temp;

    if (!G)
       return -1;
    if (x >= G->V || y >= G->V)
        return -1;
    
    for (temp = G->nodes[x].adjs; temp; temp = temp->next) {
        if (temp->data == y)
            break;
    }

    if (!temp || !temp->next)
        return -1;

    return temp->next->data;
}

void graph_print(graph* G) 
{
    int i;
    enode* temp;

    if (!G)
        return;

    printf("The graph is:\n");
    for (i = 0; i < G->V; i++) {
        printf("%d: ", i);
        for (temp = G->nodes[i].adjs; temp; temp = temp->next) {
            printf("%d %s %d, ", i, G->type ? "->" : "-", temp->data);
        }
        printf("\n");
    }
}

