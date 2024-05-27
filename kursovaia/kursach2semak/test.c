#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "base.h"
#include "comparators.h"

void* createArray( int size, int elemsize) {
    void* array = malloc(elemsize * size);
    if (!array) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    switch (type) {
    case CHAR: // char
        for (int i = 0; i < size; i++) {
            ((char*)array)[i] = rand() % 512;
        }
        break;
    case INT: // int 
        for (int i = 0; i < size; i++) {
            ((int*)array)[i] = rand();
        }
        break;
    case DOUBLE: // double
        for (int i = 0; i < size; i++) {
            ((double*)array)[i] = rand() / 10.0;
        }
        break;
    default:
        free(array);
        return NULL;
    }

    return array;
}
int test(int size) {
    const int meth[8] = { 1, 2, 3, 4, 5, 6, 7, 8};
    const int types[6] = { 0, 1, 2 };
    for (int set_2 = 0; set_2 < 8; set_2++) {
        for (int set_3 = 0; set_3 < 3; set_3++) {
            sort_set_method(meth[set_2]);
            type = meth[set_3];
            change_elemsize();
            void* array = createArray(size, elemsize);
            sort(array, size, elemsize, compare[meth[set_2]]);
            change_elemsize();
            for (int i = 0; i < size - 1; i++) {
                if (1 == comp(array + i * elemsize, array + (i + 1) * elemsize)) {
                    printf("bad result\n");
                    printArray(array, size ); printf("\n");
                    printf("method: %d data type: %d", set_2, set_3);
                    return -1;
                }
            }
            printf("success, method - %d | type = %d\n", meth[set_2], types[set_3]);
            printArray(array, size); printf("\n");
        }
    }
    return 0;
}