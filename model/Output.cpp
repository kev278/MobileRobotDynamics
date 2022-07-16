#ifndef _OPCPP_
#define _OPCPP_

#include "Output.h"
#include <fstream>

Output::Output(std::vector<std::vector<double>> stateVecDot)
: stateVecDot_(stateVecDot)
{
    writeToFile();
}

void Output::writeToFile()
{
    // Create an output filestream object
    std::ofstream myFile("output.csv");
    
    // Send data to the stream
    for(int i = 0; i < stateVecDot_[0].size(); ++i)
    {
        for(int j = 0; j < stateVecDot_.size(); ++j)
        {
            myFile << stateVecDot_[j][i];
            if(j != stateVecDot_.size() - 1) myFile << ","; // No comma at end of line
        }
        myFile << "\n";
    }

}

#endif // _OPCPP_