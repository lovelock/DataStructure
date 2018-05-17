#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "linkedlist.h"

int main() {
    p_linkedlist_t head = linkedlist_init();

    /*
     * linkedlist_insert(head, 2, 7);
     * linkedlist_append(head, 9);
     * linkedlist_prepend(head, 809);
     */
    int val;
    /* linkedlist_delete(head, 1, &val); */
    /* linkedlist_pop(head, &val); */
    linkedlist_shift(head, &val);
    printf("deleted value is: %d\n", val);

    linkedlist_show(head);
}
