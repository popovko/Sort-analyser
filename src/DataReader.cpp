#include "DataReader.h"

const int COUNT_COPY = 5;
const int COUNT_SIZES = 4;
const int COUNT_TYPES = 4;

DataReader::DataReader(string file_path)
{
    this -> file_path = file_path;
    //ctor
}

DataReader::~DataReader()
{
    //dtor
}

vector<TypeSaver> DataReader::getAllData()
{
    return all_data;
}

void DataReader::readAllData()
{
    vector<TypeSaver> data;
    ifstream file;
    file.open(file_path, ios_base::in);
    for(int i = 0; i < COUNT_TYPES; i++)
    {
        data.push_back(readNextType(file));
    }
    file.close();

    this -> all_data = data;
}

TypeSaver DataReader::readNextType(ifstream & file)
{
    if(file.is_open())
    {
        string type_name;
        file >> type_name;
        vector<ArraySaver> all_arrays_of_type;
        for(int i = 0; i < COUNT_SIZES; i++)
        {
            all_arrays_of_type.push_back(readNextArrays(file));
        }

        return TypeSaver(type_name, all_arrays_of_type);
    }
}

ArraySaver DataReader::readNextArrays(ifstream & file)
{
    if(file.is_open())
    {
        vector<vector<int>> arrays;

        int size;
        file >> size;
        for(int row = 0; row < COUNT_COPY; row++)
        {
            vector<int> arr;
            for(int column = 0; column < size; column++)
            {
                int n;
                file >> n;
                arr.push_back(n);
            }
            arrays.push_back(arr);
        }

        return ArraySaver(size, arrays);
    }
}
void DataReader::outAllData()
{
    if(!all_data.empty()){
        for(TypeSaver ts : all_data)
        {
            cout<<"Type: "<<ts.getTypeName()<<endl;
            for(ArraySaver as : ts.getData())
            {
                cout<<"Size: "<<as.getSize()<<endl;
                for(vector<int> arr : as.getArrays())
                {
                    for(int n : arr)
                    {
                        cout<<n<<" ";
                    }
                    cout<<endl;
                }
            }
        }
    }
    else
    {
        cout<<"Data is empty";
    }
}

