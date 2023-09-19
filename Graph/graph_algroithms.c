#include <stdio.h>
#include "queue.h"
#include "graph.h"

int marked[MAX_VERTICES];

static void init_marked() {
    int i;
    for (i = 0; i < MAX_VERTICES; i++)
        marked[i] = 0;
}

void BFS(graph* G, int v) {
    queue_t queue;
    NODE_TYPE node;

    if (!G)
        return;
    if (v >= G->V)
        return;
    
    init_marked();
    marked[v] = 1;

    if (!initQueue(&queue)) {
        printf("Queue init failed!\n");
        return;
    }
    printf("BFS: ");
    enQueue(&queue, v);
    printf("%d", v);

    while (!isQueueEmpty(&queue)) {
        deQueue(&queue, &v);
        for (node = graph_first_neighbour(G, v); node != NO_ADJACENCY; 
                node = graph_next_neighbour(G, v, node)) {
            if (!marked[node]) {
                marked[node] = 1;
                enQueue(&queue, node);
                printf(" %d", node);
            }
        }
    }
    printf("\n");
}
