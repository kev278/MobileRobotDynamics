#include "KinematicModel.h"
#include "Trajectory.h"
#include "Data.h"
#include <iostream>
#include "DynamicModel.h"

int main()
{

    // Task 1: Load data from CSV
    Data data;
    data.getFileContent();
    data.setModelParameters();
    std::cout << "Check 1" << std::endl;
    std::vector<double> modelParams = data.getParams();

    // Task 3: Initialize Kinematic Model
    KinematicModel kinematicModel(modelParams);
    std::cout << "Check 2" << std::endl;

    // Task 3: Calcuate Velocities
    kinematicModel.calcVel(1, 1, 1);
    std::cout << "Check 3" << std::endl;

    // Task 4: Initialize Dynamic Model
    DynamicModel dynamicModel(modelParams);
    std::cout << "Check 4" << std::endl;

    // Task 5: Input Velocity Trajectory to get Acceleration Trajectory
    Trajectory trajectory;
    trajectory.getFileContent();
    trajectory.setTraj();
    std::vector<double> velX = trajectory.getX();
    std::vector<double> velY = trajectory.getY();
    std::vector<double> omega = trajectory.getOmega();
    std::cout << "Check 5" << std::endl;

}