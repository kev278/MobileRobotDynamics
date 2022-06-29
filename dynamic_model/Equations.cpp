#include "Eigen/Dense"

Eigen::MatrixXd K;
K << -Cv / M, 0, 0,
      0, -Cvn / M, 0,
      0, 0, -Cw / J;

Eigen::MatrixXd B;
B << -sqrt(3) / (2 * M), 0, sqrt(3) / (2 * M),
      1 / (2 * M), 1 / M, 1 / (2 * M),
      wheelToCenter / J, wheelToCenter / J, wheelToCenter / J;

lambda = (gearBoxReduction * Kt) / (wheelRadius * R);
B *= lambda;

A11 = - (3 * power(Kt, 2) * power(gearBoxReduction, 2)) / (2 *  power(wheelRadius, 2) * R * M) - Bv / M;
A22 = - (3 * power(Kt, 2) * power(gearBoxReduction, 2)) / (2 *  power(wheelRadius, 2) * R * M) - Bvn / M; 
A33 = - (3 *  power(wheelToCenter, 2) * power(Kt, 2) * power(gearBoxReduction, 2)) / (power(wheelRadius, 2) * R * J) - Bw / J; 

Eigen::MatrixXd A;
A << A11, 0, 0,
     0, A22, 0,
     0, 0, A33;