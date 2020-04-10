#include<iostream>
#include"TypeSaver.h"

TypeSaver::TypeSaver(string type_name, vector<ArraySaver> data)
{
    this -> type_name = type_name;
    this -> data = data;
}

TypeSaver::~TypeSaver()
{
    //dtor
}

string TypeSaver::getTypeName()
{
    return type_name;
}

vector<ArraySaver> TypeSaver::getData()
{
    return data;
}

void TypeSaver::outData()
{
    cout<<type_name<<endl;
    for(ArraySaver arrs : data)
    {
        arrs.outArrays();
    }
}
