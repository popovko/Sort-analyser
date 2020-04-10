#ifndef ARRAYSAVER_H
#define ARRAYSAVER_H
#include<vector>

using namespace std;

class ArraySaver
{
private:
    int size;
    vector<vector<int>> arrays;
public:
    ArraySaver(int size, vector<vector<int>> arrays);
    virtual ~ArraySaver();

    int getSize();
    vector<vector<int>> getArrays();
    void outArrays();
};

#endif // ARRAYSAVER_H
