#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <iomanip>

#define PI 3.1415926535897

using namespace std;

void printEllipse(unsigned int points, double a, double b)
{
  cout << endl <<"x" << "\t" << "y" << endl;
  cout << "----" << "\t" << "----" << endl;
  double slice = 2 * PI / points;
  
  for(int i = 0; i <= points; ++i)
  {
    double angle = slice * i;
    double x = (a * cos(angle));
    double y = (b * sin(angle));
    
    cout << round(x * 1000.0) / 1000.0 << "\t" << round(y * 1000.0) / 1000.0 << endl;
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

