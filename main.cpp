#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <iomanip>
#include <Eigen/Cholesky>
#include "autodiff.h"

#define PI 3.1415926535897
#define c 0.5522847498

DECLARE_DIFFSCALAR_BASE();
typedef Eigen::Vector2d Gradient;
typedef DScalar1<double, Gradient> DScalar;

typedef struct{
  double x;
  double y;
}Point;

using namespace std;

void printBezierEllipsePartial(double r, double a, double b, int quad)
{

  Point p0;
  Point p1;
  Point p2;
  Point p3;

  int i;
  double t;
  double omt;
  
  // Note: setting the varaible has to happen first.
  DiffScalarBase::setVariableCount(2);
  Eigen::Vector2d ab(a, b);
  DScalar as(0, ab[0]);
  DScalar bs(0, ab[1]);
  DScalar bx, by;
  
  switch(quad)
  {
    case 1:
      p0 = {0.0, 1.0};
      p1 = {c, 1.0};
      p2 = {1.0, c};
      p3 = {1.0, 0.0};
      break;
    case 2:
      p0 = {-1.0, 0.0};
      p1 = {-1.0, c};
      p2 = {-c, 1.0};
      p3 = {0.0, 1.0};
      break;
    case 3:
      p0 = {0.0, -1.0};
      p1 = {-c, -1.0};
      p2 = {-1.0, -c};
      p3 = {-1.0, 0.0};
      break;
    case 4:
      p0 = {1.0, 0.0};
      p1 = {1.0, -c};
      p2 = {c, -1.0};
      p3 = {0.0, -1.0};
      break;
  }
  
  printf("QUAD %d\n--------\n", quad);
  for(i = 0; i <= r; ++i)
  {
    t = i / r;
    omt = 1-t;
    bx = as*(omt*omt*omt*p0.x + 3*omt*omt*t*p1.x + 3*omt*t*t*p2.x + t*t*t*p3.x);
    by = bs*(omt*omt*omt*p0.y + 3*omt*omt*t*p1.y + 3*omt*t*t*p2.y + t*t*t*p3.y);
    
    std::cout << bx << std::endl;
    std::cout << by << std::endl << std::endl;
  }
  printf("\n\n");
}

int main(int argc, char** argv)
{
  double r, a, b;
  
  cout << "Enter Resolution" << endl;
  cin >> r;
  cout << "Enter 'A' value" << endl;
  cin >> a;
  cout << "Enter 'B' value" << endl;
  cin >> b;

  printBezierEllipsePartial(r, a, b, 1);
  printBezierEllipsePartial(r, a, b, 2);
  printBezierEllipsePartial(r, a, b, 3);
  printBezierEllipsePartial(r, a, b, 4);
  
  
  return 0;
}

/*
Enter Resolution
10
Enter 'A' value
6
Enter 'B' value
8
QUAD 1
--------
[0, grad=[0;  0]]
[8, grad=[1;  0]]

[0.973231, grad=[0.1622;  0]]
[7.89529, grad=[0.9869;  0]]

[1.89646, grad=[0.3161;  0]]
[7.59215, grad=[0.949;  0]]

[2.75735, grad=[0.4596;  0]]
[7.10705, grad=[0.8884;  0]]

[3.54352, grad=[0.5906;  0]]
[6.45646, grad=[0.8071;  0]]

[4.24264, grad=[0.7071;  0]]
[5.65685, grad=[0.7071;  0]]

[4.84235, grad=[0.8071;  0]]
[4.7247, grad=[0.5906;  0]]

[5.33029, grad=[0.8884;  0]]
[3.67646, grad=[0.4596;  0]]

[5.69412, grad=[0.949;  0]]
[2.52862, grad=[0.3161;  0]]

[5.92147, grad=[0.9869;  0]]
[1.29764, grad=[0.1622;  0]]

[6, grad=[1;  0]]
[0, grad=[0;  0]]



QUAD 2
--------
[-6, grad=[-1;  -0]]
[0, grad=[0;  0]]

[-5.92147, grad=[-0.9869;  -0]]
[1.29764, grad=[0.1622;  0]]

[-5.69412, grad=[-0.949;  -0]]
[2.52862, grad=[0.3161;  0]]

[-5.33029, grad=[-0.8884;  -0]]
[3.67646, grad=[0.4596;  0]]

[-4.84235, grad=[-0.8071;  -0]]
[4.7247, grad=[0.5906;  0]]

[-4.24264, grad=[-0.7071;  -0]]
[5.65685, grad=[0.7071;  0]]

[-3.54352, grad=[-0.5906;  -0]]
[6.45646, grad=[0.8071;  0]]

[-2.75735, grad=[-0.4596;  -0]]
[7.10705, grad=[0.8884;  0]]

[-1.89646, grad=[-0.3161;  -0]]
[7.59215, grad=[0.949;  0]]

[-0.973231, grad=[-0.1622;  -0]]
[7.89529, grad=[0.9869;  0]]

[0, grad=[0;  0]]
[8, grad=[1;  0]]



QUAD 3
--------
[0, grad=[0;  0]]
[-8, grad=[-1;  -0]]

[-0.973231, grad=[-0.1622;  -0]]
[-7.89529, grad=[-0.9869;  -0]]

[-1.89646, grad=[-0.3161;  -0]]
[-7.59215, grad=[-0.949;  -0]]

[-2.75735, grad=[-0.4596;  -0]]
[-7.10705, grad=[-0.8884;  -0]]

[-3.54352, grad=[-0.5906;  -0]]
[-6.45646, grad=[-0.8071;  -0]]

[-4.24264, grad=[-0.7071;  -0]]
[-5.65685, grad=[-0.7071;  -0]]

[-4.84235, grad=[-0.8071;  -0]]
[-4.7247, grad=[-0.5906;  -0]]

[-5.33029, grad=[-0.8884;  -0]]
[-3.67646, grad=[-0.4596;  -0]]

[-5.69412, grad=[-0.949;  -0]]
[-2.52862, grad=[-0.3161;  -0]]

[-5.92147, grad=[-0.9869;  -0]]
[-1.29764, grad=[-0.1622;  -0]]

[-6, grad=[-1;  -0]]
[0, grad=[0;  0]]



QUAD 4
--------
[6, grad=[1;  0]]
[0, grad=[0;  0]]

[5.92147, grad=[0.9869;  0]]
[-1.29764, grad=[-0.1622;  -0]]

[5.69412, grad=[0.949;  0]]
[-2.52862, grad=[-0.3161;  -0]]

[5.33029, grad=[0.8884;  0]]
[-3.67646, grad=[-0.4596;  -0]]

[4.84235, grad=[0.8071;  0]]
[-4.7247, grad=[-0.5906;  -0]]

[4.24264, grad=[0.7071;  0]]
[-5.65685, grad=[-0.7071;  -0]]

[3.54352, grad=[0.5906;  0]]
[-6.45646, grad=[-0.8071;  -0]]

[2.75735, grad=[0.4596;  0]]
[-7.10705, grad=[-0.8884;  -0]]

[1.89646, grad=[0.3161;  0]]
[-7.59215, grad=[-0.949;  -0]]

[0.973231, grad=[0.1622;  0]]
[-7.89529, grad=[-0.9869;  -0]]

[0, grad=[0;  0]]
[-8, grad=[-1;  -0]]
*/
