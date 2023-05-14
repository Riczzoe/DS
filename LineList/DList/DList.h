#ifndef     DLIST_H
#define     DLIST_H
#include    <stdbool.h>
 
typedef     int     ElemType;
typedef struct DNode_t DNode, *DNode_ptr;

typedef struct DNode_t {
    ElemType data;
    DNode_ptr next;
    DNode_ptr prev;
};

typedef struct DList_t {
    int length;
    DNode_ptr sentinel;
}DList, *DList_ptr;

DList_ptr initDList();
bool insertNextNode(DNode_ptr node, ElemType data);
bool deleteiNextNode(DNode_ptr node);
bool isEmpty(DList_ptr list);
void printDList(DList l);

#endif
