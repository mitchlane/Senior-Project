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
void printEllipse(unsigned int points, double a0, double b0)
{
  cout << endl <<"x" << "\t" << "y" << "\t" << "dx/da" << "\t" << "dy/db" << endl;
  cout << "----" << "\t" << "----" << "\t" << "----" << "\t" << "----" << endl;
  double slice = 2 * PI / points;
  DiffScalarBase::setVariableCount(2);
  Eigen::Vector2d ab(a0, b0);
  
  DScalar as(0, ab[0]);
  DScalar bs(0, ab[1]);
  
  for(int i = 0; i <= points; ++i)
  {
    double angle = slice * i;
    DScalar x = (as * cos(angle));
    DScalar y = (bs * sin(angle));
    
    std::cout << x << std::endl;
    
/*
    cout << round(x.getValue() * 1000.0) / 1000.0
         << "\t" << round(y.getValue() * 1000.0) / 1000.0
         << "\t" << x.getGradient() 
         << "\t" << y.getGradient() << endl;
*/
  }
}

int main(int argc, char** argv)
{
  unsigned int resolution;
  double xRad;
  double yRad;
  
  cout << "Enter the resolution of the ellipse." << endl;
  cin >> resolution;
  cout << "Enter the x radius." << endl;
  cin >> xRad;
  cout << "Enter the y radius." << endl;
  cin >> yRad;
  
  printEllipse(resolution, xRad, yRad);

  return 0;
}

