#include    "stack.h"

int main() {
    stack_t stk;
    initStack(&stk);
    push(&stk, 1);
    push(&stk, 2);
    push(&stk, 3);
    push(&stk, 4);
    printf("Size: %d\n", stackSize(&stk));
    printStack(&stk);
    Elemtype e;
    pop(&stk, &e);
    printf("stack after popping: \n");
    printStack(&stk);
    pop(&stk, &e);
    printf("stack after popping: \n");
    printStack(&stk);
    return 0;
}
