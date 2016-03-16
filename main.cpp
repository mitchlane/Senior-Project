#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <iomanip>
#include <Eigen/Cholesky>
#include "autodiff.h"

#define PI 3.1415926535897

DECLARE_DIFFSCALAR_BASE();
typedef Eigen::Vector2d Gradient;
typedef DScalar1<double, Gradient> DScalar;

using namespace std;
int main(int argc, char** argv)
{
  DiffScalarBase::setVariableCount(10);
  Eigen::VectorXd vars(10);
  
  for(int i = 0; i <= 9; ++i)
  {
    vars[i] = i;
  }
  
  DScalar a(0, vars[0]),b(0, vars[1]),c(0, vars[2]),d(0, vars[3]),e(0, vars[4]),f(0, vars[5]),g(0, vars[6]),h(0, vars[7]),i(0, vars[8]),j(0, vars[9]);
  
//  DScalar test = x[0] + x[1] + x[2] + x[3] + x[4] + x[5]
//                 + x[6] + x[7] + x[8] + x[9];
  
  return 0;
}
