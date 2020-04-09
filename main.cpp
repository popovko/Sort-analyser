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

    std::vector<std::vector<int>> data2;
    int arr3[5] = {16,2,35,4,5};
    int arr4[5] = {2,37,4,5,67};

    vector<int> vec3(arr3, arr3+5);
    vector<int> vec4(arr4, arr4+5);
    data2.push_back(vec3);
    data2.push_back(vec4);

    ArraySaver as = ArraySaver(5, data);

    ArraySaver as2 = ArraySaver(5, data2);

    vector<ArraySaver> vecAS;
    vecAS.push_back(as);
    vecAS.push_back(as2);

    TypeSaver ts = TypeSaver("first type saver", vecAS);
    ts.outData();
    return 0;
}
