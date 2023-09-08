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

static int infix2postfix(char *expr, int n)
{
    
}

int reverse_polish_notation_eval(char *expr, int len) 
{
    int i;
    stack_t numbers;
    
    for (i = 0; i < len; i++) {
        if 
    }
    retrun 1;
}

int main(int argc, char *argv[])
{
    int len, ret;

    printf("Start bracket check\n");
    char brackets[] = "({[]})";
    printf("brackets: %s\n", brackets);
    len = strlen(brackets);
    ret = bracket_check(brackets, len);
    if (ret != 1)
        printf("bracket check failed\n");
    else
        printf("bracket check success\n");

    printf("start postfix expression evaluation test\n");
    printf("test: ((15/(7-(1+1)))*3)-(2+(1+1))");
    char expr[] = "15 7 1 1 + - / 3 * 2 1 1 + + -";


    return 0;
}
