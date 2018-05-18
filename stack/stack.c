#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int stack_init(p_stack_t p_stack) {
    p_node_t p_bottom = (p_node_t)malloc(sizeof(node_t));
    if (NULL == p_bottom) {
        return 0;
    }

    p_node_t p_top = p_bottom;

    p_stack->p_bottom = p_bottom;
    p_stack->p_top = p_top;
    p_stack->p_bottom->p_next = NULL;

    return 1;
}

int stack_push(p_stack_t p_stack, int val) {
    p_node_t p_node = (p_node_t)malloc(sizeof(node_t));
    if (NULL == p_node) {
        return 0;
    }
    p_node->data = val;
    p_node->p_next = p_stack->p_top;
    p_stack->p_top = p_node;
    return 1;
}

int stack_pop(p_stack_t p_stack, int *val) {
    if (p_stack->p_top == p_stack->p_bottom) {
        printf("stack is empty, nothing to pop\n");
        return 0;
    }
    p_node_t p_tmp = p_stack->p_top;
    *val = p_tmp->data;
    p_stack->p_top = p_tmp->p_next;

    p_tmp->p_next =NULL;
    free(p_tmp);

    return 1;
}
void stack_print(p_stack_t p_stack) {
    p_node_t p = p_stack->p_top;

    while (NULL != p->p_next) {
        printf("%d\n", p->data);
        p = p->p_next;
    }
}
