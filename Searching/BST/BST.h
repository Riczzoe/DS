#ifndef BST_H
#define BST_H

#include <stdio.h>
#include <stdlib.h>

#define KEYTYPE int

typedef struct BSTNode {
    KEYTYPE key;
    struct BSTNode *left, *right;
} BSTNode, BST;

/* 
 * bstcreate - create a new Binary Search Tree
 * @t: the Binary Search Tree
 *
 * return 1, if create successfully, otherwise return -1
 */
int bstcreate(BST **t, KEYTYPE *keys, int n);

/* 
 * bstget_recursion - get the node with key from the tree t recursively
 * @t: the Binary Search Tree
 * @key: the key of the node
 */
BSTNode* bstget_recursion(BST *t, KEYTYPE key);

/* 
 * bstget - get the node with key from the tree t iteratively
 * @t: the Binary Search Tree
 * @key: the key of the node
 */
BSTNode* bstget(BST *t, KEYTYPE key);

/* 
 * bstput_1 - put the node with key into the tree t recursively
 * @t: the Binary Search Tree
 * @key: the key of the node
 *
 * return the address of the new node, if return NULL, insert failed
 */
BSTNode* bstput_1(BST **t, KEYTYPE key);

/* 
 * bstput_2 - put the node with key into the tree t iteratively
 * @t: the Binary Search Tree
 * @key: the key of the node
 *
 * return 1, if insert successfully, if repeat, return 0, 
 * if insert failed, return -1
 */
int bstput_2(BST **t, KEYTYPE key);

/* 
 * bstdelete - delete the node with key from the tree t
 * @t: the Binary Search Tree
 * @key: the key of the node
 */   
BSTNode* bstdelete(BST **t, KEYTYPE key);

/* 
 * bstdestroy - destroy the tree t, free the memory
 */
int bstdestroy(BST *t);
#endif // BST_H
