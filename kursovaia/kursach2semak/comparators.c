#include "comparators.h"


int (*compare[3])(void* a1, void* a2) = {
    compare_int,
    compare_double,
    compare_char
};

int compare_int(void* a1, void* a2) {
    int int1 = *(int*)a1;
    int int2 = *(int*)a2;
    if (int1 < int2) return -1;
    if (int1 > int2) return 1;
    return 0;
}

int compare_double(void* a1, void* a2) {
    double double1 = *(double*)a1;
    double double2 = *(double*)a2;
    if (double1 < double2) return -1;
    if (double1 > double2) return 1;
    return 0;
}

int compare_char(void* a1, void* a2) {
    char char1 = *(char*)a1;
    char char2 = *(char*)a2;
    if (char1 < char2) return -1;
    if (char1 > char2) return 1;
    return 0;
}
