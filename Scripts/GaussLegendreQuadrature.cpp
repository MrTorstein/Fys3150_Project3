#include <cmath>

#include "GaussLegendreQuadrature.h"
#include "lib.h"

using namespace std;

double GaussLegendreQuadrature::Solver(int N, double * x, double * w)
{
    lib * Lib = new lib;
    double tol = pow(10, -10);
    double Result = 0;

    x[0] = - tol; x[N] = tol;
    Lib->gauleg(-tol, tol, x, w, N);

    for(int i = 0; i <= N; i++)
    {
        Result += Lib->Legendre(N, x[i]) * w[i];
    }
    return Result;
}
