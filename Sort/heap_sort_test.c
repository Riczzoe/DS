#include "sort.h"
#include "sort_test.h"

int main() 
{
    int need_test_func[] = {
        HEAP_SORT_PQ,
        HEAP_SORT,
    };
    test_sort(need_test_func, sizeof(need_test_func)/sizeof(int));
    return 0;
}
