#include "staticList.h"

void initList(SLinkList L) {
    L[0].next = ENDFLAG
    for (int i = 1; i < MAXSIZE; i++)
        L[i].next = NULLFLAG;
}


void getElem(SLinkList L, int i, ElemType *e) {
    int j = 0;
    int index = L[0].next;

    while (index != -1 && j < i) {
        index = L[index].next;
        j++;
    }

    *e = j == i ? L[index].data : NULL;
}

void insertElem(SLinkList L, int i, ElemType e) {
    int j = 0;
    int index = L[0].next;
    int location = 0;

    for (; j < MAXSIZE; j++)
        if (L[j].next == NULLFLAG) {
            location = j;
            break;
        }
    if (location == 0) {
        printf("The list is full!\n");
        return;
    }

    for (j = 0; index != -1 && j < i - 1; j++) 
        index = L[index].next;
    if (index == -1) {
        printf("The index is out of range!\n");
        return;
    }

    L[location].data = e;
    L[location].next = L[index].next;
    L[index].next = location;
}
