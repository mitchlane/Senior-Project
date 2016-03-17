#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <iomanip>
#include <Eigen/Cholesky>
#include "autodiff.h"

DECLARE_DIFFSCALAR_BASE();
typedef Eigen::VectorXd Gradient;
typedef DScalar1<double, Gradient> DScalar;

using namespace std;
int main(int argc, char** argv)
{
  Eigen::VectorXd vars(10);
  DiffScalarBase::setVariableCount(10);
  
  for(int i = 0; i <= 1; ++i)
  {
    vars[i] = i;
  }
  
//  DScalar a(0, vars[0]);
//  DScalar b(1, vars[1]);
//  DScalar c(2, vars[2]);
//  DScalar c(0, vars[2]);
  
  DScalar a(0, vars[0]),b(1, vars[1]),c(2, vars[2]),d(3, vars[3]),e(4, vars[4]),f(5, vars[5]),g(6, vars[6]),h(7, vars[7]),i(8, vars[8]),j(9, vars[9]);
  
  //DScalar test = x[0] + x[1] + x[2] + x[3] + x[4] + x[5]
  //               + x[6] + x[7] + x[8] + x[9];
  DScalar test = a + b + c + d + e + f + g + h + i + j - 2;
  std::cout << test << std::endl;
  
  return 0;
}
