#ifndef     STACK_H
#define     STACK_H

#include    <stdio.h>

#define     BOOTOM_STACK    -1
#define     MAXSIZE         50
#define     Elemtype        int

typedef struct stack_tag {
    Elemtype data[MAXSIZE];
    int top;
} stack_t;

int isStackEmpty(const stack_t *s);
int isStackFull(const stack_t *s);
void initStack(stack_t *s);
int push(stack_t *s, Elemtype e);
int pop(stack_t *s, Elemtype *e);
int getTop(const stack_t *s, Elemtype *e);
int stackSize(const stack_t *s);
void printStack(const stack_t *s);

#endif
