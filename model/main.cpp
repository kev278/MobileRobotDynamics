#include "KinematicModel.h"
#include "Data.h"
#include <iostream>

int main()
{

    // Task 1: Load data from CSV
    Data data;
    data.getFileContent();
    data.setModelParameters();
    std::cout << "Check 1" << std::endl;

    // Task 2: Initialize a Robot
    std::vector<double> modelParams = data.getParams();
    Robot robot(modelParams);
    std::cout << "Check 2" << std::endl;

    // Task 3: Initialize Kinematic Model
    KinematicModel kinematicModel;
    std::cout << "Check 3" << std::endl;

}