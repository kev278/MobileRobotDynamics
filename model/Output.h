#ifndef _OUTPUT_
#define _OUTPUT_

#include <iostream>
#include <vector>

using vec2D = std::vector<std::vector<double>>;

class Output
{
    public:
        Output(vec2D stateVecDot);
        void writeToFile();
    private:
        vec2D stateVecDot_;
};

#include "Output.cpp"

#endif // _OUTPUT_