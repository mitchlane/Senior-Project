#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <iomanip>
#include <Eigen/Cholesky>
#include "autodiff.h"

#define PI 3.1415926535897
//#define c 0.55195024494
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

  int i;
  double t;
  double omt;
  Point B;
  
  printf("QUAD %d\n--------\n", quad);
  for(i = 0; i <= r; ++i)
  {
    t = i / r;
    omt = 1-t;
    B.x = omt*omt*omt*p0.x + 3*omt*omt*p1.x + 3*omt*t*t*p2.x + t*t*t*p3.x;
    B.y = omt*omt*omt*p0.y + 3*omt*omt*p1.y + 3*omt*t*t*p2.y + t*t*t*p3.y;
//    bx = 3*c*omt*omt + 3*omt*t*t + t*t*t;
//    by = 3*c*t*t*omt + 3*t*omt*omt + omt*omt*omt;
    
    //printf("t = %lf\n", t);
    printf("(%lf,%lf)\n", B.x, B.y);
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
