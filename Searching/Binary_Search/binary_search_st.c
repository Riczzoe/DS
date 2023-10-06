#include "binary_search_st.h"

int binary_search_rank(struct binary_search_st *st, KEY_TYPE key,
                       int lo, int hi)
{
    int mid;
    KEY_TYPE midkey;

    if (lo > hi)
        return NOT_FOUND;
    
    mid = (lo + hi) / 2;
    midkey = st->keys[mid];
    if (midkey == key) 
        return mid;
    else if (midkey > key) 
        return binary_search_rank(st, key, lo, mid - 1);
    else
        return binary_search_rank(st, key, mid + 1, hi);
}


int binary_search_iter(struct binary_search_st *st, KEY_TYPE key)
{
    int lo, mid, hi;
    KEY_TYPE midkey;

    lo = 0;
    hi = st->len;
    while (lo <= hi) {
        mid = (lo + hi) / 2;
        midkey = st->keys[mid];
        if (midkey == key)
            return mid;
        else if (midkey > key)
            hi = mid - 1;
        else 
            lo = mid + 1;
    }

    return NOT_FOUND;
}

VALUE_TYPE binary_search_get(struct binary_search_st *st, KEY_TYPE key) 
{
    int index;

    if (!st || st->len <= 0)
        return -1;
    /* index = binary_search_rank(st, key, 0, st->len - 1); */
    index = binary_search_iter(st, key);
    return index == NOT_FOUND ? NOT_FOUND : st->values[index];
}

