//
// Created by frost
//

#ifndef DATASTRUCTURE_LINKEDLIST_H
#include "../common.h"

typedef struct linkedlist {
    int data;
    struct linkedlist *pNext;
} *p_linkedlist_t, linkedlist_t;

p_linkedlist_t linkedlist_init();
void linkedlist_show(p_linkedlist_t);
int linkedlist_insert(p_linkedlist_t, int, int);
int linkedlist_append(p_linkedlist_t, int);
int linkedlist_prepend(p_linkedlist_t, int);

#define DATASTRUCTURE_LINKEDLIST_H value
#endif /* ifndef DATASTRUCTURE_LINKEDLIST_H */
