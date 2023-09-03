#ifndef     STACK_H
#define     STACK_H

#include    <stdio.h>
#include    <stdlib.h>
/* The type of element in stack */
#define     Elemtype                char   
/* The index of Elemtype in __ELEMTYPE_FORMAT__ */
#define     __ELEMTYPE__            0 
/* The spearator of each element when print stack */
#define     __FORMAT_SPEARATOR__    " "     
/* The number of Elemtype */
#define     NUM_ELEMTYPES           4       

/* The format of Elemtype */
typedef struct elem_tag {
    Elemtype data;    /* The data of element */
    struct elem_tag *next;
} elem_t;

/* The stack */
typedef struct stack_tag {
    int count;      /* The number of elements in stack */
    elem_t *head;
} stack_t;

/* Init stack
 * return 1 if success, otherwise return 0
 */
int initStack(stack_t *s);

/* Judge whether stack is empty */
int isStackEmpty(const stack_t *s);

/* Push element e into stack s
 * return 1 if success, otherwise return 0
 */
int push(stack_t *s, Elemtype e);

/* Pop element from stack s, and the element will be stored in e
 * return 1 if success, otherwise return 0
 */
int pop(stack_t *s, Elemtype *e);

/* Get the top element of stack s, and the element will be stored in e
 * return 1 if success, otherwise return 0
 */
int getTop(const stack_t *s, Elemtype *e);

/* Get the number of elements in stack s */
int stackSize(const stack_t *s);

/* Print stack s */
void printStack(const stack_t *s);

/* Free memory malloced for stack s
 * return 1 if success, otherwise return 0
 */
int freeStack(stack_t *s);
#endif
