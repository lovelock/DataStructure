//
// Created by frost
//

#ifndef DATASTRUCTURE_LINKEDLIST_H
#include "../common.h"

typedef struct node {
    int data;
    struct node *pNext;
} *p_linkedlist_t, linkedlist_t;

p_linkedlist_t linkedlist_init();
void linkedlist_show(p_linkedlist_t);
int linkedlist_insert(p_linkedlist_t, int, int);
int linkedlist_length(p_linkedlist_t);
int linkedlist_append(p_linkedlist_t, int);
int linkedlist_prepend(p_linkedlist_t, int);
int linkedlist_delete(p_linkedlist_t, int, int *);
int linkedlist_pop(p_linkedlist_t, int *);
int linkedlist_shift(p_linkedlist_t, int *);
int linkedlist_sort(p_linkedlist_t);

#define DATASTRUCTURE_LINKEDLIST_H value
#endif /* ifndef DATASTRUCTURE_LINKEDLIST_H */
