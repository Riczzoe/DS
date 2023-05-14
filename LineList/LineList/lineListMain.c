#include    "LineList.h"
#include    <stdio.h>

int main(void) {
    seqList_t s;
    initList(&s);
    int res = 0;
    
    for (int i = 0; i < 10; i++) {
        listInsert(&s, i, i * 10 + i);
    }
    printf("siez: %d\n", s.size);
    printf("all element of list:\n");
    printList(s);

    for (int i = 0; i < 10; i++) {
        listDelete(&s, 0, &res);
        printf("After delete %d\n", res);
        printf("size: %d\n", s.size);
        printf("all element of list:\n");
        printList(s);
        printf("\n");
    }
    destroyList(&s);
    printf("after distroy list, Is list empty? %s\n", isEmpty(s) ? "no" : "yes");

    return 1;
}
