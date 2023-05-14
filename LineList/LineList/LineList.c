#include    <stdio.h>
#include    <stdlib.h>
#include    "LineList.h"



int initList(seqList_ptr l) {
    l->maxSize = INITSIZE;
    l->data = (int*)malloc(sizeof(int) * INITSIZE);
    for(int i = 0; i < INITSIZE; i++) {
        *(l->data + i) = DEFAULT_VALUE;
    }
    l->size = 0;
}

int length(seqList_t l) {
    return l.size;
}


// 
int locateElement(seqList_t l, int e) {
    if (l.size < 1) {
        return -1;
    }

    int *p = l.data;
    for (int i = 0; i < l.size && *p++ != e; i++);
    return p - l.data;
}


int getElement(seqList_t l, int index) {
    if (l.size < 1 || index >= l.size) {
        return -1;
    }

    int *p = l.data;
    return *(p + index);
}

int listInsert(seqList_ptr l, int i, int e) {
    if (l->size >= l->maxSize || l == NULL) {
        return 0;
    }
    if (i < 1 || i　> l->size) {
        return 0;
    }

    for (int j = l->size; j >= i; j++) {
        *(l->data + j) = *(l->data + j - 1);
    }

    *(l->data + i - 1) = e;
    l->size++;
    return 1;
}

int listDelete(seqList_ptr l, int index, int *e) {
    if (l == NULL || index >= l->size || index < 0) {
        return 0;
    }

    *e = *(l->data + index - 1);

    int i;
    for (i = 0; index + i < l->size - 1; i++) {
        *(l->data + index + i) = *(l->data + index + i + 1);
    }

    *(l->data + index + i) = 0;
    l->size--;

    return 1;
}

void printList(seqList_t l) {
    for (int i = 0; i < l.size; i++) {
        printf(i == (l.size - 1) ? "%4d\n" : "%4d\t", l.data[i]);
    }
}

int isEmpty(seqList_t l) {
    return !!l.size;
}

int destroyList(seqList_ptr l) {
    if (l == NULL) {
        return 1;
    }
    
    if (l->data != NULL) {
        free(l->data);
    }

    return 1;
}
