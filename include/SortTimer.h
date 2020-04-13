#ifndef SORTTIMER_H
#define SORTTIMER_H
#include"DataReader.h"
#include"../sorts.h"
#include<iostream>
#include<fstream>
#include<string>
#include <ctime>
#include <algorithm>

using namespace std;

class SortTimer
{
private:
    vector<TypeSaver> allData;

public:
    SortTimer(vector<TypeSaver> allData);
    virtual ~SortTimer();

    void outTimeEverySort(string outPath);
};

#endif // SORTTIMER_H
