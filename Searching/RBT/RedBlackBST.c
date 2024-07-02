/*
 * left_rotate - Left rotate the node
 *
 * the result like this:
 *
 *     (node)                (node)                  (rc)           
 *     /    \                /  |                    /  \
 *   (lc)  (rc)    --->    (lc) | (rc) --->     (node)  (rcr) 
 *         /  \                 | /  \          /   \
 *     (rcl)  (rcr)           (rcl)  (rcr)    (lc) (rcl)
 *
 */
static rbnode* left_rotate(rbnode *node)
{
    rbnode *rc = node->right;
    node->right = rc->left;
    rc->left = node;
    rc->color = node->color;
    node->color = RED;
    return rc;
}

/*
 * right_rotate - Right rotate the node
 *
 * the result like this:
 *
 *     (node)               (node)                (lc)           
 *     /    \                  | \                /  \
 *   (lc)  (rc)   --->    (lc) | (rc) --->   (lcl)  (node) 
 *   /  \                 /  \ |                    /    \
 * (lcl) (lcr)        (lcl) (lcr)                (lcr)  (rc)
 *
 */
static rbnode* right_rotate(rbnode *node)
{
    rbnode *lc = node->left;
    node->left = lc->right;
    lc->right = node;
    lc->color = node->color;
    node->color = RED;
    return lc;
}
