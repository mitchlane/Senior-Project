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

void test_func(DScalar one, DScalar two) {
  // do nothing
}

int main(int argc, char** argv)
{
  vector<double> vars(10);
  int count = 6;
  DiffScalarBase::setVariableCount(count);

  double test = 100;
  DScalar x;
  x = test;
  double test2 = x;
  DScalar y;
  DScalar z;
  DScalar yy = 1.0;
  yy = y + z;
  double t = static_cast<double>(yy);
  static_cast<double>(test2);
  DScalar ct;
  ct = (DScalar)1.0;
  
  z = y = x;
  
  cout << z << endl;
  
  z = y = 2.4;
  y = 1;
  
  y = std::abs(z);
  abs(z);
  
  cout << z << endl;
  cout << ct << endl;
  
  return 0;
}


/*
  DScalar a(0, vars[0]),b(1, vars[1]),c(2, vars[2]),d(3, vars[3]),
    e(4, vars[4]),f(5, vars[5]),g(6, vars[6]),h(7, vars[7]),i(8, vars[8]),
    j(9, vars[9]);
 * [240, grad=[1;  2;  3;  4;  5;  6;  7;  8;  9;  0]]
 * 
  DScalar a(0, vars[0]),b(0, vars[1]),c(0, vars[2]),d(0, vars[3]),
    e(0, vars[4]),f(0, vars[5]),g(0, vars[6]),h(0, vars[7]),i(0, vars[8]),
    j(0, vars[9]);
 * [240, grad=[45;  0;  0;  0;  0;  0;  0;  0;  0;  0]]

  DScalar a(0, 4.0);
  DScalar b(0, 5.0);
  DScalar test = (a*a) - b + vars[9];
  std::cout << test << std::endl;
* [20, grad=[7]]
*/
