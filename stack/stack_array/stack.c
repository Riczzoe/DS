#include    "stack.h"

void initStack(stack_t *s) {
    s->top = BOOTOM_STACK;
}

int isStackEmpty(const stack_t *s) {
    return s->top == BOOTOM_STACK;
}

static int isStackFull(const stack_t *s) {
    return s->top == MAXSIZE - 1;
}

int push(stack_t *s, Elemtype e) {
    if (isStackFull(s))
        return 0;
    s->data[++(s->top)] = e;
    return 1;
}

int pop(stack_t *s, Elemtype *e) {
    if (isStackEmpty(s))
        return 0;
    *e = s->data[(s->top)--];
    return 1;
}

int getTop(const stack_t *s, Elemtype *e) {
    if (isStackEmpty(s))
        return 0;
    *e = s->data[s->top];
    return 1;
}

int stackSize(const stack_t *s) {
    return s->top - BOOTOM_STACK;
}


void printStack(const stack_t *s) {
    int i;
    printf("Top of stack:");
    for (i = s->top; i > BOOTOM_STACK; i--) {
        printf(" %d ", s->data[i]);
    }
    printf("\n");
}
