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

std::vector<std::vector<int>> ArraySaver::getArrays()
{
    return arrays;
}

void ArraySaver::outArrays()
{
    std::cout<<"Size = "<<size<<std::endl;
    for(std::vector<int> vec : arrays){
        for(int n : vec){
            std::cout<<n<<' ';
        }
        std::cout<<std::endl;
    }
    std::cout<<std::endl;
}
