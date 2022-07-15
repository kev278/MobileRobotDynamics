#ifndef _DMCPP_
#define _DMCPP_

#include "DynamicModel.h"
#include <cmath>
#include <functional>

double x1{0}, x2{0}, x3{0};

DynamicModel::DynamicModel(std::vector<double> modelParams)
: KinematicModel(modelParams), accV(0), accVn(0), accAng(0)
{

}

Eigen::MatrixXd DynamicModel::calcStateDot(double velRobot, double velNormalRobot, double omegaRobot, double u1, double u2, double u3)
{
    /* TODO
    Add Kt to model parameters

    */
    double Kt{0.5};

    double A11 = - (3 * pow(Kt, 2) * pow(gearBoxReduction, 2)) / (2 *  pow(wheelRadius, 2) * R * M) - Bv / M;
    double A22 = - (3 * pow(Kt, 2) * pow(gearBoxReduction, 2)) / (2 *  pow(wheelRadius, 2) * R * M) - Bvn / M; 
    double A33 = - (3 *  pow(wheelToCenter, 2) * pow(Kt, 2) * pow(gearBoxReduction, 2)) / (pow(wheelRadius, 2) * R * J) - Bw / J; 

    Eigen::MatrixXd A;
    A << A11, 0,   0,
         0,   A22, 0,
         0,   0,   A33;

    Eigen::MatrixXd stateVec;
    stateVec << velRobot, velNormalRobot, omegaRobot;

    Eigen::MatrixXd B;
    B << -sqrt(3) / (2 * M), 0,                 sqrt(3) / (2 * M),
          1 / (2 * M), 1 /   M,                 1 / (2 * M),
          wheelToCenter / J, wheelToCenter / J, wheelToCenter / J;

    double lambda = (gearBoxReduction * Kt) / (wheelRadius * R);
    B *= lambda;

    Eigen::MatrixXd U;
    U << u1, u2, u3;

    Eigen::MatrixXd K;
    K << -Cv / M, 0,       0,
          0,     -Cvn / M, 0,
          0,      0,      -Cw / J;

    Eigen::MatrixXd signX;
    x1 = sign_func(velRobot);
    x2 = sign_func(velNormalRobot);
    x3 = sign_func(omegaRobot);
    signX << x1, x2, x3;


    Eigen::MatrixXd stateVecDot;
    stateVecDot = A * stateVec + B * U + K * signX;
    return stateVecDot;
}

double DynamicModel::sign_func(double x)
{
    if (x > 0)
        return 1;
    else if (x == 0)
        return 0;
    else
        return -1;
}

#endif // _DMCPP_