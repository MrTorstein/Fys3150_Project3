#include <iostream>
#include "2b.cpp"
#include "MonteCarlo.cpp"
#include "MonteCarloImproved.cpp"

#include <GaussLegendreQuadrature.h>
#include <MonteCarlo.h>
#include <MonteCarloImproved.h>



using namespace std;

int main()
{   
    const int N = 5;

    //Gauss-Legendre
    GaussLegendreQuadrature * GLQ = new GaussLegendreQuadrature;

    double res = GLQ->Solver(N);

    cout << "N = " << N << endl;
    cout << "res " << res << endl;

    /*
    //Gauss-laguerre
    integrate_gaulag();
    */

    /*
    // Monte Carlo Method
    MonteCarlo * MC = new MonteCarlo;

    ofstream myfile1;
    myfile1.open ("data_MC.txt");

    for (int n = 1; n <= pow(10, 1); n++)
    {
        double * var_f = new double [1];
        double * avg_f = new double [1];
        MC->Solver(n, var_f, avg_f);
        myfile1 << n << " " << var_f[0] << " " << avg_f[0] << endl;
    }
    myfile1.close();
    */
    /*
    // Monte Carlo Method
    MonteCarloImproved * MCI = new MonteCarloImproved;

    ofstream myfile2;
    myfile2.open ("data_MCI.txt");

    for (int n = 1; n <= pow(10, 4); n++)
    {
        double * var_fp = new double [1];
        double * avg_fp = new double [1];
        MCI->SolverI(n, var_fp, avg_fp);
        myfile2 << n << " " << var_fp[0] << " " << avg_fp[0] << endl;
    }
    myfile2.close();
    */
    return 0;
}
