#ifndef ARRAYSAVER_H
#define ARRAYSAVER_H
#include<vector>

const int COUNT_ARRAYS = 5;

class ArraySaver
{
private:
    int size;
    std::vector<std::vector<int>> arrays;
public:
    ArraySaver(int size, std::vector<std::vector<int>> arrays);
    virtual ~ArraySaver();

    int getSize();
    std::vector<std::vector<int>> getArrays();
    void outArrays();
};

#endif // ARRAYSAVER_H
