#ifndef     QUEUE_H
#define     QUEUE_H

#include    <stdio.h>

#define     MAXSIZE     50
#define     Elemtype    int

typedef struct queue_tag {
    int front;
    int back;
    int size;
    Elemtype data[MAXSIZE];
} queue_t;

int initQueue(queue_t * q);
int isQueueEmpty(const queue_t *q);
int enQueue(queue_t *q, Elemtype e);
int deQueue(queue_t *q, Elemtype *e);
void getHead(const queue_t *q, Elemtype *e);
void getLast(const queue_t *q, Elemtype *e);
void printQueue(const queue_t *q);

#endif
