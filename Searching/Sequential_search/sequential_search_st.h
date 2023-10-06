#ifndef     SEQUENTIAL_SEARCH_ST_H
#define     SEQUENTIAL_SEARCH_ST_H

#define     KEY_TYPE    int
#define     VALUE_TYPE  int

struct sequential_search_node {
    KEY_TYPE key;
    VALUE_TYPE value;
    struct sequential_search_node *next;
};

struct sequential_search_table {
    struct sequential_search_node *first;
    int len;
};

VALUE_TYPE  sequential_search_get(struct sequential_search_table *st, 
                                    KEY_TYPE key);
void sequential_search_put(struct sequential_search_table *st,
                                    KEY_TYPE key, VALUE_TYPE value);
int sequential_search_size(struct sequential_search_table *st);
void sequential_search_delete(struct sequential_search_table *st, 
                                    KEY_TYPE key);

#endif      // SEQUENTIAL_SEARCH_ST_H
