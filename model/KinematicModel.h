#ifndef _KINEMATICMODEL_
#define _KINEMATICMODEL_

#include "Robot.h"

class KinematicModel : public Robot
{
    public:
        KinematicModel(std::vector<double> modelParams);
        void calcVel(double velRobot, double velNormalRobot, double omegaRobot);
        void calcLinearVel(double velRobot, double velNormalRobot, double omegaRobot);
        void calcAngularVel();
        
    private:

        double linVel0;
        double linVel1;
        double linVel2;
        double angVel0;
        double angVel1;
        double angVel2;
};

#include "KinematicModel.cpp"

#endif