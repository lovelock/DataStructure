#include <stdio.h>
#include <stdlib.h>

typedef struct {
    void * (*walk)();
    void (*count)(int);
} *p_cat_t, cat_t;


void * walk() {
    printf("I' am cat and I can walk\n");
}

void count(int c) {
    printf("I can count to %d\n", c);
}


int main() {

    p_cat_t p_cat = (p_cat_t)malloc(sizeof(cat_t));

    p_cat->count = count;
    p_cat->walk = walk;

    p_cat->walk();
    p_cat->count(200);

    free(p_cat);

    cat_t cat = {
      count: count,
      walk: walk,
    };
    cat.walk();
    cat.count(100);

    return 0;
}
