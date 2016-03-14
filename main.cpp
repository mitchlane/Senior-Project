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
    std::cout << y << std::endl << std::endl;
    
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

/*
Enter the resolution of the ellipse.
10
Enter the x radius.
6
Enter the y radius.
8

x	y	dx/da	dy/db
----	----	----	----
[6, grad=[1;  0]]
[0, grad=[0;  0]]

[4.8541, grad=[0.809;  0]]
[4.70228, grad=[0.5878;  0]]

[1.8541, grad=[0.309;  0]]
[7.60845, grad=[0.9511;  0]]

[-1.8541, grad=[-0.309;  -0]]
[7.60845, grad=[0.9511;  0]]

[-4.8541, grad=[-0.809;  -0]]
[4.70228, grad=[0.5878;  0]]

[-6, grad=[-1;  -0]]
[7.4705e-13, grad=[9.338e-14;  0]]

[-4.8541, grad=[-0.809;  -0]]
[-4.70228, grad=[-0.5878;  -0]]

[-1.8541, grad=[-0.309;  -0]]
[-7.60845, grad=[-0.9511;  -0]]

[1.8541, grad=[0.309;  0]]
[-7.60845, grad=[-0.9511;  -0]]

[4.8541, grad=[0.809;  0]]
[-4.70228, grad=[-0.5878;  -0]]

[6, grad=[1;  0]]
[-1.4941e-12, grad=[-1.868e-13;  -0]]
*/
