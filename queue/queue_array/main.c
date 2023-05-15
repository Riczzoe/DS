#include    "queue.h"

int main() {
    queue_t q;
    initQueue(&q);
    enQueue(&q, 1);
    enQueue(&q, 2);
    enQueue(&q, 3);
    enQueue(&q, 4);
    printf("Size: %d\n", q.size);
    printQueue(&q);
    Elemtype e;
    deQueue(&q, &e);
    printf("Queue after deQueue: \n");
    printQueue(&q);
    deQueue(&q, &e);
    printf("Queue after deQueue: \n");
    printQueue(&q);
    return 0;
}
