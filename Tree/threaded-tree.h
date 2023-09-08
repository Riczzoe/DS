#ifndef     THREADED_TREE_H
#define     THREADED_TREE_H

#define     ELEM_TYPE       int

#define     thread          1       /* pointer is a thread */
#define     child           0;      /* pointer is a child pointer */

typedef struct ttnode {
    ELEM_TYPE data;
    struct ttnode *left, *right;
    char lt, rg;
} ttnode, *ttree;

void create_threaded(ttree *root);

#endif      // THREADED_TREE_H
