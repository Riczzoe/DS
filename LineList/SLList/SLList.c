#include    <stdio.h>
#include    <stdlib.h>
#include    "SLList.h"

SLList headInsert() {
    SLNode *node;

    // create a new SLList
    SLList l = (SLList) malloc(sizeof(SLNode));
    l->next = NULL;

    int input;
    do {
        scanf("%d", &input);
        node = (SLNode *) malloc(sizeof(SLNode));
        node->data = input;
        node->next = l->next;
        l->next = node;
    } while (input != 9999);

    return l;
}

SLList tailInsert() {
    SLNode *node, *tail;
    SLList l = (SLList) malloc(sizeof(SLNode));
    tail = l;
    l->next = NULL;

    int input;
    do {
        scanf("%d", &input);
        node = (SLNode *) malloc(sizeof(SLNode));
        node->data = input;
        tail->next = node; 
        tail = node;
    } while (input != 9999);
    tail->next = NULL;

    return l;
}

static bool insertPriorNode(SLNode *node, ElemType e) {
    if (!node) {
        return false;
    }

    SLNode *new = (SLNode *) malloc(sizeof(SLNode));
    if (!new) {
        return false;
    }

    new->data = node->data;
    new->next = node->next;
    node->next = new;
    node->data = e;
    return true;
}

static bool insertNextNode(SLNode *node, ElemType e) {
    if (!node) {
        return false;
    }

    SLNode *new = (SLNode *) malloc(sizeof(SLNode));
    if (!new) {
        return false;
    }
    new->data = e;
    new->next = node->next;
    node->next = new;
    return true;
}

SLNode* getElem(SLList l, int i) {
    if (i < 0) {
        return false;
    }

    SLList p = l;
    while (i > 0 && p) {
        p = p->next;
        i--;
    }

    return p;
}


bool listInsert(SLList l, int i, ElemType e) {
    if (i < 1) {
        return false;
    }

    SLList p = getElem(l, i - 1);
    return insertNextNode(p, e);
}


bool listDelete(SLList l, int i, ElemType *e) {
    if (i < 1) 
        return false;

    SLList p = getElem(l, i - 1);
    if (!p) 
        return false;

    SLNode *deleteNode = p->next;
    if (!deleteNode) 
        return false;

    *e = deleteNode->data;
    p->next = deleteNode->next;
    free(deleteNode);

    return true;
}

SLNode* locateElem(SLList l, ElemType e) {
    SLList p = l->next;
    while (p && p->data != e) {
        p = p->next;
    }

    return p;
}

int length(SLList l) {
    int len = 0;
    SLList p = l->next;
    while (p) {
        len++;
        p = p->next;
    }

    return len;
}

void printList(SLList l) {
    SLNode *p = l->next;
    while (p) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}








