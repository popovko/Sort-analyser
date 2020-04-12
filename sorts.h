#ifndef SORTS_H_INCLUDED
#define SORTS_H_INCLUDED

#define MAX 10000
#define MAX2 20000

#define IS_EMPTY(e) (e<0)
#define NONE -1
//INTROSORT
    void introsort(int * arr, int *begin, int *end);

//COUNTING SORT
    void countingSort(int *arr, int size);

//LIBRARY SORT
    void librarySort(int * arr, int n);

//SMOOTH SORT
    void smoothsort (int * arr, int _n);
#endif // SORTS_H_INCLUDED
