#include    "queue.h"

/* Define the Placeholder for printf */
static const char* __ELEMTYPE_FORMAT__[NUM_ELEMTYPES] = {
    "%c",   /* If Elemtype is char */
    "%d",   /* If Elemtype is int */
    "%f",   /* If Elemtype is float */
    "%s",   /* If Elemtype is string */
};

int initQueue(queue_t *q) {
    queueNode_t *sentinel = (queueNode_t *)malloc(sizeof(queueNode_t));
    if (!sentinel)
        return 0;

    sentinel->next = NULL;
    q->sentinel = sentinel;
    q->last = sentinel;
    q->size = 0;
    return 1;
}

int isQueueEmpty(const queue_t *q) {
    return !q->size;
}

int enQueue(queue_t *q, Elemtype e) {
    queueNode_t *newNode = (queueNode_t *)malloc(sizeof(queueNode_t));
    if (!newNode) 
        return 0;

    newNode->data = e;
    q->last->next = newNode;
    q->last = newNode;
    q->size++;
    return 1;
}

int deQueue(queue_t *q, Elemtype *e) {
    if (isQueueEmpty(q))
        return 0;

    queueNode_t *nodeNeedDelet = q->sentinel->next;
    *e = nodeNeedDelet->data;
    q->sentinel->next = nodeNeedDelet->next;
    q->size--;
    free(nodeNeedDelet);
    return 1;
}

void getHead(const queue_t *q, Elemtype *e) {
    if (isQueueEmpty(q))
        return;

    *e = q->sentinel->next->data;
}

void getLast(const queue_t *q, Elemtype *e) {
    if (isQueueEmpty(q))
        return;

    *e = q->last->data;
}

/* get the placeholder according to the Elemtype */
static void __getPrintfPlaceholder__(char * const format) {
    sprintf(format, "%s%s%s", __FORMAT_SPEARATOR__,
            __ELEMTYPE_FORMAT__[__ELEMTYPE__],
            __FORMAT_SPEARATOR__);
}

void printQueue(const queue_t *q) {
    queueNode_t *curr = q->sentinel->next;

    printf("Front of queue:");
    char format[32];
    __getPrintfPlaceholder__(format);
    while (curr) {
        printf(format, curr->data);
        curr = curr->next;
    }
    printf("\n");
}

int getQueueSize(const queue_t *q) {
    return q->size;
}

int freeQueue(queue_t *q) {
    queueNode_t *curr = q->sentinel->next;
    queueNode_t *next = NULL;

    while (curr) {
        next = curr->next;
        free(curr);
        curr = next;
    }

    free(q->sentinel);
    q->sentinel = NULL;
    q->last = NULL;
    q->size = 0;
    return 1;
}


