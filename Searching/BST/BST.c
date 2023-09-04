#include "BST.h"

int bstcreate(BST **t, KEYTYPE *keys, int n) 
{
    *t = NULL;
    int i, res;
    for (i = 0; i < n; i++) {
        res = bstput_2(t, keys[i]);
        if (res < 0)
            goto err;
    }
    return 1;

err:
    for (i = 0; i < n; i++)
        bstdelete(t, keys[i]);
    printf("bstcreate failed\n");
    return -1;
}

BSTNode* bstget_recursion(BST *t, KEYTYPE key) 
{
    if (!t)
        return NULL;

    if (key < t->key)
        return bstget_recursion(t->left, key);
    else if (key > t->key)
        return bstget_recursion(t->right, key);
    return t;
}

BSTNode* bstget(BST *t, KEYTYPE key) 
{
    while (t && key != t->key) {
        if (key < t->key)
            t = t->left;
        else
            t = t->right;
    }

    return t;
}

BSTNode* bstput_1(BST **t, KEYTYPE key) 
{
    if (!(*t)) {
        BSTNode *nn = (BSTNode *)malloc(sizeof(BSTNode));
        if (!nn)  /* malloc failed */  
            goto err;
        nn->key = key;
        nn->left = nn->right = NULL;
        *t = nn;
    }

    if (key < (*t)->key)
        (*t)->left = bstput_1(&((*t)->left), key);
    else if (key > (*t)->key)
        (*t)->right = bstput_1(&((*t)->right), key);
    else
        goto err;

    return *t;

err:
    return NULL;
}

int bstput_2(BST **t, KEYTYPE key) 
{
    if (!(*t)) {
        BSTNode *nn = (BSTNode *)malloc(sizeof(BSTNode));
        if (!nn)  /* malloc failed */  
            return -1;
        nn->key = key;
        nn->left = nn->right = NULL;
        *t = nn;
        return 1;
    }

    if (key < (*t)->key)
        return bstput_2(&((*t)->left), key);
    else if (key > (*t)->key)
        return bstput_2(&((*t)->right), key);
    return 0;
}

static BSTNode* deletemin(BSTNode *node) 
{
    if (!node->left)
        return node->right;
    node->left = deletemin(node->left);
    return node;
}

static BSTNode* deletemax(BSTNode *node) 
{
    if (!node->right)
        return node->left;
    node->right = deletemax(node->right);
    return node;
}

static BSTNode* min(BSTNode *node) 
{
    if (!node->left)
        return node;
    return min(node->left);
}

BSTNode* bstdelete(BST **t, KEYTYPE key)
{
    if (!(*t))
        return NULL;
    BSTNode *tp = *t;

    if (key < tp->key) {
        tp->left = bstdelete(&(tp->left), key);
    } else if (key > tp->key) {
        tp->right = bstdelete(&(tp->right), key);
    } else {
        if (!tp->left)
            *t = tp->right;
        if (!tp->right)
            *t = tp->left;
        if (tp->left && tp->right) {
            *t = min(tp->right);
            (*t)->right = deletemin(tp->right);
            (*t)->left = tp->left;
        }
        free(tp);
    }
    return *t;
}

int bstdestroy(BST *t) 
{
    if (!t)
        return 0;

    bstdestroy(t->left);
    bstdestroy(t->right);
    free(t);
    return 1;
}
