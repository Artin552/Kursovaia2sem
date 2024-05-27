#ifndef SORTS_H
#define SORTS_H

void bubble_sort(void* array, int size, int elemsize, int (*comp)(void* a1, void* a2));
void insertion_sort(void* array, int size, int elemsize, int (*comp)(void* a1, void* a2));
void selection_sort(void* array, int size, int elemsize, int (*comp)(void* a1, void* a2));
void comb_sort(void* array, int size, int elemsize, int (*comp)(void* a1, void* a2));
void shell_sort(void* array, int size, int elemsize, int (*comp)(void* a1, void* a2));
void quick_sort(void* array, size_t size, size_t elemsize, int (*comp)(void* a1, void* a2));
void merge_sort(void* array, size_t size, size_t elemsize, int (*comp)(void* a1, void* a2));
void heap_Sort(void* array, int size, int elemsize, int(*comp)(void*, void*));
int heapify(void* array, int size, int i, int elemsize, int(*comp)(void*, void*));

#endif
