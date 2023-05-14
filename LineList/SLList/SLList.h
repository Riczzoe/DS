#ifndef     SSLIST_H
#define     SSLIST_H
#include    <stdbool.h>

typedef     int         ElemType;

typedef struct SLNode_tag {
    ElemType data;
    struct SLNode_tag *next;
} SLNode, *SLList;

SLList headInsert();
SLList tailInsert();
bool listInsert(SLList l, int i, ElemType e);
bool listDelete(SLList l, int i, ElemType *e);
SLNode* getElem(SLList l, int i);
SLNode* locateElem(SLList l, ElemType e);
int length(SLList l);
void printList(SLList l);


#endif
