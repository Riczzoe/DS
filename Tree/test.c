#include "tree.h"

static void (*travfuncs[])(btree) = {
    [PREORDER_TRAV]     = preorder_trav,
    [INORDER_TRAV]      = inorder_trav,
    [POSTORDER_TRAV]    = postorder_trav,
    [LEVELORDER_TRAV]   = levelorder_trav,
};

static char *travnames[] = {
    [PREORDER_TRAV]     = "preorder",
    [INORDER_TRAV]      = "inorder",
    [POSTORDER_TRAV]    = "postorder",
    [LEVELORDER_TRAV]   = "levelorder",
};

/*
 * create_test_tree() - create a test tree
 * @bstp: pointer to the BST pointer
 * @initarr: array of initial keys
 * @size: size of the array
 *
 * if initarr is NULL or size <= 0, use default array
 *
 * Return:
 *  1  - success
 *  -1 - failed
 */
static int create_test_tree(BST **bstp, int initarr[], int size)
{
    int res;
    /* default tree:
     *         13
     *       /     \
     *      10     16
     *     / \     / \
     *    9  11   15 17
     *   /    \   /
     *  8     12 14
     */
    int default_arr[] = {13, 10, 16, 9, 11, 15, 17, 8, 12, 14};
    if (initarr == NULL || size <= 0) {
        initarr = default_arr;
        size = sizeof(default_arr) / sizeof(default_arr[0]);
    }
    res = bstcreate(bstp, initarr, size);
    printf("test tree create %s\n", res == 1 ? "success" : "failed");
    return res;
}


void bst_trav_test(int funcnum, BST *bst)
{
    printf("checking bst traversal %s\n", travnames[funcnum]);
    travfuncs[funcnum](bst);
    printf("\n");
}

static void test(BST *bst, int funcs[], int nf, int initarr[], int n)
{
    int res;
    printf("checking bst traversal\n");

    printf("creating test tree\n");
    res = create_test_tree(&bst, initarr, n);
    if (res < 0) 
        return;

    int i;
    for (i = 0; i < nf; i++) {
        bst_trav_test(funcs[i], bst);
    }

    bstdestroy(bst);
}

int main(void) 
{
    BST *bst = NULL;
    int nf;

    int funcs[] = {PREORDER_TRAV, INORDER_TRAV, POSTORDER_TRAV, LEVELORDER_TRAV};
    nf = sizeof(funcs) / sizeof(funcs[0]);
    test(bst, funcs, nf, NULL, 0);
    return 0;
}
