#ifndef     QUEUE_H
#define     QUEUE_H

#include    <stdio.h>
#include    <stdlib.h>

/* You can change the type of element in queue here.
 * And you should change the Elemtype and __ELEMTYPE__.
 * 
 * The relationship between Elemtype and __ELEMTYPE__:
 * Elemtype    __ELEMTYPE__
 * char        0
 * int         1
 * float       2
 * char *      3
 */
/* The type of element in queue */
#define     Elemtype            void *
/* The index of Elemtype in __ELEMTYPE_FORMAT__ */
#define     __ELEMTYPE__            1

/* The spearator of each element when print queue */
#define     __FORMAT_SPEARATOR__    " "
/* The number of Elemtype supported */
#define     NUM_ELEMTYPES           4

/*
 * the node of queue
 */
typedef struct queue_node {
    struct queue_node *next;    /* point to the next node */
    Elemtype data;              /* the data of the node */
} queueNode_t;

/*
 * the queue
 */
typedef struct queue_tag {
    queueNode_t *sentinel;      /* the sentinel of the queue */
    queueNode_t *last;          /* the last node of the queue */
    int size;                   /* the size of the queue */
} queue_t;

/*
 * init the queue
 * If success, return 1; else return 0
 */
int initQueue(queue_t * q);

/* Judge the queue is empty or not */
int isQueueEmpty(const queue_t *q);

/* add the element e to the queue 
 * If success, return 1; else return 0
 */
int enQueue(queue_t *q, Elemtype e);

/* delete the first element of the queue
 * and store the element to e.
 * If success, return 1; else return 0
 */
int deQueue(queue_t *q, Elemtype *e);

/* get the first element of the queue
 * and store the element to e.
 */
void getHead(const queue_t *q, Elemtype *e);

/* get the last element of the queue
 * and store the element to e.
 */
void getLast(const queue_t *q, Elemtype *e);

/* print the queue */
void printQueue(const queue_t *q);

/* get the size of the queue */
int getQueueSize(const queue_t *q);

/* free the memory of the queue allocated */
int freeQueue(queue_t *q);

#endif
