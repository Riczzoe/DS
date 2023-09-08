#ifndef     TREE_H
#define     TREE_H

#include    "BST.h"
#include    "queue.h"

#define      PREORDER_TRAV    0
#define      INORDER_TRAV     1
#define      POSTORDER_TRAV   2
#define      LEVELORDER_TRAV  3

typedef struct BSTNode *btree;

/* tree_travel.c */
void preorder_trav(btree root);
void inorder_trav(btree root);
void postorder_trav(btree root);
void levelorder_trav(btree root);


#endif      // TREE_H
