#include "stack.h"
#include <string.h>

int bracket_check_array(char *brackets, int len)
{
    char bracket, pair, data[32];
    int i, index = 0;

    for (i = 0; i < len; i++) {
        bracket = brackets[i];
        if (bracket == '(' || bracket == '[' || bracket == '{') {
            data[index++] = bracket;
            printf("push: %c\n", bracket);
        } else {
            if (!index)
                return -1;
    
            pair = data[--index];
            if (bracket - pair > 2 || bracket - pair < 1)
                return -1;
            printf("pair: %c %c\n", pair, bracket);
        }
    }
    return !index;
}

int main(void) 
{
    int len, ret;
    char brackets[] = "({[]})";
    len = strlen(brackets);
    ret = bracket_check_array(brackets, len);
    if (ret != 1)
        printf("bracket check failed\n");
    return 0;

}
