#include <iostream>
#include <cmath>

#include "GaussLegendreQuadrature.h"
#include "lib.h"

using namespace std;

double GaussLegendreQuadrature::Solver(int N, double * x1, double * x2, double * w)
{
    lib * Lib = new lib;
    double tol = pow(10, -10);
    double lam = - log(tol) / 2;
    double Result = 0;

    x1[0] = - lam; x1[N - 1] = lam;
    x2[0] = - lam; x2[N - 1] = lam;
    x3[0] = - lam; x3[N - 1] = lam;
    x4[0] = - lam; x4[N - 1] = lam;
    x5[0] = - lam; x5[N - 1] = lam;
    x6[0] = - lam; x6[N - 1] = lam;
    /*
    for (int i = 0; i < N; i++)
    {
    cout << i << " " << x[i] << endl;
    }
    */
    Lib->gauleg(x1[0], x1[N], x1, w, N);
    /*
    for (int i = 0; i < N; i++)
    {
    cout << i << " " << x[i] << endl;
    }
    */

    for(int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            for (int k = 0; k < N; k++)
                for (int l = 0; l < N; l++)
                    for (int m = 0; m < N; m++)
                        for (int n = 0; n < N; n++)
        {
            cout << lam * x1[i] + lam << " " << 2 * lam * lam << endl;
            Result += lam * Lib->Funk(lam * x1[i] + lam, 2 * lam * lam) * w[i];
        }
    return Result;
}
