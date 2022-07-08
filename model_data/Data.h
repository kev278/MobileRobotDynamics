/*
Get Data from csv file and set Model Parameters
*/

#ifndef _DATA_
#define _DATA_

#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <map>

template<class T>
class Data
{
    public:
        Data() = default;
        std::string readFileIntoString(const std::string& path);
        void getFileContent();
        void setModelParameters();

    private:
        std::map<int, std::vector<std::string>> csv_contents;
        std::vector<T> modelParameters;  
};

#include "Data.cpp"

#endif //_DATA_