#include "sequential_search_st.h"
#include <stdlib.h>

static int is_illegal(struct sequential_search_table *st)
{
    if (!st)
        return 1;
    if (st->len < 0)
        return 1;

    return 0;
}

VALUE_TYPE  sequential_search_get(struct sequential_search_table *st, 
                                    KEY_TYPE key)
{
    struct sequential_search_node *node;

    if (is_illegal(st))
        return -1;

    for (node = st->first; node; node = node->next) {
        if (key == node->key) {
            return node->value;
        }
    }

    return -1;
}

void sequential_search_put(struct sequential_search_table *st,
                                    KEY_TYPE key, VALUE_TYPE value)
{
    struct sequential_search_node *node;

    if (is_illegal(st))
        return;

    for (node = st->first; node; node = node->next) {
        if (key == node->key) {
            node->value = value;
            return;
        }
    }
    
    node = (struct sequential_search_node*) 
           malloc(sizeof (struct sequential_search_node));
    if (!node)
        return;

    node->key = key;
    node->value = value;
    node->next = st->first;
    st->first = node;
    st->len++;
}

int sequential_search_size(struct sequential_search_table *st) 
{
    struct sequential_search_node *node;
    int size;

    if (is_illegal(st))
        return 0;

    for (node = st->first, size = 0; node; node = node->next)
        size++;

    return size;
}

void sequential_search_delete(struct sequential_search_table *st, 
                                    KEY_TYPE key) 
{
    struct sequential_search_node **nodep, *temp;

    if (is_illegal(st))
        return;

    nodep = &st->first;
    while (*nodep && (*nodep)->key != key)
        nodep = &(*nodep)->next;
    
    if (*nodep) {
        temp = *nodep;
        *nodep = temp->next;
        free(temp);
        st->len--;
    }
}
