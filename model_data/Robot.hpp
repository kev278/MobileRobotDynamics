#ifndef _ROBOT_
#define _ROBOT_

template <class T>
class Robot
{
    public:
        // Parametric Constructor to initialize robot parameters
        Robot(T modelParameters);

    private:
        T wheelToCenter;
        T wheelRadius;
        T gearBoxReduction;
        /*
        Dynamic Model and Motor Parameters
        Check the report for description of each parameter
        */
        T Kv;
        T R;
        T M;
        T J;
        T Bv;
        T Bvn;
        T Bw;
        T Cv;
        T Cvn;
        T Cw;
};

#endif
