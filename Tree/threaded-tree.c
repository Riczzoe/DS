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

/*
 * build_threaded() - build threaded tree
 * @root: root of tree
 */
void build_threaded(ttree root)
{
    if (!root)
        return;
    ttnode *prev = NULL;
    create_thread(root, &prev);
    prev->right = NULL;
    prev->rt = thread;
}

/*
 * first_node_inorder() - find the first node in inorder traversal
 * @node: root of tree
 *
 * Retuen:
 *  the first node in inorder traversal
 */
ttnode* first_node_inorder(ttnode *node)
{
    if (!node)
        return NULL;
    while (node->lt == child)
        node = node->left;
    return node;
}

/*
 * find_successor() - find successor of a node
 * @p: node to find successor
 *
 * Return:
 *  pointer to successor node
 */
ttnode* find_successor(ttnode *p)
{
    if (!p)
        return NULL;
    /* if p->rt is thread, just return p->right */
    if (p->rt == thread)
        return p->right;
    /* if p->rt is child, return the first node in inorder traversal of 
     * p->right subtree.
     */
    return first_node_inorder(p->right);

}

/*
 * last_node_inorder() - find the last node in inorder traversal
 * @p: root of tree
 *
 * Return:
 *  the last node in inorder traversal
 */
ttnode* last_node_inorder(ttnode *p)
{
    if (!p)
        return NULL;
    while (p->rt == child)
        p = p->right;
    return p->right;
}

/*
 * find_precursor() - find precursor of a node
 * @p: node to find precursor
 *
 * Return:
 *  pointer to precursor node
 */
ttnode* find_precursor(ttnode *p)
{
    if (!p)
        return NULL;
    /* if p->lt is thread, just return p->left */
    if (p->lt == thread)
        return p->left;
    /* if p->lt is child, return the last node in inorder traversal of
     * p->left subtree.
     */
    return last_node_inorder(p->left);
}

/*
 * inorder_trav_threaded() - inorder traversal of threaded tree
 * @tree: root of tree
 */
void inorder_trav_threaded(ttree tree)
{
    ttnode *p;

    for (p = first_node_inorder(tree); p; p = find_successor(p))
        prinft("%d ", p->data);
}
