int fun2_2(sqList &l) {
    if (!l || l.length < 1) {
        return 0;
    }

    int length = l.length;
    int temp;

    for (int i = 0; i < length / 2; i++) {
        temp = l.data[i];
        l.data[i] = l.data[length - i - 1];
        l.data[length - i - 1] = temp;
    }

    return 1;
}

int fun2_3(sqList &l, int val) {
    if (!l || l.length < 1) {
        return 0;
    }

    int len = l.length;
    int equalValNum = 0;

    for (int i = 0; i < len; i++) {
        if (l.data[i] == val) {
            equalValNum++;
        } else {
            l.data[i - equalValNum] = l.data[i];
        }
    }

    l.length -= equalValNum;
    return 1;
}

int fun2_4(sqList &l, int s, int t) {
    if (!l || l.length < 1 || s > t) {
        return 0;
    }

    int sIndex = -1;
    int tIndex = -1;
    int move = 0;
    int i, j;

    for (i = 0; i < l.length && l.data[i] < s; i++);
    if (i >= l.legnth) {
        return 0;
    }

    for (j = i; j < l.length && l.data[j] <= t; j++);
    
    for ( ; j < l.length; i++; j++) {
        l.data[i] = l.data[j];
    }

    l.length = i;
    return 1;
}

int fun2_5(sqList &l, int s, int t) {
    if (!l || l.length < 1 || s > t) {
        return 0;
    }

    int k = 0;
    for (int i = 0; i < l.length; i++) {
        if (!(l.data[i] >= s && l.data[i] <= j)) {
            l.data[k] = l.data[i];
            k++;
        }
    }

    l.length = k;
    return 1;
}


int fun2_6(sqList &l) {
    if (!l || l.length < 1) {
        return 0;
    }
    int equalNum = 0;

    for (int i = 0; i < l.length - 1; i++) {
        if (l.data[i] == l.data[i + 1] || 
                (i != 0 && l.data[i] == l.data[i - 1])) {
            equal++;
        } else {
            l.data[i - 2] = l.data[i];
        }
    }
    l.length -= equalNum;

    return 1;
}

int fun2_6_better(sqList &l) {
    if (!l || l.length < 1) {
        return 0;
    }

    int i, j;
    for (i = 0, j = 1; j < l.length; j++) {
        if (l.data[i] != l.data[j]) {
            l.data[++i] = l.data[j];
        }
    }
    l.length = i + 1;
    return 1;
}

int fun2_7(const sqList &a, const sqList &b, sqList &c) {
    if (a.length + b.length > c.length) {
        return 0;
    }

    int i = 0, j = 0, k = 0;
    while (i < a.length && j < b.length) {
        if (a.data[i] < b.data[i]) {
            c.data[k++] = a.data[i++];
        } else {
            c.data[k++] = b.data[j++];
        }
    }

    while (i < a.length) {
        c.data[k++] = a.data[i++];
    }

    while (j < b.length) {
        c.data[k++] = b.data[j++];
    }

    c.length = k;
    return 1;
}
