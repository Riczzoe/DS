#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
#include <string.h>

static char *sort_names[] = {
    "Selection Sort",
    "Insertion Sort",
    "Shell Sort",
    "Merge Sort",
    "Merge Sort Down Top",
};

static void (*sort_functions[])(int *, int) = {
    selection_sort,
    insertion_sort,
    shell_sort,
    merge_sort,
    merge_sort_dt,
};


static int is_sorted(int *arr, int len) 
{
    for (int i = 1; i < len; i++) {
        if (arr[i] < arr[i - 1])
            return 0;
    }
    return 1;
}

static void print_result(const char* subTest, int passed) 
{
    if (passed) {
        printf("\033[32m\u2713\033[0m %s Passed\n", subTest);
    } else {
        printf("\033[31m\u2717\033[0m %s Failed\n", subTest);
    }
}

static int sort_and_check(int *arr, int len, const char *subTest, 
        void (*sort)(int *, int)) {
    if (arr && len > 0) {
        sort(arr, len);
    }
    int sorted = is_sorted(arr, len);
    print_result(subTest, sorted);
    return sorted;
}

static int test_sort(void (*sort)(int *, int), char *name) 
{
    int passed = 1;
    printf("\033[32m--------------------------\n");
    printf("Testing\033[31m %s\n", name);
    printf("\033[32m--------------------------\033[0m\n");

    int test1[] = {5, 4, 3, 2, 1};
    int test2[] = {1, 2, 3, 4, 5};
    int test3[] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
    int test4[] = {7, 7, 7, 7, 7, 7, 7, 7, 7};
    int test5[] = {1, 2, 3, 4, 5, 5, 4, 3, 2, 1};
    int *test6 = NULL;
    int test7[] = {42};
    
    int len1 = sizeof(test1) / sizeof(test1[0]);
    int len2 = sizeof(test2) / sizeof(test2[0]);
    int len3 = sizeof(test3) / sizeof(test3[0]);
    int len4 = sizeof(test4) / sizeof(test4[0]);
    int len5 = sizeof(test5) / sizeof(test5[0]);
    int len7 = sizeof(test7) / sizeof(test7[0]);

    int results[8];
    results[0] = sort_and_check(test1, len1, "Test 1 (Reverse Order)", sort);
    results[1] = sort_and_check(test2, len2, "Test 2 (Already Sorted)", sort);
    results[2] = sort_and_check(test3, len3, "Test 3 (Random Order)", sort);
    results[3] = sort_and_check(test4, len4, "Test 4 (All Same)", sort);
    results[4] = sort_and_check(test5, len5, "Test 5 (Palindromic Array)", sort);
    results[5] = sort_and_check(test6, 0, "Test 6 (Empty Array)", sort);
    results[6] = sort_and_check(test7, len7, "Test 7 (Single Element)", sort);

    int len8 = 1000;
    int *test8 = (int *)malloc(len8 * sizeof(int));
    for (int i = 0; i < len8; i++) {
        test8[i] = rand() % 5000;  
    }
    results[7] = sort_and_check(test8, len8, "Test 8 (Large Random Array)", sort);
    free(test8);  // free dynamically allocated memory

    for (int i = 0; i < 8; i++) {
        if (results[i])
            continue;
        passed = 0;
        break;
    }

    return passed;
}

static void final_result(int *result, int len)
{
    int maxWidth;

    printf("\n\033[32m--------------------------\n");
    printf("Final Result\n");
    printf("--------------------------\033[0m\n");

    for (int i = 0; i < len; i++) {
        int currentWidth = strlen(sort_names[i]);
        if (currentWidth > maxWidth) {
            maxWidth = currentWidth;
        }
    }

    for (int i = 0; i < len; i++) {
        printf("%s ", result[i] ? "\033[32m\u2713\033[0m" : 
                                  "\033[31m\u2717\033[0m");
        printf("%-*s\t%s\n", maxWidth, sort_names[i], 
                               result[i] ? "Passed" : "Failed");
    }
}


int main() {
    int i;
    int need_test_func[] = {
        SELECTION_SORT, 
        INSERTION_SORT,
        SHELL_SORT,
        MERGE_SORT,
        MERGE_SORT_DT,
    };
    int results[sizeof(need_test_func) / sizeof(need_test_func[0])];

    for (i = 0; i < sizeof(need_test_func) / sizeof(need_test_func[0]); i++) {
        if (i)
            printf("\n");
        results[i] = test_sort(sort_functions[need_test_func[i]], 
                        sort_names[need_test_func[i]]);
    }

    final_result(results, sizeof(results) / sizeof(results[0]));
    return 0;
}
