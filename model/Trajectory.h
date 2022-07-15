#ifndef _TRAJ_
#define _TRAJ_

#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <map>

class Trajectory
{
    public:
        Trajectory() = default;
        std::string readFileIntoString(const std::string& path);
        void getFileContent();
        void setTraj();
        std::vector<double> getX();
        std::vector<double> getY();
        std::vector<double> getOmega();

    private:
        std::map<int, std::vector<std::string>> csv_contents;
        std::vector<double> velX;
        std::vector<double> velY;
        std::vector<double> omega;

};

#include "Trajectory.cpp"

#endif // _TRAJ_