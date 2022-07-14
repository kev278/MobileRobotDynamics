#include <KinematicModel.h>
#include <Eigen/Dense>
#include <cmath>

using KM = KinematicModel;

// Solve this error
void KM::calcLinearVel(Robot<T>::Robot::wheelToCenter, T velRobot, T velNormalRobot, T omegaRobot)
{
    Eigen::MatrixXd Rotation(3, 3);
    Rotation << -sqrt(3) / 2, 1 / 2, wheelToCenter,
                 0,          -1,     wheelToCenter,
                 sqrt(3) / 2, 1 / 2, wheelToCenter;

    Eigen::MatriXd stateVec(3, 1);
    stateVec << velRobot, velNormalRobot, omegaRobot;
    Eigen::wheelLinearVel(3, 1);
    wheelLinearVel = Rotation * stateVec;
    KinematicModel::linVel0 = wheelLinearVel(1, 1);
    KinematicModel::linVel1 = wheelLinearVel(2, 1);
    KinematicModel::linVel2 = wheelLinearVel(3, 1);
}

void KinematicModel::calAngularVel()
{
    KinematicModel::angVel0 = KinematicModel::linVel0 / Robot::wheelRadius;
    KinematicModel::angVel1 = KinematicModel::linVel1 / Robot::wheelRadius;
    KinematicModel::angVel2 = KinematicModel::linVel2 / Robot::wheelRadius;
}