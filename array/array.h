//
// Created by frost on 18-5-14.
//

#ifndef DATA_ARRAY_H
#define DATA_ARRAY_H

typedef struct Array {
    int *pBase;
    int cap;
    int len;
} array;

typedef int bool;

bool array_init(array *, int);
bool array_is_empty(array *);
bool array_is_full(array *);
void array_show(array *);
bool array_get(array *, int, int *);
bool array_insert(array *, int, int);
bool array_append(array *, int);
bool array_prepend(array *, int);
bool array_unshift(array *, int);
bool array_delete(array *, int, int *);
bool array_shift(array *, int *);
bool array_pop(array *, int *);
void array_sort(array *);
void array_swap(array *, int, int);
int parition(array *, int, int);
void array_qsort(array *, int, int);



#endif //DATA_ARRAY_H
