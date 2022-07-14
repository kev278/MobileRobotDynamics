#include <KinematicModel.h>
#include <Eigen/Dense>
#include <cmath>

using KM = KinematicModel;

// Solve this error
void KM::calcLinearVel(double wheelToCenter, double velRobot, double velNormalRobot, double omegaRobot)
{
    Eigen::MatrixXd Rotation(3, 3);
    Rotation << -sqrt(3) / 2, 1 / 2, wheelToCenter,
                 0,          -1,     wheelToCenter,
                 sqrt(3) / 2, 1 / 2, wheelToCenter;

    Eigen::MatrixXd stateVec(3, 1);
    stateVec << velRobot, velNormalRobot, omegaRobot;
    Eigen::MatrixXd wheelLinearVel(3, 1);
    wheelLinearVel = Rotation * stateVec;
    KM::linVel0 = wheelLinearVel(1, 1);
    KM::linVel1 = wheelLinearVel(2, 1);
    KM::linVel2 = wheelLinearVel(3, 1);
}

void KM::calAngularVel(double wheelRadius)
{
    KM::angVel0 = KM::linVel0 / wheelRadius;
    KM::angVel1 = KM::linVel1 / wheelRadius;
    KM::angVel2 = KM::linVel2 / wheelRadius;
}