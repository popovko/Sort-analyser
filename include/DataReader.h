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

    void readAllData();
    TypeSaver readNextType(ifstream & file);
    ArraySaver readNextArrays(ifstream & file);
    void outAllData();
    vector<TypeSaver> getAllData();
};

#endif // DATAREADER_H
