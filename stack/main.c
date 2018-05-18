#include <stdio.h>
#include "stack.h"

int main() {
    stack_t stack;

    printf("=======init start=========\n");
    stack_init(&stack);
    stack_print(&stack);
    printf("=======init stop=========\n\n\n");


    printf("=======push start=========\n");
    stack_push(&stack, 20);
    stack_push(&stack, 30);
    stack_push(&stack, 25);
    stack_push(&stack, 51);
    stack_print(&stack);
    printf("=======push stop=========\n\n\n");

    printf("=======pop start=========\n");
    int val;
    printf("-------correct pop start--------\n");
    stack_pop(&stack, &val);
    printf("val popped out: %d\n", val);
    stack_print(&stack);
    printf("-------correct pop stop--------\n");
    printf("-------incorrect pop start--------\n");
    stack_pop(&stack, &val);
    stack_pop(&stack, &val);
    stack_pop(&stack, &val);
    stack_pop(&stack, &val);
    stack_pop(&stack, &val);
    printf("val popped out: %d\n", val);
    stack_print(&stack);
    printf("-------incorrect pop stop--------\n");
    printf("=======pop stop=========\n");

    return 0;
}
