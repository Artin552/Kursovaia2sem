#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "base.h"
#include "comparators.h"
#include "test.h"



int method; 
int direction;
DataType type;
size_t elemsize = sizeof(int);
int main() {
    /*
    printf("Write a type of array\n int = 0\n double = 1\n char = 2\n");
    scanf("%d", &type);

    srand(time(NULL));
    const int size;
    printf("Write the size of the array ");
    scanf("%d", &size);
    if (type == 0) {
        change_elemsize();
        int* array_int = (int*)malloc(size * elemsize);
        for (int i = 0; i < size; i++) {
            array_int[i] = rand() % 100;
        }
        
        printArray(array_int, size);
        printf("Write a name of sort\n(1 - bubbleSort)\n(2 - insertionSort)\
        \n(3 - selectionSort)\n(4 - combSort)\n(5 - shellSort)\n(6 - quickSort)\n(7 - mergeSort)\n(8 - heapSort)\ninput ");
        scanf(" %d", &method);
        sort_set_method();
        printf("\n");
        printf("Write a direction os sort - ASCENDING = 1 and DESCENDING = 2\n");
        scanf("%d", &direction);
        sort_set_direction();
        sort(array_int, size, elemsize,compare[type]);
        printArray(array_int, size);
    }
    else if (type == 1) {
            change_elemsize();
            double* array_double = (double*)malloc(size * elemsize);
            
            for (int i = 0; i < size; i++) {
                array_double[i] = (double)rand() / RAND_MAX * 100;
            }

            printArray(array_double, size);
            printf("Write a name of sort\n(1 - bubbleSort)\n(2 - insertionSort)\n(3 - selectionSort)\
            \n(4 - combSort)\n(5 - shellSort)\n(6 - quickSort)\n(7 - mergeSort)\n(8 - heapSort)\ninput ");
            scanf(" %d", &method);
            sort_set_method();
            printf("\n");
            printf("Write a direction os sort - ASCENDING = 1 and DESCENDING = 2\n");
            scanf("%d", &direction);
            sort_set_direction();
            sort(array_double, size, elemsize, compare[type]);
            printArray(array_double, size);
    }
    else if (type == 2) {
        change_elemsize();
        char* array_char = (char*)malloc(size * elemsize);

        for (int i = 0; i < size; i++) {
            array_char[i] = 'A' + rand() %26;
        }

        printArray(array_char, size);
        printf("Write a name of sort\n(1 - bubbleSort)\n(2 - insertionSort)\n(3 - selectionSort)\
        \n(4 - combSort)\n(5 - shellSort)\n(6 - quickSort)\n(7 - mergeSort)\n(8 - heapSort)\ninput ");
        scanf(" %d", &method);
        sort_set_method();
        printf("\n");
        printf("Write a direction os sort - ASCENDING = 1 and DESCENDING = 2\n");
        scanf("%d", &direction);
        sort_set_direction();
        sort(array_char, size, elemsize, compare[type]);
        printArray(array_char, size);
    }
    */
    
    test();
    return 0;
}
