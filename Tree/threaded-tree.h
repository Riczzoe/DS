#ifndef     THREADED_TREE_H
#define     THREADED_TREE_H

#define     ELEM_TYPE       int

#define     thread          1       /* pointer is a thread */
#define     child           0;      /* pointer is a child pointer */

typedef struct ttnode {
    ELEM_TYPE data;
    struct ttnode *left, *right;
    char lt, rg;
} ttnode, *ttree;

void create_threaded(ttree*);
ttnode* first_node_inorder(ttnode*);
ttnode* find_successor(ttnode*);
void inorder_trav_threaded(ttree);
ttnode* last_node_inorder(ttnode*);
ttnode* find_precursor(ttnode*);

#endif      // THREADED_TREE_H
