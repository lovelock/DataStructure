#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "linkedlist.h"

int main() {
    p_linkedlist_t head = linkedlist_init();

    linkedlist_insert(head, 2, 8);

    linkedlist_show(head);
}
