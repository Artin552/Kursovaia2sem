#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "base.h"
#include "sorts.h"
#include "comparators.h"

int sort_set_method() {
    if (1 <= method && method <= 8) {
        return 0;
    }
    method = 1;
    printf("Wrong method\nDefault value has been set\n");
    return 1;
}

//setter for direction
int sort_set_direction() {
    if (1 <= direction && direction <= 2) {
        return 0;
    }
    direction = 1;
    printf("Wrong direction\nDefault value has been set\n");
    return 1;
}

void change_elemsize() {
    switch (type) {
    case INT:
        break;
    case DOUBLE:
        elemsize = sizeof(double);
        break;
    case CHAR:
        elemsize = sizeof(char);
        break;
    }
}

void printArray(void* array,  size_t size) {
    for (size_t i = 0; i < size; ++i) {
        switch (type) {
        case INT:
            printf("%d ", ((int*)array)[i]);
            break;
        case DOUBLE:
            printf("%.2f ", ((double*)array)[i]);
            break;
        case CHAR:
            printf("%c ", ((char*)array)[i]);
            break;
        }
    }
    printf("\n");
}


void swap(void* a, void* b, int size) {
    void* temp = malloc(size);
    if (temp == NULL) {
        fprintf(stderr, "Memory allocation error\n");
        exit(EXIT_FAILURE);
    }
    memcpy(temp, a, size);
    memcpy(a, b, size);
    memcpy(b, temp, size);
    free(temp);
}
void reverse(void* array, size_t size, size_t elemsize) {
    char* base = (char*)array;
    size_t i, j;
    char* temp = malloc(elemsize);

    if (!temp) {
        printf("Ошибка выделения памяти\n");
        return;
    }

    for (i = 0, j = size - 1; i < j; i++, j--) {
        char* front = base + i * elemsize;
        char* back = base + j * elemsize;
        memcpy(temp, front, elemsize);
        memcpy(front, back, elemsize);
        memcpy(back, temp, elemsize);
    }

    free(temp);
}

int sort(void* array, size_t size, size_t elemsize, int (*comp)(void* a1, void* a2)) {
    if (array == NULL || size <= 0 || elemsize <= 0 || comp == NULL) {
        return -1; // Invalid parameters
    }

    switch (method) {
    case SORT_METHOD_EXCHANGE:
        bubble_sort(array, size, elemsize, comp);
        break;
    case SORT_METHOD_INSERTION:
        insertion_sort(array, size, elemsize, comp);
        break;
    case SORT_METHOD_SELECTION:
        selection_sort(array, size, elemsize, comp);
        break;
    case SORT_METHOD_COMB:
        comb_sort(array, size, elemsize, comp);
        break;
    case SORT_METHOD_SHELL:
        shell_sort(array, size, elemsize, comp);
        break;
    case SORT_METHOD_QUICK:
        quick_sort(array, size, elemsize, comp);
        break;
    case SORT_METHOD_MERGE:
        merge_sort(array, size, elemsize, comp);
        break;
    case SORT_METHOD_HEAP:
        heap_Sort(array, size, elemsize, comp);
        break;
    default:
        return -2; // Unknown sorting method
    }
   
}
