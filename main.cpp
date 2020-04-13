#include "TypeSaver.h"
#include "ArraySaver.h"
#include "DataReader.h"
#include "LeonardoNumber.h"
#include "SortTimer.h"
#include "sorts.h"
#include <iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

#define N 30000000
#define TWO_POW_31 2147483648
int main()
{
    string file_path = "input.txt";
    DataReader dr = DataReader(file_path);
    dr.readAllData();

    string out_path = "output2.txt";
    SortTimer st = SortTimer(dr.getAllData());
    st.outTimeEverySort(out_path);

    return 0;
}
