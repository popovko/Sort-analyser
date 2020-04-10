#include "TypeSaver.h"
#include "ArraySaver.h"
#include "DataReader.h"
#include <iostream>
#include<vector>
#include<string>

using namespace std;

int main()
{
    string file_path = "input.txt";
    DataReader dr = DataReader(file_path);
    dr.read_all_data();
    dr.out_all_data();


    return 0;
}
