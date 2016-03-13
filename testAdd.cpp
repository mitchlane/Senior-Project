#include "had.h"

#include <cassert>
#include <cmath>

using namespace std;
using namespace had;

DECLARE_ADGRAPH();

#define NearEqualAssert(a, b) \
    assert(std::fabs((a) - (b)) < 1e-8)

void TestAdd() {
    ADGraph adGraph;

    AReal x0 = AReal(Real(1.0));
    AReal x1 = AReal(Real(2.0));
    AReal x2 = AReal(Real(3.0));

    AReal y = x0 + x0 + x1 + x2;
    SetAdjoint(y, Real(1.0));
    PropagateAdjoint();

    Real dydx0 = GetAdjoint(x0);
    Real dydx1 = GetAdjoint(x1);
    Real dydx2 = GetAdjoint(x2);

    Real dydx0x0 = GetAdjoint(x0, x0);
    Real dydx0x1 = GetAdjoint(x0, x1);
    Real dydx0x2 = GetAdjoint(x0, x2);
    Real dydx1x1 = GetAdjoint(x1, x1);
    Real dydx1x2 = GetAdjoint(x1, x2);
    Real dydx2x2 = GetAdjoint(x2, x2);

    NearEqualAssert(dydx0, Real(2.0));
    NearEqualAssert(dydx1, Real(1.0));
    NearEqualAssert(dydx2, Real(1.0));

    NearEqualAssert(dydx0x0, Real(0.0));
    NearEqualAssert(dydx0x1, Real(0.0));
    NearEqualAssert(dydx0x2, Real(0.0));
    NearEqualAssert(dydx1x1, Real(0.0));
    NearEqualAssert(dydx1x2, Real(0.0));
    NearEqualAssert(dydx2x2, Real(0.0));
}

int main(int argc, char *argv[])
{
  TestAdd();
}
