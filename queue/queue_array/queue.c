#include     "queue.h"


int initQueue(queue_t * q) {
    q->front = q->back = q->size = 0;
    return 1;
}

int isQueueEmpty(const queue_t *q) {
    return !q->size;
}

static int __isQueueFull__(queue_t *q) {
    return q->size == MAXSIZE - 1;
}

int enQueue(queue_t *q, Elemtype e) {
    if (__isQueueFull__(q))
        return 0;

    int back = q->back;
    q->data[back] = e;
    q->back = ++back % MAXSIZE;
    q->size++;
    return 1;
}

int deQueue(queue_t *q, Elemtype *e) {
    if (isQueueEmpty(q))
        return 0;
    
    int front = q->front;
    *e = q->data[front];
    q->front = ++front % MAXSIZE;
    q->size--;
    return 1;
}

void getHead(const queue_t *q, Elemtype *e) {
    if (isQueueEmpty(q))
        return;
    
    *e = q->data[q->front];
}

void getLast(const queue_t *q, Elemtype *e) {
    if (isQueueEmpty(q))
        return;

    *e = q->data[q->back - 1];
}

void printQueue(const queue_t *q) {
    int size = q->size;
    int front = q->front;
    int i;
    printf("Front of Queue: ");

    for (i = front; i < size + front; i++) {
        printf(" %d ", q->data[i % MAXSIZE]);
    }
    printf("\n");
}

