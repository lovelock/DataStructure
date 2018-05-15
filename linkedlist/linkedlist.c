#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include "linkedlist.h"

p_linkedlist_t linkedlist_init() {

    int len, val;
    printf("Please enter a length for the linkedlist\n");
    scanf("%d", &len);

    if (len <= 0) {
        printf("len must be unsigned\n");
        exit(1);
    }

    p_linkedlist_t p_head = (p_linkedlist_t)malloc(sizeof(linkedlist_t));
    if (NULL == p_head) {
        printf("create p_head failed, exiting\n");
        exit(1);
    }
    p_linkedlist_t p_tail = p_head;
    p_tail->pNext = NULL;

    while (len-- > 0) {
        printf("enter a number: \t");
        scanf("%d", &val);

        p_linkedlist_t p_new = (p_linkedlist_t)malloc(sizeof(linkedlist_t));
        p_new->data = val;
        p_tail->pNext = p_new;
        p_new->pNext = NULL;
        p_tail = p_new;
    }

    return p_head;
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
