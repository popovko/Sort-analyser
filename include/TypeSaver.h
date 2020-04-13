#ifndef TYPESAVER_H
#define TYPESAVER_H
#include<string>
#include<vector>
#include"ArraySaver.h"

using namespace std;

class TypeSaver
{
private:
    string type_name;
    vector<ArraySaver> data;
public:

    TypeSaver(string type_name, vector<ArraySaver> data);
    virtual ~TypeSaver();

    string getTypeName();
    vector<ArraySaver> getData();
    void outData();
};

#endif // TYPESAVER_H
