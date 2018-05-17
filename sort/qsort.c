#include <stdio.h>

#define N 6

void qsort(int *, int, int);

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


void qsort(int *array, int low, int high) {
    if (low >= high) {
        return;
    }

    int first = low;
    int last = high;
    int key = array[first];

    while (first < last) {
        while (first < last && array[last] > key) {
            last--;
        }

        if (first < last) {
            array[first] = array[last];
        }

        while (first < last && array[first] < key) {
            first++;
        }

        if (first < last) {
            array[last] = array[first];
        }
    }

    array[first] = key;

    qsort(array, low, first -1);
    qsort(array, first + 1, high);
}
