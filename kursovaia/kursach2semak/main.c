#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "base.h"
#include "comparators.h"


int method; 
int direction;
DataType type;
size_t elemsize = sizeof(int);
int main() {
    
    type = INT;
 
    method = SORT_METHOD_HEAP;
    int sort_set_method();
    direction = SORT_DIRECTION_ASCENDING;
    int sort_set_method();
    change_elemsize();

    
    

    const size_t size = 3;
    int array[3] = { 3, 3473, 7 };
    printArray(array, size);
    sort(array, size, elemsize, compare[type]);
    printArray(array, size);
   
    test(5);

    return 0;
}