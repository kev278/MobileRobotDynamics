#include <KinematicModel.h>
#include <Eigen/Dense>
#include <cmath>

template<class T>
using KM = KinematicModel;

// Solve this error
template<class T>
void KM<T>::KM::calcLinearVel(Robot<T>::Robot::wheelToCenter, T velRobot, T velNormalRobot, T omegaRobot)
{
    Eigen::MatrixXd Rotation(3, 3);
    Rotation << -sqrt(3) / 2, 1 / 2, wheelToCenter,
                 0,          -1,     wheelToCenter,
                 sqrt(3) / 2, 1 / 2, wheelToCenter;

    Eigen::MatriXd stateVec(3, 1);
    stateVec << velRobot, velNormalRobot, omegaRobot;
    Eigen::wheelLinearVel(3, 1);
    wheelLinearVel = Rotation * stateVec;
    KinematicModel<T>::KinematicModel::linVel0 = wheelLinearVel(1, 1);
    KinematicModel<T>::KinematicModel::linVel1 = wheelLinearVel(2, 1);
    KinematicModel<T>::KinematicModel::linVel2 = wheelLinearVel(3, 1);
}

void KinematicModel<T>::KinematicModel::calAngularVel()
{
    KinematicModel<T>::KinematicModel::angVel0 = KinematicModel<T>::KinematicModel::linVel0 / Robot<T>::Robot::wheelRadius;
    KinematicModel<T>::KinematicModel::angVel1 = KinematicModel<T>::KinematicModel::linVel1 / Robot<T>::Robot::wheelRadius;
    KinematicModel<T>::KinematicModel::angVel2 = KinematicModel<T>::KinematicModel::linVel2 / Robot<T>::Robot::wheelRadius;
}