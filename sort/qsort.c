#include <stdio.h>
#include "qsort.h"


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
