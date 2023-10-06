#include <stdio.h>
#include <assert.h>
#include "binary_search_st.h"

void test_binary_search() {
    struct binary_search_st st;

    // Test case 1: Empty structure
    st.keys = NULL;
    st.values = NULL;
    st.len = 0;
    assert(binary_search_get(&st, 5) == NOT_FOUND);

    // Test case 2: Single element
    int keys2[] = {5};
    int values2[] = {10};
    st.keys = keys2;
    st.values = values2;
    st.len = 1;
    assert(binary_search_get(&st, 5) == 10);
    assert(binary_search_get(&st, 4) == NOT_FOUND);

    // Test case 3: Multiple elements, value exists
    int keys3[] = {1, 3, 5, 7, 9};
    int values3[] = {10, 30, 50, 70, 90};
    st.keys = keys3;
    st.values = values3;
    st.len = 5;
    assert(binary_search_get(&st, 5) == 50);
    assert(binary_search_get(&st, 1) == 10);
    assert(binary_search_get(&st, 9) == 90);

    // Test case 4: Multiple elements, value doesn't exist
    assert(binary_search_get(&st, 4) == NOT_FOUND);
    assert(binary_search_get(&st, 0) == NOT_FOUND);
    assert(binary_search_get(&st, 10) == NOT_FOUND);

    printf("All tests passed!\n");
}

int main() {
    test_binary_search();
    return 0;
}

