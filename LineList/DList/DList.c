#include    "DList.h"
#include    <stdio.h>
#include    <stdlib.h>

/*
 * Initialize a new doubly linked list
 */
DList_ptr initDList() {
    /* Allocate memory for the list */
    DList_ptr l = (DList_ptr) malloc(sizeof(DList));
    if (!l) {
        printf("Memory allocation failed!");
        return NULL;
    }
    l->length = 0;
    l->sentinel = (Node_ptr) malloc(sizeof(DNode));
    if (!l->sentinel) {
        printf("Memory allocation failed!");
        free(l);
        return NULL;
    }
    l->sentinel->next = NULL;
    l->sentinel->prev = NULL;

    return l;
}

/*
 * Insert a new node after the given node
 */
bool insertNextNode(DNode_ptr node, ElemType elem) {
    if (!node) {
        printf("Invalid node!");
        return false;
    }

    Node_ptr newNode = (Node_ptr) malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed!");
        return false;
    }
    /* Insert the new node */
    newNode->elem = elem;
    newNode->next = node->next;
    newNode->prev = node;

    /* Update the next node's prev pointer */
    if (node->next) 
        node->next->prev = newNode;
    node->next = newNode;
    return true;
}

/* delete the next node */
bool deleteNextNode(DNode_ptr node) {
    if (!node) {

    }

    DNode_ptr nextNode = node->next;
    if（!nextNode) 
        return false;

    node->next = nextNode->next;
    if (nextNode->next)         
        nextNode->next->prev = node;
    free(nextNode);
    return true;
}

bool isEmpty(DList l) {
    return !!l.length;
}

void printDList(DList l) {
    if (isEmpty(l)) {
        printf("The list is empty!");
        return;
    }

    DNode_ptr p = l.sentinel->next;
    while (p) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}
