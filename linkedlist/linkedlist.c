#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include "linkedlist.h"

int linkedlist_init(p_linkedlist_t head, int data) {
    // create node with given data
    p_linkedlist_t node = (p_linkedlist_t) malloc(sizeof(linkedlist_t));
    if (node == NULL) {
        printf("create linkedlist node failed\n");
        return FALSE;
    }
    node->data = data;

    // point head node's pNext to node
    head->pNext = node;

    // point valid node's pNext to NULL
    node->pNext = NULL;

    return TRUE;
}

void linkedlist_show(p_linkedlist_t head) {
    printf("linkedlist is below\n");

    p_linkedlist_t pt = head->pNext;

    while (pt != NULL) {
        printf("pointer: %p, data: %d\t\n", pt, pt->data);
        pt = pt->pNext;
    }

    free(pt);

    printf("\n\n\nend print linkedlist\n");
}
