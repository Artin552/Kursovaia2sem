# SORT(1) USER COMMANDS SORT(1)

## NAME
sort \- array sorting

## SYNOPSIS
\`#include "base.h"\`
\`#include "comparators.h"\`

\`int sort_set_method();\`
\`void change_elemsize();\`
\`void printArray(const void *array, size_t size);\`
\`void sort(void *array, size_t size, size_t elemsize, int (*compare)(const void *, const void *));\`

## DESCRIPTION
\`sort\` - program for sorting an array of integers.

### Options
- \`type\` - data type of the array elements. In this program, the type \`INT\` is used.
- \`method\` - sorting method. In this program, the method \`SORT_METHOD_HEAP\` is used.
- \`direction\` - sorting direction. In this program, the direction \`SORT_DIRECTION_ASCENDING\` is used.
- \`elemsize\` - size of one array element. In this program, the size of an element of type \`int\` is used.

### Functions

#### int sort_set_method()
Sets the sorting method.

#### void change_elemsize()
Changes the size of the array element.

#### void printArray(const void *array, size_t size)
Prints the array elements to the screen.

- \`array\` - pointer to the array.
- \`size\` - number of elements in the array.

#### void sort(void *array, size_t size, size_t elemsize, int (*compare)(const void *, const void *))
Sorts the array according to the specified sorting method and direction.

- \`array\` - pointer to the array.
- \`size\` - number of elements in the array.
- \`elemsize\` - size of one array element.
- \`compare\` - function to compare elements.

### Usage
The program performs the following steps:
1. Sets the data type of the array elements (\`INT\`).
2. Sets the sorting method (\`SORT_METHOD_HEAP\`).
3. Sets the sorting direction (\`SORT_DIRECTION_ASCENDING\`).
4. Changes the size of the array element.
5. Creates an array of 3 elements and fills it with the values \`3, 3473, 7\`.
6. Prints the initial array to the screen.
7. Sorts the array.
8. Prints the sorted array to the screen.

## EXAMPLES
\`sort\` prints the initial and sorted array to the screen.

## SEE ALSO
\`qsort(3)\`, \`heapsort(3)\`

## AUTHOR
Written by Artem Pronin

## REPORTING BUGS
Report bugs to pronin5524@gmail.com

SORT(1) May 2024 SORT(1)
