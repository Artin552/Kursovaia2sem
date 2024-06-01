#include <stdlib.h>
#include <string.h>
#include "sorts.h"
#include "base.h"

void bubble_sort(void* array, int size, int elemsize, int (*comp)(void* a1, void* a2)) {
    if (size < 2) return;

    for (size_t i = 0; i < size - 1; ++i) {
        int swapped = 0;
        for (size_t j = 0; j < size - i - 1; ++j) {
            void* elem1 = (char*)array + j * elemsize;
            void* elem2 = (char*)array + (j + 1) * elemsize;

            if (comp(elem1, elem2) > 0) {
                swap(elem1, elem2, elemsize);
                swapped = 1;
            }
        }
        // If no elements were swapped, the array is already sorted
        if (!swapped) break;
    }
    if (direction == 2) {
        reverse(array, size, elemsize);
    }
}

void insertion_sort(void* array, int size, int elemsize, int (*comp)(void* a1, void* a2)) {
    char* arr = (char*)array;
    for (int i = 1; i < size; i++) {
        char* key = (char*)malloc(elemsize);
        memcpy(key, arr + i * elemsize, elemsize);
        int j = i - 1;
        while (j >= 0 && comp(arr + j * elemsize, key) > 0) {
            memcpy(arr + (j + 1) * elemsize, arr + j * elemsize, elemsize);
            j--;
        }
        memcpy(arr + (j + 1) * elemsize, key, elemsize);
        free(key);
    }
    if (direction == 2) {
        reverse(array, size, elemsize);
    }
}

void selection_sort(void* array, int size, int elemsize, int (*comp)(void* a1, void* a2)) {
    char* arr = array;
    for (int i = 0; i < size - 1; i++) {
        int selected = i;
        for (int j = i + 1; j < size; j++) {
            void* a = arr + j * elemsize;
            void* b = arr + selected * elemsize;
            if (comp(a,b) < 0) selected = j;
        }
        if (selected != i) {
            swap(arr + i * elemsize, arr + selected * elemsize, elemsize);
        }
    }
    if (direction == 2) reverse(array, size, elemsize);
}

void comb_sort(void* array, int size, int elemsize, int (*comp)(void* a1, void* a2)) {
    char* arr = array;
    int gap = size;
    int swapped = 1;
    while (gap != 1 || swapped) {
        gap = (gap * 10) / 13;
        if (gap < 1) gap = 1;
        swapped = 0;
        for (int i = 0; i < size - gap; i++) {
            void* a = arr + i * elemsize;
            void* b = arr + (i + gap) * elemsize;
            int cmp = (direction == SORT_DIRECTION_ASCENDING) ? comp(a, b) : comp(b, a);
            if (cmp > 0) {
                swap(a, b, elemsize);
                swapped = 1;
            }
        }
    }
    if (direction == 2) {
        reverse(array, size, elemsize);
    }
}

void shell_sort(void* array, int size, int elemsize, int (*comp)(void* a1, void* a2)) {
    char* arr = array;
    for (int gap = size / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < size; i++) {
            char* temp = malloc(elemsize);
            memcpy(temp, arr + i * elemsize, elemsize);
            int j;
            for (j = i; j >= gap; j -= gap) {
                void* a = arr + (j - gap) * elemsize;
                int cmp = (direction == SORT_DIRECTION_ASCENDING) ? comp(a, temp) : comp(temp, a);
                if (cmp <= 0) break;
                memcpy(arr + j * elemsize, a, elemsize);
            }
            memcpy(arr + j * elemsize, temp, elemsize);
            free(temp);
        }
    }
    if (direction == 2) {
        reverse(array, size, elemsize);
    }
}

void quick_sort(void* array, size_t size, size_t elemsize, int (*comp)(void* a1, void* a2)) {
    if (size < 2) return;

    char* base = (char*)array;
    void* pivot = base + (size / 2) * elemsize;
    size_t i = 0;
    size_t j = size - 1;

    while (i <= j) {
        while (direction * comp(base + i * elemsize, pivot) < 0) {
            i++;
        }
        while (direction * comp(base + j * elemsize, pivot) > 0) {
            j--;
        }
        if (i <= j) {
            swap(base + i * elemsize, base + j * elemsize, elemsize);
            i++;
            j--;
        }
    }

    if (j > 0) {
        quick_sort(base, j + 1, elemsize, comp, direction);
    }
    if (i < size) {
        quick_sort(base + i * elemsize, size - i, elemsize, comp, direction);
   
    }
    if (direction == 2) reverse(array, size, elemsize);
}

void merge_sort(void* array, size_t size, size_t elemsize, int (*comp)(void* a1, void* a2)) {
    if (size < 2) return;

    char* base = (char*)array;
    void* pivot = base + (size / 2) * elemsize;
    size_t i = 0;
    size_t j = size - 1;

    while (i <= j) {
        while (direction * comp(base + i * elemsize, pivot) < 0) {
            i++;
        }
        while (direction * comp(base + j * elemsize, pivot) > 0) {
            j--;
        }
        if (i <= j) {
            swap(base + i * elemsize, base + j * elemsize, elemsize);
            i++;
            j--;
        }
    }

    if (j > 0) {
        merge_sort(base, j + 1, elemsize, comp, direction);
    }
    if (i < size) {
        merge_sort(base + i * elemsize, size - i, elemsize, comp, direction);

    }
    if (direction == 2) reverse(array, size, elemsize);
}
int heapify(void* array, int size, int i, int elemsize, int(*comp)(void*, void*)) {
    char* arr = (char*)array;
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && comp(arr + left * elemsize, arr + largest * elemsize) > 0) {
        largest = left;
    }

    if (right < size && comp(arr + right * elemsize, arr + largest * elemsize) > 0){
        largest = right;
    }

    if (largest != i) {
        swap(arr + i * elemsize, arr + largest * elemsize, elemsize);
        heapify(arr, size, largest, elemsize, comp);
    }

}

void heap_Sort(void* array, int size, int elemsize, int(*comp)(void*, void*)) {
    char* arr = (char*)array;
    for (int i = size / 2 - 1; i >= 0; i--) {
        heapify(arr, size, i, elemsize, comp);
    }

    for (int i = size - 1; i > 0; i--) {
        swap(arr, arr + i * elemsize, elemsize);
        heapify(arr, i, 0, elemsize, comp);
    }
    if (direction == 2) reverse(array, size, elemsize);
}



    