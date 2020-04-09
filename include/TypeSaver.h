#ifndef TYPESAVER_H
#define TYPESAVER_H
#include<string>
#include<vector>
#include"ArraySaver.h"

class TypeSaver
{
private:
    std::string type_name;
    std::vector<ArraySaver> data;
public:
    TypeSaver(std::string type_name, std::vector<ArraySaver> data);
    virtual ~TypeSaver();
    std::string getTypeName();
    std::vector<ArraySaver> getData();

    void outData();
};

#endif // TYPESAVER_H
