/*
 * add_thread() - add thread to a node
 * @node: node to add thread
 * @precursor: precursor node
 */
static void add_thread(ttnode *node, ttnode *precursor)
{
    if (!node->left) {
        /* if node->left is NULL, that no left child, make the left
         * pointer points to the precursor node, and declare that 
         * the left pointer points to a thread.
         */
        node->left = precursor;
        node->lt = thread;
    } else {
        /* if node->left not Null, that means node has left chile,
         * just declare that the right pointer points to a child.
         */
        node->lt = child;
    }

    /* precursor is NULL, do nothing */
    if (!precursor)
        return;

    /* if precursor has no right child, make the right pointer points
     * to the node, and declare that the right pointer points to a
     * thread.
     */
    if (!precursor->right) {
        precursor->right = node;
        precursor->rt = thread;
    } else {
        /* if precursor has right child, just declare that the right pointer
         * points to a child.
         */
        precursor->rt = child;
    }
}

static ttnode* create_thread(ttnode *node, ttnode **precursor);
{
    if (!node)
        return NULL;

    create_thread(node->left, precursor);
    add_thread(node, *precursor);
    *precursor = node;
    create_thread(node->right, precursor);
}

void build_threaded(ttree root)
{
    if (!root)
        return;
    ttnode *prev = NULL;
    create_thread(root, &prev);
    prev->right = NULL;
    prev->rt = thread;
}
