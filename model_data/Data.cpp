/*
Implementation of Data Class
*/

#ifndef _DATACPP_
#define _DATACPP_

#include "Data.h"

/*
Stnadard implementation of functions to get data from a CSV file
*/
template<class T>
std::string Data<T>::Data::readFileIntoString(const std::string& path) 
    {
        auto ss = std::ostringstream{};
        std::ifstream input_file(path);
        ss << input_file.rdbuf();
        return ss.str();
    }

template<class T>        
void Data<T>::Data::getFileContent()
{
    std::string filename("parameters.csv");
    std::string file_contents = readFileIntoString(filename);;
    char delimiter{','};

    std::istringstream sstream(file_contents);
    std::vector<std::string> items;
    std::string record;

    int counter{0};
    while(std::getline(sstream, record)) 
        {
            std::istringstream line(record);
            while(std::getline(line, record, delimiter)) 
            {
                items.push_back(record);
            }
            csv_contents[counter] = items;
            items.clear();
            counter += 1;
        }
}

// Converts csv data to a double and sets modelParameter member of the class
template<class T>
void Data<T>::Data::setModelParameters()
{
    modelParameters.clear();
    modelParameters.push_back(std::stod(csv_contents[0][1], nullptr));
    int sizeOfData = csv_contents.size();
    for(int i = 0; i < sizeOfData; i++)
    {
        modelParameters.push_back(std::stod(csv_contents[i][1], nullptr));
    }
}

// Getter for model parameters
template<class T>
std::vector<T> Data<T>::Data::getParams()
{
    return modelParameters;
}

#endif //_DATACPP_