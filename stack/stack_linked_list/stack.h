#ifndef     STACK_H
#define     STACK_H

#include    <stdio.h>
#include    <stdlib.h>

#define     Elemtype    int

typedef struct elem_tag elem_t;

typedef struct elem_tag {
    Elemtype data;
    elem_t *next;
} __un_usage_stack_list;

typedef struct stack_tag {
    int count;
    elem_t *head;
} stack_t;

int initStack(stack_t *s);
int isStackEmpty(const stack_t *s);
int push(stack_t *s, Elemtype e);
int pop(stack_t *s, Elemtype *e);
int getTop(const stack_t *s, Elemtype *e);
int stackSize(const stack_t *s);
void printStack(const stack_t *s);
#endif
