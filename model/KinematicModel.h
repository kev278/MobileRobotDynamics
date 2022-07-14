#ifndef _KINEMATICMODEL_
#define _KINEMATICMODEL_

#include "Robot.h"

class KinematicModel : public Robot
{
    public:
        void calcLinearVel(double wheelToCenter, double velRobot, double velNormalRobot, double omegaRobot);
        void calAngularVel(double wheelRadius);
        
    private:
        double linVel0;
        double linVel1;
        double linVel2;
        double angVel0;
        double angVel1;
        double angVel2;
};

#endif