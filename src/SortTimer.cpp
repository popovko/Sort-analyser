#include "SortTimer.h"

SortTimer::SortTimer(vector<TypeSaver> allData)
{
    this -> allData = allData;
    //ctor
}

SortTimer::~SortTimer()
{
    //dtor
}

void SortTimer::outTimeEverySort(string outPath)
{
    ofstream out;
    out.open(outPath);

    if(out.is_open())
    {
        for(TypeSaver ts : allData)
        {
            out << ts.getTypeName() << endl;
            for(ArraySaver as : ts.getData())
            {
                //---------LIBRARY SORT TIME-----------//
                long sizeArr = as.getSize();
                out << sizeArr << endl;
                ArraySaver as_copy = as;
                double averageTime = 0;
                for(vector<int> v : as_copy.getArrays())
                {
                    const int n = sizeArr;
                    int *arr = new int[n];
                    copy(v.begin(), v.end(), arr);

                    unsigned long long start_time =  clock();
                   // librarySort(arr, n);
                    unsigned long long end_time =  clock();

                    averageTime += (end_time - start_time)/double(COUNT_COPY);

                    delete arr;
                }
                out<<"Library_sort-"<<averageTime<<endl;

                //---------COUNTING SORT TIME-----------//
                as_copy = as;
                averageTime = 0;
                for(vector<int> v : as_copy.getArrays())
                {
                    vector<int> v_copy = v;

                    unsigned long long start_time =  clock();
                    countingSort(v_copy, v_copy.size());
                    unsigned long long end_time =  clock();

                    averageTime += (end_time - start_time)/double(COUNT_COPY);

                }
                out<<"Counting_sort-"<<averageTime<<endl;

                //---------SMOOTH SORT TIME-----------//
                as_copy = as;
                averageTime = 0;
                for(vector<int> v : as_copy.getArrays())
                {
                    const int n = sizeArr;
                    int *arr = new int[n];
                    copy(v.begin(), v.end(), arr);

                    unsigned long long start_time =  clock();
                   // smoothsort(arr, n);
                    unsigned long long end_time =  clock();

                    averageTime += (end_time - start_time)/double(COUNT_COPY);

                    delete arr;
                }
                out<<"Smooth_sort-"<<averageTime<<endl;

                //---------INTRO SORT TIME-----------//
                as_copy = as;
                averageTime = 0;
                for(vector<int> v : as_copy.getArrays())
                {
                    const int n = sizeArr;
                    int *arr = new int[n];
                    copy(v.begin(), v.end(), arr);

                    unsigned long long start_time =  clock();
                    //introsort(arr, arr, arr+n-1);
                    unsigned long long end_time =  clock();

                    averageTime += (end_time - start_time)/double(COUNT_COPY);

                    delete arr;
                }
                out<<"Inrto_sort-"<<averageTime<<endl;

                //---------STL::SORT TIME-----------//
                as_copy = as;
                averageTime = 0;
                for(vector<int> v : as_copy.getArrays())
                {
                    const int n = sizeArr;
                    int *arr = new int[n];
                    copy(v.begin(), v.end(), arr);

                    unsigned long long start_time =  clock();
                    //sort(arr, arr + n);
                    unsigned long long end_time =  clock();

                    averageTime += (end_time - start_time)/double(COUNT_COPY);

                    delete arr;
                }
                out<<"stl::sort-"<<averageTime<<endl;

                //---------STL::STABLE_SORT TIME-----------//
                as_copy = as;
                averageTime = 0;
                for(vector<int> v : as_copy.getArrays())
                {
                    const int n = sizeArr;
                    int *arr = new int[n];
                    copy(v.begin(), v.end(), arr);

                    unsigned long long start_time =  clock();
                   // stable_sort(arr, arr + n);
                    unsigned long long end_time =  clock();

                    averageTime += (end_time - start_time)/double(COUNT_COPY);

                    delete arr;
                }
                out<<"stl::stable_sort-"<<averageTime<<endl;
            }
        }
    }
}
