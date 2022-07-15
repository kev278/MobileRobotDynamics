#ifndef _KMCPP_
#define _KMCPP_

#include "KinematicModel.h"
#include "Eigen/Dense"
#include <cmath>
#include <iostream>

using KM = KinematicModel;

KM::KinematicModel(std::vector<double> modelParams)
: Robot(modelParams), linVel0(0), linVel1(0), linVel2(0), angVel0(0), angVel1(0), angVel2(0)
{
    
}

//void KM::calcLinearVel(double wheelToCenter, double velRobot, double velNormalRobot, double omegaRobot)
void KM::calcLinearVel(double velRobot, double velNormalRobot, double omegaRobot)
{
    Eigen::MatrixXd Rotation(3, 3);
    Rotation << -sqrt(3) / 2, 1 / 2, Robot::wheelToCenter,
                 0,          -1,     Robot::wheelToCenter,
                 sqrt(3) / 2, 1 / 2, Robot::wheelToCenter;

    Eigen::MatrixXd stateVec(3, 1);
    stateVec << velRobot, velNormalRobot, omegaRobot;
    Eigen::MatrixXd wheelLinearVel(3, 1);
    wheelLinearVel = Rotation * stateVec;
    KM::linVel0 = wheelLinearVel(0, 0);
    KM::linVel1 = wheelLinearVel(1, 0);
    KM::linVel2 = wheelLinearVel(2, 0);
}

void KM::calcAngularVel()
{
    KM::angVel0 = KM::linVel0 / Robot::wheelRadius;
    KM::angVel1 = KM::linVel1 / Robot::wheelRadius;
    KM::angVel2 = KM::linVel2 / Robot::wheelRadius;
}

void KM::calcVel(double velRobot, double velNormalRobot, double omegaRobot)
{
    calcLinearVel(velRobot, velNormalRobot, omegaRobot);
    calcAngularVel();
}

#endif // _KMCPP_