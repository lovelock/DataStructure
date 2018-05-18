#ifndef DATASTRUCTURE_STACK_H
#define DATASTRUCTURE_STACK_H value


typedef struct node {
    int data;
    struct node *p_next;
} *p_node_t, node_t;

typedef struct {
    p_node_t p_top;
    p_node_t p_bottom;
} *p_stack_t, stack_t;

int stack_init(p_stack_t);
int stack_push(p_stack_t, int);
int stack_pop(p_stack_t, int *);
void stack_print(p_stack_t);

#endif /* ifndef DATASTRUCTURE_STACK_H */
