#include <stdio.h>
#include "BST.h"

int main(void) 
{
    BST *bst;
    int res, i, size, testsuccess = 1, destroyresuccess = 1;

    int initarr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    size = sizeof(initarr) / sizeof(initarr[0]);
    res = bstcreate(&bst, initarr, size);
    if (res < 0) {
        printf("bstcreate failed\n");
        testsuccess = 0;
        goto failed;
    } else {
        printf("bstcreate success\n");
    }

    printf("\nchecking bstget_recursion\n");
    for (i = 0; i < size; i++) {
        BSTNode *node = bstget_recursion(bst, initarr[i]);
        if (!node) {
            printf("bstget_recursion get %d failed\n", initarr[i]);
            testsuccess = 0;
        } else if (node->key == initarr[i]) {
            printf("bstget_recursion get %d success\n", initarr[i]);
        } else {
            printf("bstget_recursion get %d incorrect, get %d\n", initarr[i], node->key);
            testsuccess = 0;
        }
    }

    printf("\nchecking delete\n");
    BSTNode *temp;
    KEYTYPE testkey = initarr[8];
    bstdelete(&bst, testkey);
    if ((temp = bstget(bst, testkey)) != NULL) {
        if (temp->key == testkey) {
            printf("bstdelete failed\n");
            testsuccess = 0;
        } else {
            printf("bstdelete incorrect, get %d\n", temp->key);
            testsuccess = 0;
        }
    } else {
        printf("bstdelete success\n");
    }

    printf("\nchecking bstget\n");
    for (i = 0; i < size; i++) {
        BSTNode *node = bstget(bst, initarr[i]);
        if (!node) {
            printf("bstget get %d failed\n", initarr[i]);
            testsuccess = 0;
        } else if (node->key == initarr[i]) {
            printf("bstget get %d success\n", initarr[i]);
        } else {
            printf("bstget get %d incorrect, get %d\n", initarr[i], node->key);
            testsuccess = 0;
        }
    }

    printf("\nchecking destroy\n");
    bstdestroy(bst);
    for (i = 0; i < size; i++) {
        BSTNode *node = bstget(bst, initarr[i]);
        if (node) {
            destroyresuccess = 0;
            testsuccess = 0;
        }
    }

    printf("bstdestroy %s\n", destroyresuccess ? "success" : "failed");
    if (!testsuccess)
        goto failed;
    printf("\nCongratulations! All tests passed!\n");
    return 0;

failed:
    printf("\nSorry, some tests failed.\n");
    return -1;
}
