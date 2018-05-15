#include <stdio.h>
#include "array.h"

#define ARRAY_CAP 10

int main() {
    array arr;
    array_init(&arr, ARRAY_CAP);

    /* array_show(&arr); */

    /* array_insert(&arr, 0, 20); */
    /* array_show(&arr); */
    /* array_append(&arr, 10); */
    /* array_show(&arr); */
    /* array_prepend(&arr, 100); */
    /* array_show(&arr); */
    /* array_insert(&arr, 5, 30); */
    /* array_show(&arr); */
    /* array_prepend(&arr, 13); */
    /* array_prepend(&arr, 116); */
    /* array_show(&arr); */
    /* printf("sorting array...\n"); */
    /* array_sort(&arr); */
    /* array_qsort(&arr); */
    /* array_show(&arr); */
    /* int deleted; */
    /* array_delete(&arr, 2, &deleted); */
    /* printf("deleted: %d\n", deleted); */
    /* array_show(&arr); */
    /* int popped; */
    /* array_pop(&arr, &popped); */
    /* printf("popped: %d\n", popped); */
    /* array_show(&arr); */
    /* int shifted; */
    /* array_shift(&arr, &shifted); */
    /* printf("shifted: %d\n", shifted); */
    /* array_show(&arr); */

    array_append(&arr, 3);
    array_append(&arr, 8);
    array_append(&arr, 2);
    array_append(&arr, 1);
    array_append(&arr, 6);
    array_append(&arr, 4);
    array_append(&arr, 7);
    array_append(&arr, 9);
    array_append(&arr, 5);
    array_show(&arr);
    array_qsort(&arr, 0, arr.len-1);
    array_show(&arr);

    return 0;
}
