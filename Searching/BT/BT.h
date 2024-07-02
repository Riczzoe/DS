#ifndef BT_H
#define BT_H

#define DataType int

typedef struct BTnode {
    DataType data;
    struct BTnode *left, *right;
} BTnode, *BTtree;

#endif // BT_H
