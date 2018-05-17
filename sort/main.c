#include <stdio.h>
#include "qsort.h"

#define N 6

int main()
{
    int array[N] = {15, 23, 1, 34, 89, 43};

    qsort(array, 0, N - 1);

    int i;
    for (i = 0; i < N; i++) {
        printf("%d\n", array[i]);
    }

    return 0;
}

