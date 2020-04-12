#ifndef SORTS_H_INCLUDED
#define SORTS_H_INCLUDED

#define MAX 10000
#define MAX2 20000

#define IS_EMPTY(e) (e<0)
#define NONE -1
//INTROSORT
    void introsort(int arr[], int *begin, int *end);
    void introsortUtil(int arr[], int * begin, int * end, int depthLimit);
    int *medianOfThree(int * a, int * b, int * c);
    int* partition(int arr[], int low, int high);
    void insertionSort(int arr[], int *begin, int *end);
    void swapValue(int *a, int *b);
//END INTROSORT

//COUNTING SORT
    int getMax(int arr[], int size);
    void countingSort(int *arr, int size);
//END COUNTING SORT

//LIBRARY SORT
    void librarySort(int A[], int n);
    void libSort(int A[], int N, int S[], int EPSILON);
    int searchFree(int e, int sorted[], int last);
    void prepareLibrarySort(int epsilon, int n, int S[], int * sLen);
//END LIBRARY SORT
#endif // SORTS_H_INCLUDED
