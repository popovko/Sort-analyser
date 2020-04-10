#ifndef DATAREADER_H
#define DATAREADER_H
#include<string>
#include<vector>
#include<iostream>
#include<fstream>
#include"TypeSaver.h"

using namespace std;

class DataReader
{
private:
    string file_path;
    vector<TypeSaver> all_data;

public:
    DataReader(string file_path);
    virtual ~DataReader();

    void read_all_data();
    TypeSaver read_next_type(ifstream & file);
    ArraySaver read_next_arrays(ifstream & file);
    void out_all_data();
};

#endif // DATAREADER_H
