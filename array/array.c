#include <stdlib.h>
#include <stdio.h>
#include "array.h"

int array_init(array *arr, int cap) {
    arr->pBase = (int *) malloc(sizeof(int) * cap);
    if (arr->pBase == NULL) {
        return FALSE;
    }
    arr->cap = cap;
    arr->len = 0;

    return TRUE;
}

int array_is_empty(array *arr) {
    return arr->cap == 0;
}

int array_is_full(array *arr) {
    return arr->cap == arr->len;
}

int array_get(array *arr, int index, int *value) {
    if (array_is_empty(arr)) {
        printf("array arr is empty\n");
        return FALSE;
    }

    if (index < 0 || index > arr->len) {
        printf("index out of bound\n");
        return FALSE;
    }

    *value = arr->pBase[index];

    return TRUE;
}

void array_show(array *arr) {
    int i;

    printf("array:\t\t");
    for (i = 0; i < arr->len; i++) {
        printf("%d: %d\t", i, arr->pBase[i]);
    }
    printf("\n");
}

int array_insert(array *arr, int index, int data) {
    if (array_is_full(arr)) {
        printf("array is full, no elements can be inserted\n");
        return FALSE;
    }

    if (index < 0 || index > arr->cap - 1) {
        printf("index out of bound\n");
        return FALSE;
    }

    int i;

    for (i = arr->len; i > index; i--) {
        arr->pBase[i] = arr->pBase[i-1];
    }

    arr->pBase[index] = data;
    arr->len++;

    return TRUE;
}

int array_append(array *arr, int data) {
    return array_insert(arr, arr->len, data);
}

int array_prepend(array *arr, int data) {
    return array_insert(arr, 0, data);
}

int array_unshift(array *arr, int data) {
    return array_prepend(arr, data);
}

int array_delete(array *arr, int index, int *value) {
    if (array_is_empty(arr)) {
        printf("array is empty\n");
        return FALSE;
    }

    if (index < 0 || index > arr->len - 1) {
        printf("index out of bound\n");
        return FALSE;
    }

    *value = arr->pBase[index];

    int i;
    for (i = index; i < arr->len; i++) {
        arr->pBase[i] = arr->pBase[i+1];
    }
    arr->pBase[arr->len-1] = 0;
    arr->len--;

    return TRUE;
}

int array_pop(array *arr, int *value) {
    return array_delete(arr, arr->len - 1, value);
}

int array_shift(array *arr, int *value) {
    return array_delete(arr, 0, value);
}

void array_sort(array *arr) {
    int i, j;

    for (i = 0; i < arr->len - 1; i++) {
        for (j = i + 1; j < arr->len; j++) {
            if (arr->pBase[i] > arr->pBase[j]) {
                array_swap(arr, i, j);
            }
        }
    }
}

void array_swap(array *arr, int i, int j) {
    if (array_is_empty(arr)) {
        printf("array is empty\n");
    }

    int tmp = arr->pBase[i];
    arr->pBase[i] = arr->pBase[j];
    arr->pBase[j] = tmp;
}

int partition(array *arr, int i, int j) {
    int mid = arr->pBase[i];

    while (i < j) {
        while (i < j && arr->pBase[j] >= mid) {
            j--;
        }

        if (i < j) {
            arr->pBase[i] = arr->pBase[j];
            i++;
        }

        while (i < j && arr->pBase[i] <= mid) {
            i++;
        }

        if (i < j) {
            arr->pBase[j] = arr->pBase[i];
            j--;
        }
    }

    arr->pBase[i] = mid;

    return i;
}

void array_qsort(array *arr, int low, int high) {
    int mid;

    if (low < high) {
        mid = partition(arr, low, high);
        array_qsort(arr, low, mid - 1);
        array_qsort(arr, mid + 1, high);
    }

}

