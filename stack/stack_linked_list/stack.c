#include    "stack.h"

int initStack(stack_t *s) {
    s->count = 0;
    s->head = NULL;
    return 1;
}

int isStackEmpty(const stack_t *s) {
    return !s->count;
}

int push(stack_t *s, Elemtype e) {
    elem_t *newElem = (elem_t *)malloc(sizeof(elem_t));
    if (!newElem)
        return 0;

    newElem->data = e;
    newElem->next = s->head;
    s->head = newElem;
    s->count++;
    return 1;
}

int pop(stack_t *s, Elemtype *e) {
    if (isStackEmpty(s))
        return 0;
    
    *e = s->head->data;
    elem_t *old = s->head;
    s->head = s->head->next;
    s->count--;
    free(old);
    return 1;
}

int getTop(const stack_t *s, Elemtype *e) {
    if (isStackEmpty(s))
        return 0;

    *e = s->head->data;
    return 1;
}

int stackSize(const stack_t *s) {
    return s->count;
}

void printStack(const stack_t *s) {
    printf("Top of stack:");
    elem_t *curr = s->head;

    while (curr) {
        printf(" %d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}
