#ifndef _DYNAMICMODEL_
#define _DYNAMICMODEL_

#include "KinematicModel.h"

class DynamicModel : public KinematicModel
{
    public:
        DynamicModel(std::vector<double> modelParams);
        void calcStateDot(double velRobot, double velNormalRobot, double omegaRobot, double u1, double u2, double u3);
        std::vector<double> getStateVecDot();
        

    private:
        double sign_func(double x);
        double accV;
        double accVn;
        double accAng;
};

#include "DynamicModel.cpp"

#endif