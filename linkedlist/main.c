#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "linkedlist.h"

int main() {
    p_linkedlist_t head = (p_linkedlist_t)malloc(sizeof(linkedlist_t));
    linkedlist_init(head, 20);

    linkedlist_show(head);
}
