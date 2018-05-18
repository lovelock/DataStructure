#include <stdio.h>

#define ARRAY_LEN 6

void var_export(int *, int);

void qsort(int *, int, int);

int main()
{
    int array[ARRAY_LEN] = {3, 9, 2, 1, 0, 43};

    var_export(array, ARRAY_LEN);

    qsort(array, 0, ARRAY_LEN - 1);

    var_export(array, ARRAY_LEN);

    return 0;
}


void qsort(int * array, int low, int high) {

    if (low >= high) {
        return;
    }

    int first = low;
    int last = high;
    int pivot = array[first];

    while (first < last) {
        while (first < last && array[last] > pivot) {
            --last;
        }

        if (first < last) {
            array[first] = array[last];
        }

        while (first < last && array[first] < pivot) {
            ++first;
        }

        if (first < last) {
            array[last] = array[first];
        }
    }

    array[first] = pivot; // equals array[last] = pivot; because last = first

    qsort(array, low, first - 1);
    qsort(array, first + 1, high);

}

void var_export(int * array, int len) {
    printf("\n[\n");

    int i = 0;

    for(;i < len; i++) {
        printf("\t%d,\n", array[i]);
    }

    printf("]\n");
}
