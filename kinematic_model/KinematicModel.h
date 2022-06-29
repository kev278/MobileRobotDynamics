#ifndef _KINEMATICMODEL_
#define _KINEMATICMODEL_

#include <Robot.h>

template<class T>
class KinematicModel : public Robot
{
    public:
        void calcLinearVel(Robot<T>::Robot::wheelToCenter, T velRobot, T velNormalRobot, T omegaRobot);
        void calAngularVel();
        
    private:
        T linVel0;
        T linVel1;
        T linVel2;
        T angVel0;
        T angVel1;
        T angVel2;
};

#endif