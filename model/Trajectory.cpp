/*
Implementation of Data Class
*/

#ifndef _TRAJCPP_
#define _TRAJCPP_

#include "Trajectory.h"

/*
Stnadard implementation of functions to get data from a CSV file
*/

std::string Trajectory::readFileIntoString(const std::string& path) 
    {
        auto ss = std::ostringstream{};
        std::ifstream input_file(path);
        ss << input_file.rdbuf();
        return ss.str();
    }

       
void Trajectory::getFileContent()
{
    std::string filename("velocityTraj.csv");
    std::string file_contents = readFileIntoString(filename);
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

// Converts csv Trajectory to a double and sets modelParameter member of the class
void Trajectory::setTraj()
{
    velX.clear();
    velY.clear();
    omega.clear();

    //velX.push_back(std::stod(csv_contents[0][1], nullptr));
    int sizeOfData = csv_contents[0].size();
    for(int i = 1; i < sizeOfData; i++)
    {
        velX.push_back(std::stod(csv_contents[0][i], nullptr));
        velY.push_back(std::stod(csv_contents[1][i], nullptr)); 
        omega.push_back(std::stod(csv_contents[2][i], nullptr));
    }
}

// Getter for model parameters
std::vector<double> Trajectory::getX()
{
    return velX;
}

std::vector<double> Trajectory::getY()
{
    return velY;
}

std::vector<double> Trajectory::getOmega()
{
    return omega;
}

#endif //_TRAJCPP_