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
  
  for(int i = 0; i <= 9; ++i)
  {
    vars[i] = i;
  }
  
  DScalar a(0, vars[0]),b(1, vars[1]),c(2, vars[2]),d(3, vars[3]),
    e(4, vars[4]),f(5, vars[5]),g(6, vars[6]),h(7, vars[7]),i(8, vars[8]),
    j(9, vars[9]);
  
              // 0 + 2*1 + 3*2 + 4*3 + 5*4 + 6*5 + 7*6 + 8*7 + 9*8 + 0*9
  DScalar test = a + 2*b + 3*c + 4*d + 5*e + 6*f + 7*g + 8*h + 9*i + 0*j;
  std::cout << test << std::endl;
  
  return 0;
}


/*
 * [240, grad=[1;  2;  3;  4;  5;  6;  7;  8;  9;  0]]
*/
