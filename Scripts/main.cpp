#include <iostream>
#include "2b.cpp"

#include <GaussLegendreQuadrature.h>

using namespace std;

int main()
{   
    const int N = 5;

    //Gauss-Legendre
    GaussLegendreQuadrature * GLQ = new GaussLegendreQuadrature;

    double res = GLQ->Solver(N);

    cout << "N = " << N << endl;
    cout << "res " << res << endl;


    //Gauss-laguerre
    integrate_gaulag();


    // Monte Carlo Method
    MonteCarlo * MC = new MonteCarlo;

    ofstream myfile;
    myfile.open ("data_MC.txt");

    for (int n = 1; n <= pow(10, 4); n++)
    {
        double * var_f = new double [1];
        double * avg_f = new double [1];
        MC->Solver(n, var_f, avg_f);
        myfile << n << " " << var_f[0] << " " << avg_f[0] << endl;
    }
    myfile.close();

    return 0;
}
