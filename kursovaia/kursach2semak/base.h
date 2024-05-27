#ifndef BASE_H
#define BASE_H

typedef enum {
    INT,
    DOUBLE,
    CHAR
} DataType;

int method;
int direction;
int type;
size_t elemsize; 
#define SORT_METHOD_EXCHANGE 1
#define SORT_METHOD_INSERTION 2
#define SORT_METHOD_SELECTION 3
#define SORT_METHOD_COMB 4
#define SORT_METHOD_SHELL 5
#define SORT_METHOD_QUICK 6
#define SORT_METHOD_MERGE 7
#define SORT_METHOD_HEAP 8

#define SORT_DIRECTION_ASCENDING 1
#define SORT_DIRECTION_DESCENDING 2
void change_elemsize();
int sort_set_method();
int sort_set_direction();
int sort(void* array, int size, int elemsize, int (*comp)(void* a1, void* a2));
void reverse(void* array, size_t size, size_t elemsize);
void swap(void* a, void* b, int size);
void printArray(void* array, size_t size);
 

#endif
