//
// Created by frost on 18-5-14.
//

#ifndef DATA_ARRAY_H
#define DATA_ARRAY_H

#include "../common.h"

typedef struct Array {
    int *pBase;
    int cap;
    int len;
} array;


int array_init(array *, int);
int array_is_empty(array *);
int array_is_full(array *);
void array_show(array *);
int array_get(array *, int, int *);
int array_insert(array *, int, int);
int array_append(array *, int);
int array_prepend(array *, int);
int array_unshift(array *, int);
int array_delete(array *, int, int *);
int array_shift(array *, int *);
int array_pop(array *, int *);
void array_sort(array *);
void array_swap(array *, int, int);
int parition(array *, int, int);
void array_qsort(array *, int, int);



#endif //DATA_ARRAY_H
