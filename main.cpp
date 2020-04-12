#include "TypeSaver.h"
#include "ArraySaver.h"
#include "DataReader.h"
#include "LeonardoNumber.h"
#include "sorts.h"
#include <iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

#define N 2000
int main()
{
    string file_path = "input.txt";
    DataReader dr = DataReader(file_path);
    dr.readAllData();

    int* mas = new int[N];
    for(int i = 0; i<N; i++){
        mas[N-i-1] = i;
    }

    //vector<int> v = dr.getAllData().at(0).getData().at(0).getArrays().at(2);
    //const int n = v.size();
    //int arr[n];
    //copy(v.begin(), v.end(), arr);

    //introsort(mas, mas, mas + N);

    //for(int i = 0 ;i < N; i++){
      //  cout<<mas[i]<<" ";
   //}
    //cout<<endl;
    //copy(v.begin(), v.end(), arr);
   // countingSort(mas, N);
    // for(int i = 0 ;i <N; i++){
     //   cout<<mas[i]<<" ";
    //}
    //cout<<endl;
   // copy(v.begin(), v.end(), arr);
    introsort(mas,mas, mas+N-1);
    cout<<endl;
     for(int i = 0 ;i <N; i++){
        cout<<mas[i]<<" ";
    }

    return 0;
}
