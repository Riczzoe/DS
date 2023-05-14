#ifndef     STATICLIST_H
#define     STATICLIST_H

#include    <stdio.h>

#define     MAXSIZE     100 /* The maximum number of elements in the list */
#define     ElemType    int /* The type of elements in the list */
#define     NULLFLAG    -2  /* The flag of the element is null */
#define     ENDOFLAG    -1  /* The flag of the end of the list */

typedef struct node_tag {
    ElemType data;
    int next;
} node_t, SLinkList[MAXSIZE];

void initList(SLinkList L);
void getElem(SLinkList L, int i, ElemType *e);

#endif
