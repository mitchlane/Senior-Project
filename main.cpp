#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <iomanip>
#include "had.h"

#define PI 3.1415926535897

using namespace std;
using namespace had;
DECLARE_ADGRAPH();

void printEllipse(ADGraph ad, unsigned int points, AReal a, AReal b)
{
  cout << endl <<"x" << "\t" << "y" << "\t" << "dx/da" << "\t" << "dy/db" << endl;
  cout << "----" << "\t" << "----" << "\t" <<"----" << "\t" << "----" << endl;
  double slice = 2 * PI / points;
  
  for(int i = 0; i <= points; ++i)
  {
    double angle = slice * i;
    AReal x = a * cos(angle);
    AReal y = b * sin(angle);
    
    SetAdjoint(x, 1.0);
    PropagateAdjoint();
    double dxda = GetAdjoint(a);
//    ad.Clear();

    SetAdjoint(y, 1.0);
    PropagateAdjoint();
    double dyda = GetAdjoint(b);
    
    cout << round(x.val * 1000.0) / 1000.0 << "\t" << round(y.val * 1000.0) / 1000.0 << 
"\t" << dxda << "\t" << dyda<< endl;
  }
}

int main(int argc, char** argv)
{
  unsigned int resolution;
  double xRad;
  double yRad;
  ADGraph adGraph;
  
  cout << "Enter the resolution of the ellipse." << endl;
  cin >> resolution;
  cout << "Enter the x radius." << endl;
  cin >> xRad;
  cout << "Enter the y radius." << endl;
  cin >> yRad;
  
  printEllipse(adGraph, resolution, xRad, yRad);

  return 0;
}

