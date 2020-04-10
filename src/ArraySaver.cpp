#include"ArraySaver.h"
#include<iostream>

ArraySaver::ArraySaver(int size, std::vector<std::vector<int>> arrays)
{
    this -> size = size;
    this -> arrays = arrays;
    //ctor
}

ArraySaver::~ArraySaver()
{
    //dtor
}

int ArraySaver::getSize()
{
    return size;
}

vector<vector<int>> ArraySaver::getArrays()
{
    return arrays;
}

void ArraySaver::outArrays()
{
    cout<<"Size = "<<size<<endl;
    for(vector<int> vec : arrays){
        for(int n : vec){
            cout<<n<<' ';
        }
        cout<<endl;
    }
    cout<<endl;
}
