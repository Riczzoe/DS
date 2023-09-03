#ifndef     STACK_H
#define     STACK_H

#include    <stdio.h>

#define     BOOTOM_STACK    -1
#define     MAXSIZE         50

// The element type of stack, optional char, int, float, string
#define     Elemtype        char
// format string index 0:char, 1:int, 2:float, 3:string
#define     __ELEMTYPE__    0
#define     __FORMAT_SPEARATOR__    " "
/* The number of Elemtype */
#define     NUM_ELEMTYPES           4       

typedef struct stack_tag {
    Elemtype data[MAXSIZE];
    int top;
} stack_t;

int isStackEmpty(const stack_t *s);
void initStack(stack_t *s);
int push(stack_t *s, Elemtype e);
int pop(stack_t *s, Elemtype *e);
int getTop(const stack_t *s, Elemtype *e);
int stackSize(const stack_t *s);
void printStack(const stack_t *s);

#endif
