#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <iomanip>
#include <Eigen/Cholesky>
#include "autodiff.h"

#define PI 3.1415926535897

DECLARE_DIFFSCALAR_BASE();
typedef Eigen::VectorXd Gradient;
typedef DScalar1<double, Gradient> DScalar;

using namespace std;
int main(int argc, char** argv) {
  double len = 10;
  double fr = 1;
  
  Eigen::VectorXd a_fr(1);
  DiffScalarBase::setVariableCount(1);
  
  for(int i = 1; i < 10; ++i) {
    DScalar s_fr((double)i, a_fr);
    DScalar dia = (len/s_fr);
    std::cout << dia << std::endl;
  }

  return 0;
}
