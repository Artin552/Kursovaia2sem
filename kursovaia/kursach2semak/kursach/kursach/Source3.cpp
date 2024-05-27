// sorts.c
#include "sorts.h"
#include <string.h>
#include <stdio.h>

static void swap(void* a, void* b, int elemsize) {
    void* temp = malloc(elemsize);
    if (temp == NULL) {
        fprintf(stderr, "Memory allocation error.\n");
        exit(EXIT_FAILURE);
    }
    memcpy(temp, a, elemsize);
    memcpy(a, b, elemsize);
    memcpy(b, temp, elemsize);
    free(temp);
}

static void sort_exchange(void* array, int size, int elemsize, int (*comp)(void* a1, void* a2)) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (comp((char*)array + j * elemsize, (char*)array + (j + 1) * elemsize) > 0) {
                swap((char*)array + j * elemsize, (char*)array + (j + 1) * elemsize, elemsize);
            }
        }
    }
}

static void sort_insertion(void* array, int size, int elemsize, int (*comp)(void* a1, void* a2)) {
    for (int i = 1; i < size; i++) {
        int j = i;
        while (j > 0 && comp((char*)array + (j - 1) * elemsize, (char*)array + j * elemsize) > 0) {
            swap((char*)array + (j - 1) * elemsize, (char*)array + j * elemsize, elemsize);
            j--;
        }
    }
}

static void sort_selection(void* array, int size, int elemsize, int (*comp)(void* a1, void* a2)) {
    for (int i = 0; i < size - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < size; j++) {
            if (comp((char*)array + j * elemsize, (char*)array + min_idx * elemsize) < 0) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            swap((char*)array + i * elemsize, (char*)array + min_idx * elemsize, elemsize);
        }
    }
}

static void sort_comb(void* array, int size, int elemsize, int (*comp)(void* a1, void* a2)) {
    int gap = size;
    const double shrink = 1.3;
    int sorted = 0;

    while (!sorted) {
        gap = (int)(gap / shrink);
        if (gap <= 1) {
            gap = 1;
            sorted = 1;
        }
        for (int i = 0; i + gap < size; i++) {
            if (comp((char*)array + i * elemsize, (char*)array + (i + gap) * elemsize) > 0) {
                swap((char*)array + i * elemsize, (char*)array + (i + gap) * elemsize, elemsize);
                sorted = 0;
            }
        }
    }
}

static void sort_shell(void* array, int size, int elemsize, int (*comp)(void* a1, void* a2)) {
    for (int gap = size / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < size; i++) {
            for (int j = i; j >= gap && comp((char*)array + (j - gap) * elemsize, (char*)array + j * elemsize) > 0; j -= gap) {
                swap((char*)array + j * elemsize, (char*)array + (j - gap) * elemsize, elemsize);
            }
        }
    }
}

static int reverse_compare(int (*comp)(void* a1, void* a2), void* a1, void* a2) {
    return comp(a2, a1);
}

int sort(void* array, int size, int elemsize, int (*comp)(void* a1, void* a2), int method, int direction) {
    if (array == NULL || size <= 0 || elemsize <= 0 || comp == NULL) {
        return -1; // Invalid parameters
    }

    if (direction == SORT_DIRECTION_DESCENDING) {
        comp = reverse_compare;
    }

    switch (method) {
    case SORT_METHOD_EXCHANGE:
        sort_exchange(array, size, elemsize, comp);
        break;
    case SORT_METHOD_INSERTION:
        sort_insertion(array, size, elemsize, comp);
        break;
    case SORT_METHOD_SELECTION:
        sort_selection(array, size, elemsize, comp);
        break;
    case SORT_METHOD_COMB:
        sort_comb(array, size, elemsize, comp);
        break;
    case SORT_METHOD_SHELL:
        sort_shell(array, size, elemsize, comp);
        break;
    default:
        return -1; // Invalid sort method
    }

    return 0; // Success
}
