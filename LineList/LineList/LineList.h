#ifndef     LINELIST_h
#define     LINELIST_H

#define     INITSIZE        100         // the maximum capacity of the linear list.
#define     DEFAULT_VALUE   0           // default value for linear list elements.

typedef struct seqList_tag {
    int *data;                          // array storing the elements of the linear list.
    int maxSize;                        
    int size;                           // the number of elements the list currently.
} seqList_t, *seqList_ptr;

int initList(seqList_ptr l);
int length(seqList_t l);
int locateElement(seqList_t l, int e);
int getElement(seqList_t l, int index);
int listInsert(seqList_ptr l, int i, int e);
int listDelete(seqList_ptr l, int index, int *e);
void printList(seqList_t l);
int isEmpty(seqList_t l);
int destroyList(seqList_ptr l);

#endif
