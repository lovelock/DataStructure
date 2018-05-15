#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "linkedlist.h"

int main() {
    p_linkedlist_t head = linkedlist_init();

    linkedlist_show(head);
}
