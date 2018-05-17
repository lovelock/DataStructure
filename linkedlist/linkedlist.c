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

int linkedlist_length(p_linkedlist_t p_head) {
    int len = 0;

    p_linkedlist_t pt = p_head->pNext;

    while(pt != NULL) {
        len++;
        pt = pt->pNext;
    }

    free(pt);

    return len;
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


int linkedlist_insert(p_linkedlist_t p_head, int pos, int val)
{
    int i = 0;
    p_linkedlist_t p = p_head;

    while (p != NULL && ++i < pos) {
        printf("\ni: %d\n", i);
        printf("address of p: %p\n", p);
        p = p->pNext;
    }

    if (p == NULL) {
        printf("skip insert\n");
        return FALSE;
    }

    p_linkedlist_t p_new = (p_linkedlist_t)malloc(sizeof(linkedlist_t));
    if (p_new == NULL) {
        printf("create p_new failed\n");
        return FALSE;
    }

    p_new->data = val;
    p_new->pNext = p->pNext;

    p->pNext = p_new;

    return TRUE;
}

int linkedlist_append(p_linkedlist_t p_head, int val) {
    int len = linkedlist_length(p_head);

    return linkedlist_insert(p_head, len+1, val);
}

int linkedlist_prepend(p_linkedlist_t p_head, int val) {
    return linkedlist_insert(p_head, 0, val);
}

int linkedlist_delete(p_linkedlist_t p_head, int pos, int *val) {
    int i = 0;
    p_linkedlist_t p = p_head;

    while (p != NULL && ++i < pos) {
        printf("\ni: %d\n", i);
        printf("address of p: %p\n", p);
        p = p->pNext;
    }

    if (p->pNext == NULL) {
        printf("skip delete\n");
        return FALSE;
    }

    p_linkedlist_t q = p->pNext;
    *val = q->data;
    p->pNext = p->pNext->pNext;
    free(q);

    printf("p->data: %d\n", p->data);


    return TRUE;
}

int linkedlist_pop(p_linkedlist_t p_head, int *val) {
    return linkedlist_delete(p_head, linkedlist_length(p_head), val);
}

int linkedlist_shift(p_linkedlist_t p_head, int *val) {
    return linkedlist_delete(p_head, 0, val);
}


