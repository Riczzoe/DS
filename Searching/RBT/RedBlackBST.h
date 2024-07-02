#ifndef     REDBLACKBST_H
#define     REDBLACKBST_H

#include    <stdio.h>

#define     RED     1
#define     BLACK   0

typedef struct rbnode {
    int key;
    int color;
    struct rbnode *left, *right, *parent;
} rbnode, *rbt;

/*
 * rb_isempty - check if the red-black tree is empty
 * @t: the pointer to the root node of the red-black tree
 */
int rb_isempty(rbt t);



#endif      // REDBLACKBST_H
