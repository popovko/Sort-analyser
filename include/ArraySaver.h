#ifndef ARRAYSAVER_H
#define ARRAYSAVER_H
#include<vector>

const int COUNT_ARRAYS = 5;

class ArraySaver
{
    public:
        int size;
        std::vector<std::vector<int>> data;

        ArraySaver(int size, std::vector<std::vector<int>> data);
        virtual ~ArraySaver();
};

#endif // ARRAYSAVER_H
