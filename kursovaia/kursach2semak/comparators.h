#ifndef COMPARATORS_H
#define COMPARATORS_H

// ��������� ������� ���������
int compare_int(void* a1, void* a2);
int compare_double(void* a1, void* a2);
int compare_char(void* a1, void* a2);

// ���������� ������� ���������� �� ������� ���������
extern int (*compare[3])(void* a1, void* a2);

#endif // COMPARATORS_H
