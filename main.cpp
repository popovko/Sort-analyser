#include "TypeSaver.h"
#include "ArraySaver.h"
#include "DataReader.h"
#include "sorts.h"
#include <iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

int main()
{
    string file_path = "input.txt";
    DataReader dr = DataReader(file_path);
    dr.readAllData();

    vector<int> v = dr.getAllData().at(0).getData().at(0).getArrays().at(2);
    const int n = v.size();
    int arr[n];
    copy(v.begin(), v.end(), arr);

    introsort(arr, arr, arr + n);

    for(int i = 0 ;i < v.size(); i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    copy(v.begin(), v.end(), arr);
    countingSort(arr, n);
     for(int i = 0 ;i <n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    copy(v.begin(), v.end(), arr);
    librarySort(arr, n);
    cout<<endl;
     for(int i = 0 ;i <n; i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}
