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

static void __getElemtypeFormat__(char * const format) {
    sprintf(format, "%s%s%s", __FORMAT_SPEARATOR__,
            __ELEMTYPE_FORMAT__[__ELEMTYPE__],
            __FORMAT_SPEARATOR__);
}

void printStack(const stack_t *s) {
    int i;
    printf("Top of stack:");
    char format[32];
    __getElemtypeFormat__(format);
    for (i = s->top; i > BOOTOM_STACK; i--) {
        printf(format, s->data[i]);
    }
    printf("\n");
}
