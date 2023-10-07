#define RADIX 10
#include <stdio.h>

static int find_max(int *elems, int len)
{
    int i, max = elems[0];

    for (i = 0; i < len; i++) {
        if (elems[i] > elems[max]) 
            max = i;
    }
    return max;
}

static void counting_sort(int *elems, int len, int significant) 
{
    int counts[RADIX] = {0};
    int start_point[RADIX] = {0};
    int aux[len];
    int i, digit;

    for (i = 0; i < len; i++) {
        digit = (elems[i] / significant) % RADIX;
        counts[digit]++;
    }

    for (i = 1; i < RADIX; i++) 
        start_point[i] = start_point[i - 1] + counts[i - 1];

    for (i = 0; i < len; i++) {
        digit = (elems[i] / significant) % RADIX;
        aux[start_point[digit]] = elems[i];
        start_point[digit]++;
    }
    
    for (i = 0; i < len; i++) 
        elems[i] = aux[i];
}

void radix_sort(int *elems, int len)
{
    int max, significant;
    max = elems[find_max(elems, len)];

    for (significant = 1; max / significant > 0; significant *= RADIX) {
        counting_sort(elems, len, significant);
    }
}
