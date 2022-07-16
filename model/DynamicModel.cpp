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

void DynamicModel::calcStateDot(double velRobot, double velNormalRobot, double omegaRobot, double u1, double u2, double u3)
{
    /* TODO
    Add Kt to model parameters

    */
    double Kt{0.5};

    double A11 = - (3 * pow(Kt, 2) * pow(gearBoxReduction, 2)) / (2 *  pow(wheelRadius, 2) * R * M) - Bv / M;
    double A22 = - (3 * pow(Kt, 2) * pow(gearBoxReduction, 2)) / (2 *  pow(wheelRadius, 2) * R * M) - Bvn / M; 
    double A33 = - (3 *  pow(wheelToCenter, 2) * pow(Kt, 2) * pow(gearBoxReduction, 2)) / (pow(wheelRadius, 2) * R * J) - Bw / J; 

    Eigen::MatrixXd A(3, 3);
    A << A11, 0,   0,
         0,   A22, 0,
         0,   0,   A33;

    Eigen::MatrixXd stateVec(3, 1);
    stateVec << velRobot, velNormalRobot, omegaRobot;

    Eigen::MatrixXd B(3, 3);
    B << -sqrt(3) / (2 * M), 0,                 sqrt(3) / (2 * M),
          1 / (2 * M), 1 /   M,                 1 / (2 * M),
          wheelToCenter / J, wheelToCenter / J, wheelToCenter / J;

    double lambda = (gearBoxReduction * Kt) / (wheelRadius * R);
    B *= lambda;

    Eigen::MatrixXd U(3, 1);
    U << u1, u2, u3;

    Eigen::MatrixXd K(3, 3);
    K << -Cv / M, 0,       0,
          0,     -Cvn / M, 0,
          0,      0,      -Cw / J;

    Eigen::MatrixXd signX(3, 1);
    x1 = sign_func(velRobot);
    x2 = sign_func(velNormalRobot);
    x3 = sign_func(omegaRobot);
    signX << x1, x2, x3;


    Eigen::MatrixXd stateVecDot(3, 1);
    stateVecDot = A * stateVec + B * U + K * signX;
    accV = stateVecDot.coeff(0, 0);
    accVn = stateVecDot.coeff(1, 0);
    accAng = stateVecDot.coeff(2, 0);

}

inline std::vector<double> DynamicModel::getStateVecDot()
{
    std::vector<double> stateVecDot {accV, accVn, accAng};
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