#include "sequential_search_st.h"
#include <stdio.h>
#include <assert.h>

void test_sequential_search_table() {
    struct sequential_search_table st;
    st.first = NULL;
    st.len = 0;

    // Test put function
    sequential_search_put(&st, 1, 10);
    assert(sequential_search_size(&st) == 1);
    assert(sequential_search_get(&st, 1) == 10);

    sequential_search_put(&st, 2, 20);
    assert(sequential_search_size(&st) == 2);
    assert(sequential_search_get(&st, 2) == 20);

    // Test update value for existing key
    sequential_search_put(&st, 1, 15);
    assert(sequential_search_get(&st, 1) == 15);

    // Test delete function
    sequential_search_delete(&st, 1);
    assert(sequential_search_size(&st) == 1);
    assert(sequential_search_get(&st, 1) == -1); // Assuming -1 indicates not found or error

    // Cleanup after tests
    while(st.first) {
        sequential_search_delete(&st, st.first->key);
    }

    printf("All tests passed!\n");
}

int main() {
    test_sequential_search_table();
    return 0;
}
