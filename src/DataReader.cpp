#include "DataReader.h"
#include<string>

DataReader::DataReader(std::string file_path)
{
    this -> file_path = file_path;
    //ctor
}

DataReader::~DataReader()
{
    //dtor
}
