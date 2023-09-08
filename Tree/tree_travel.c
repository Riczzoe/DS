#include "tree.h"
#include "queue.h"


/*
 * preorder_trav() - Prorder traversal of a binary tree
 * 
 * @root:       root of the binary tree
 */
void preorder_trav(btree root) 
{
    if (!root)
        return;

    printf("%d ", root->key);
    preorder_trav(root->left);
    preorder_trav(root->right);
}

/*
 * inorder_trav() - Inorder traversal of a binary tree
 * 
 * @root:       root of the binary tree
 */
void inorder_trav(btree root) 
{
    if (!root)
        return;

    inorder_trav(root->left);
    printf("%d ", root->key);
    inorder_trav(root->right);
}

/*
 * postorder_trav() - Postorder traversal of a binary tree
 * 
 * @root:       root of the binary tree
 */
void postorder_trav(btree root) 
{
    if (!root)
        return;

    postorder_trav(root->left);
    postorder_trav(root->right);
    printf("%d ", root->key);
}

/*
 * levelorder_trav() - Levelorder traversal of a binary tree
 * 
 * @root:       root of the binary tree
 */
void levelorder_trav(btree root)
{
    queue_t q;
    initQueue(&q);
    BSTNode* temp;

    if (!root)
        return;
    enQueue(&q, root);

    while (!isQueueEmpty(&q)) {
        deQueue(&q, (void **)&temp);
        printf("%d ", temp->key);
        if (temp->left)
            enQueue(&q, temp->left);
        if (temp->right)
            enQueue(&q, temp->right);
    }

    freeQueue(&q);
}
