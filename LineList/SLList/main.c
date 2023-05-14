#include    "SLList.h"
#include    <stdio.h>


int main(void) {
    printf("head insert\n");
    SLList list = headInsert();
    printList(list);
    printf("tail insert\n");
    SLList list2 = tailInsert();
    printList(list2);
    int test = 1;

    if (test % 2 == 1) {
        if (listInsert(list, 3, 3)) {
            printf("insert success\n");
        } else {
            printf("insert failed\n");
        }
        printList(list);

        printf("now delete elem\n");
        ElemType elem;
        for (int i = 0; i < 3; i++) {
            if (listDelete(list, 1, &elem)) {
                printf("delete success\n");
            } else {
                printf("delete failed\n");
            }
            printList(list);
        }   
    }

    
    if (test % 4 / 2 == 1) {
        if (listInsert(list2, 2, 3)) {
            printf("insert success\n");
        } else {
            printf("insert failed\n");
        }
        printList(list2);
    }
    return 0;
}
