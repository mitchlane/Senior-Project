#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <iomanip>
#include "had.h"

#define PI 3.1415926535897

using namespace had;
using namespace std;
DECLARE_ADGRAPH();

void printEllipse(unsigned int points, double a, double b)
{
  ADGraph adGraph;
  
  cout << endl <<"x" << "\t" << "y" << "\t" << "dx/dslice" << "\t" << "dy/dslice" << endl;
  cout << "----" << "\t" << "----" << "\t" << "----" << "\t" << "----" << endl;
  AReal slice = AReal(2 * PI / points);
  
  for(int i = 0; i <= points; ++i)
  {
    AReal angle = AReal(slice * AReal(i));
    AReal x = AReal(AReal(a) * AReal(cos(angle)));
    SetAdjoint(x, 1.0);
    PropagateAdjoint();
    
    Real dxdslice = GetAdjoint(x);
    
    AReal y = AReal(b * sin(angle));
    SetAdjoint(y, 1.0);
    PropagateAdjoint();
    Real dydslice = GetAdjoint(y);
    
    cout << round(x.val * 1000.0) / 1000.0 << "\t" << round(y.val * 1000.0) / 1000.0 << "\t" << dxdslice << "\t" << dydslice << endl;
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

