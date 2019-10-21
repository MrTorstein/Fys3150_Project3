#include <iostream>
#include "2b.cpp"

#include "GaussLegendreQuadrature.h"
#include "lib.h"

using namespace std;

int main()
{   
    const int N = 5;

    //Gauss-Legendre
    GaussLegendreQuadrature * GLQ = new GaussLegendreQuadrature;

    double res_1 = GLQ->Solver(N);

    cout << "res " << res << endl;

    //Gauss-laguerre


    //gauss_laguerre(x, w, N, 2);
    integrate_gaulag();

    return 0;
}
