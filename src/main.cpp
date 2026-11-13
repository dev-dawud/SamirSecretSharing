#pragma warning(disable : 4146)
#pragma warning(disable : 4244)

#include <iostream>

#include "header/generate.h"
#include "header/reconstruct.h"

int main()
{
    Generate gn;
    Reconstruct rc;

    gn.Parameter();
    gn.calculatePolynom();

    rc.getPoints(gn.getResult(), gn.getCalcGrade());
    rc.calculateLagrange();

    return 0;
}