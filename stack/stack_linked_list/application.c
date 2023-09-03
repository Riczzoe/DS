#include "stack.h"

int bracket_check(char *brackets, int len)
{
    int i;
    char bracket, pair;
    stack_t stack;
    initStack(&stack);
    
    for (i = 0; i < len; i++) {
        bracket = brackets[i];
        if (bracket == '(' || bracket == '[' || bracket == '{') {
            push(&stack, bracket);
            printf("push: %c\n", bracket);
        } else {
            if (isStackEmpty(&stack))
                goto pairerr;

            pop(&stack, &pair);
            if (bracket - pair > 2 || bracket - pair < 1)
                goto pairerr;
            printf("pair: %c %c\n", pair, bracket);
        }
    }

    return isStackEmpty(&stack);

pairerr:
    return -1;
}

int main(int argc, char *argv[])
{
    int len, ret;
    char brackets[] = "({[]})";
    len = strlen(brackets);
    ret = bracket_check(brackets, len);
    if (!ret)
        printf("bracket check failed\n");
    return 0;
}
