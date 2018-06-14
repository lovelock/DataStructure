#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  float coef;
  int expn;
  struct node *next;
} node, *p_node;

void create_polyn(p_node p, int n) {
    p->next = NULL;

    int i = 0;

    for (; i< n; i++) {
        p_node s = (p_node)malloc(sizeof(node));
        scanf("%f %d", &s->coef, &s->expn);

        p_node p_pre = p;
        p_node q = p->next;

        while (q && q->expn < s->expn) {
            p_pre = q;
            q = q->next;
        }

        s->next = q;
        p_pre->next = s;
    }
}

void add_polyn(p_node pa, p_node pb) {
    p_node p1 = pa->next;
    p_node p2 = pb->next;

    int sum;

    while (p1 && p2) {
        if (p1->expn == p2->expn) {
            sum = p1->coef + p2->coef;
            if (sum == 0) {
                p_node ppa =
            }
        }
    }
}

int main() {
    p_node p = (p_node)malloc(sizeof(node));

    create_polyn(p, 2);

    p_node p_head = p;

    while (p_head->next != NULL) {
        p_head = p_head->next;
        printf("%f:%d\n", p_head->coef, p_head->expn);
    }

    return 0;
}
