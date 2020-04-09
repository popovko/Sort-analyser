#include<iostream>
#include"TypeSaver.h"

TypeSaver::TypeSaver(std::string type_name, std::vector<ArraySaver> data)
{
    this -> type_name = type_name;
    this -> data = data;
}

TypeSaver::~TypeSaver()
{
    //dtor
}

std::string TypeSaver::getTypeName()
{
    return type_name;
}

void TypeSaver::outData()
{
    std::cout<<type_name<<std::endl;
    for(ArraySaver arrs : data)
    {
        arrs.outArrays();
    }
}
