#include    "stack.h"

/* 
 * The following array is used to define the format of Elemtype.
 * For example, if Elemtype is int, then __ELEMTYPE__ is 1, 
 * and __ELEMTYPE_FORMAT__[__ELEMTYPE__] is "%d".
 */
static const char* __ELEMTYPE_FORMAT__[NUM_ELEMTYPES] = {
    "%c",   /* If Elemtype is char, then use %c to print */
    "%d",   /* If Elemtype is int, then use %d to print */
    "%f",   /* If Elemtype is float, then use %f to print */
    "%s",   /* If Elemtype is char*, then use %s to print */
};

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

static void __getElemtypeFormat__(char * const format) {
    sprintf(format, "%s%s%s", __FORMAT_SPEARATOR__,
            __ELEMTYPE_FORMAT__[__ELEMTYPE__],
            __FORMAT_SPEARATOR__);
}

int freeStack(stack_t *s) {
    elem_t *curr = s->head;
    while (curr) {
        elem_t *old = curr;
        curr = curr->next;
        free(old);
    }
    s->count = 0;
    s->head = NULL;
    return 1;
}
        

void printStack(const stack_t *s) {
    printf("Top of stack:");
    elem_t *curr = s->head;
    char format[32];
    __getElemtypeFormat__(format);

    while (curr) {
        printf(format, curr->data);
        curr = curr->next;
    }
    printf("\n");
}
