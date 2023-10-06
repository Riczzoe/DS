#ifndef SORT_H
#define SORT_H

#define SELECTION_SORT      0
#define INSERTION_SORT      1
#define SHELL_SORT          2
#define MERGE_SORT          3
#define MERGE_SORT_DT       4

void selection_sort(int *elems, int len);
void insertion_sort(int *elems, int len);
void shell_sort(int *elems, int len);
void merge_sort(int *elems, int len);
void merge_sort_dt(int *elems, int len);

#endif // SORT_H
