#include "TypeSaver.h"
#include "ArraySaver.h"
#include <iostream>
#include<vector>
#include<string>

using namespace std;

int main()
{
    std::vector<std::vector<int>> data;
    int arr1[5] = {1,2,3,4,5};
    int arr2[5] = {2,3,4,5,6};

    vector<int> vec1(arr1, arr1+5);
    vector<int> vec2(arr2, arr2+5);
    data.push_back(vec1);
    data.push_back(vec2);

    ArraySaver as = ArraySaver(5, data);
    as.outArrays();
    return 0;
}