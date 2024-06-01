#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "base.h"
#include "comparators.h"


void test() {
	const int size = 5;
    direction = 1;
    for (int i = 1; i < 9; i++) {
        method = i;
        switch (method) {
        case SORT_METHOD_EXCHANGE:
            printf("bublesort\n");
            break;
        case SORT_METHOD_INSERTION:
            printf("insertionsort\n");
            break;
        case SORT_METHOD_SELECTION:
            printf("selectionsort\n");
            break;
        case SORT_METHOD_COMB:
            printf("combsort\n");
            break;
        case SORT_METHOD_SHELL:
            printf("shellsort\n");
            break;
        case SORT_METHOD_QUICK:
            printf("quicksort\n");
            break;
        case SORT_METHOD_MERGE:
            printf("mergesort\n");
            break;
        case SORT_METHOD_HEAP:
            printf("heapsort\n");
            break;
        }
        type = 0;
        elemsize = sizeof(int);
        int* array_int = (int*)malloc(size * elemsize);
        for (int n = 0; n < size; n++) {
            array_int[n] = rand() % 100;
        }
        printArray(array_int, size);
        sort(array_int, size, elemsize, compare[type]);
        printArray(array_int, size);
        type = 1;
        double* array_double = (double*)malloc(size * elemsize);
        elemsize = sizeof(double);
        for (int n = 0; n < size; n++) {
            array_double[n] = (double)rand() / RAND_MAX * 100;
        }
        printArray(array_double, size);
        sort(array_double, size, elemsize, compare[type]);
        printArray(array_double, size);
        type = 2;
        elemsize = sizeof(char);
        char* array_char = (char*)malloc(size * elemsize);
        for (int n = 0; n < size; n++) {
            array_char[n] = 'A' + rand() % 26;
        }
        printArray(array_char, size);
        sort(array_char, size, elemsize, compare[type]);
        printArray(array_char, size);

    }

    
}