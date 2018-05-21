#include <stdio.h>

#define M 3
#define N 6

void merge_ordered_list(int *, int, int *, int, int *);
void list_len(int *);

int main(void) {
    int a[M] = {1,3,19};
    int b[N] = {2,3,6,8,10,12};

    int c[M+N];

    merge_ordered_list(a, M, b, N, c);

    int i;
    for (i = 0; i < M+N;i++) {
        printf("%d\n", c[i]);
    }
}

void merge_ordered_list(int *a, int a_len, int *b, int b_len, int *c) {
    int *pa = a;
    int *pb = b;
    int *pc = c;

    int i = 0, j = 0;

    while (i <= a_len && j <= b_len) {
        if ((j == b_len) || (i < a_len && *pa <= *pb)) {
            *pc++ = *pa++;
            i++;
        }

        if ((i == a_len) || (j < b_len && *pa >= *pb)) {
            *pc++ = *pb++;
            j++;
        }
    }
}
