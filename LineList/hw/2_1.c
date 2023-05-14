#include    "LineList.h"

int deleteMin(seqList &l) {
    if (!l || l.length < 1) {
        printf("delete error\n");
        return 0;
    }

    int min = l.data[0];
    int index = 0;
    for (int i = 1; i < l.length; i++) {
        min < l.data[i] ? min = l.data[i], index = i : ;
    }
    l.data[index] = l.data[l.size];
    return min;
}
