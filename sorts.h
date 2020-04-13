#ifndef SORTS_H_INCLUDED
#define SORTS_H_INCLUDED

#include<map>
#include<algorithm>
#include<vector>
#include<string>
#include<iostream>
#include<fstream>
#include<cmath>

#include"DataReader.h"
#include"LeonardoNumber.h"

#define MAX 2000000

#define IS_EMPTY(e) (e<0)
#define NONE -1

using namespace std;
//INTROSORT
    void introsort(int * arr, int *begin, int *end);

//COUNTING SORT
    void countingSort(vector<int> arr, int size);

//LIBRARY SORT
    void librarySort(int * arr, int n);

//SMOOTH SORT
    void smoothsort (int * arr, int _n);
#endif // SORTS_H_INCLUDED
