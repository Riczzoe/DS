#ifndef BINARY_SEARCH_ST_H
#define BINARY_SEARCH_ST_H

#define KEY_TYPE int
#define VALUE_TYPE int
#define NOT_FOUND -1

struct binary_search_st {
    KEY_TYPE *keys;
    VALUE_TYPE *values;
    int len;
};

VALUE_TYPE binary_search_get(struct binary_search_st *st, KEY_TYPE key);

#endif // BINARY_SEARCH_ST_H
