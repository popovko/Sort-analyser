#ifndef DATAREADER_H
#define DATAREADER_H
#include<string>

class DataReader
{
private:
    std::string file_path;

public:
    DataReader(std::string file_path);
    virtual ~DataReader();
};

#endif // DATAREADER_H
