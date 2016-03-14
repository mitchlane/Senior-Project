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
    cout << "theta is " << angle << endl;
    AReal x = a * cos(angle);
    AReal y = b * sin(angle);
    
    // Take the derivative of x with respect to a
    SetAdjoint(x, 1.0);
    PropagateAdjoint();
    double dxda = GetAdjoint(a);
//    ad.Clear();

    // Take the derivative of y with renspet to b
    SetAdjoint(y, 1.0);
    PropagateAdjoint();
    double dyda = GetAdjoint(b);
    
    // Report the results.
    cout << round(x.val * 1000.0) / 1000.0 << "\t"
         << round(y.val * 1000.0) / 1000.0 << "\t"
         << dxda << "\t" << dyda<< endl;
  }
}

int main(int argc, char** argv)
{
  unsigned int resolution;
  double xRad;
  double yRad;
  // construct the reverse-mode AD graph
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

/*
Enter the resolution of the ellipse.
10
Enter the x radius.
6
Enter the y radius.
8

x	y	dx/da	dy/db
----	----	----	----
6	0	1	0
4.854	4.702	1.80902	0.587785
1.854	7.608	2.11803	1.53884
-1.854	7.608	1.80902	2.4899
-4.854	4.702	1	3.07768
-6	0	1.43885e-13	3.07768
-4.854	-4.702	-0.809017	2.4899
-1.854	-7.608	-1.11803	1.53884
1.854	-7.608	-0.809017	0.587785
4.854	-4.702	-2.87104e-13	9.34808e-14
6	-0	1	-9.32816e-14
*/
