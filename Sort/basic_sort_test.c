#include <stdio.h>
#include "sort.h"
#include "sort_test.h"

int main() {
    int i;
    int need_test_func[] = {
        SELECTION_SORT, 
        INSERTION_SORT,
        SHELL_SORT,
        MERGE_SORT,
        MERGE_SORT_DT,
    };
    test_sort(need_test_func, sizeof(need_test_func) / sizeof(int));
    return 0;
}

