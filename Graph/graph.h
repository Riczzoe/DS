#ifndef     GRAPH_H
#define     GRAPH_H

#define     MAX_VERTICES        100
#define     UNDIRECTED_GRAPH    0
#define     DIRECTED_GRAPH      1
#define     NODE_TYPE           int
#define     NO_ADJACENCY        -1

typedef struct enode {
    NODE_TYPE data;
    struct enode* next;
} enode;

typedef struct vnode {
    NODE_TYPE data;
    struct enode* adjs;
} vnode;

typedef struct graph {
    int V;
    int E;
    int type;
    vnode* nodes;
} graph;

int         graph_create(graph*, int, int);
void        graph_destroy(graph*);
int         graph_add_edge(graph*, int, int);
int         graph_has_edge(graph*, int, int);
int         graph_remove_edge(graph*, int, int);
void        graph_neighbours(graph*, int);
NODE_TYPE   graph_first_neighbour(graph*, int);
NODE_TYPE   graph_next_neighbour(graph*, int, int);
void        graph_print(graph*);

#endif      // GRAPH_H
