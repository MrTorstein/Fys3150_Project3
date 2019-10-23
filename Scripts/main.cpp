#include <iostream>
#include <ctime>
#include <time.h> 
#include <thread>
#include <iomanip>
#include "2b.cpp"
#include "MonteCarlo.cpp"
#include "MonteCarloImproved.cpp"

#include <GaussLegendreQuadrature.h>
#include <MonteCarlo.h>
#include <MonteCarloImproved.h>



using namespace std;

int main()
{   
    //const int N = 5;
    /*
    //Gauss-Legendre
    GaussLegendreQuadrature * GLQ = new GaussLegendreQuadrature;

    double res = GLQ->Solver(N);

    cout << "N = " << N << endl;
    cout << "res " << res << endl;


    //Gauss-laguerre
    integrate_gaulag();

    */
    auto start_processor_usage = std::clock();
    
    // Monte Carlo Method
    MonteCarlo * MC = new MonteCarlo;

    ofstream myfile1;
    myfile1.open ("data_MC.txt");
    #pragma omp parallel
    for (int n = 1; n <= pow(10, 1); n++)
    {
        double * var_f = new double [1];
        double * avg_f = new double [1];
        MC->Solver(n, var_f, avg_f);
        myfile1 << n << " " << var_f[0] << " " << avg_f[0] << endl;
    }
    myfile1.close();
    auto finish_processor_usage = std::clock();
    
    /*
    auto start_processor_usage = clock();
    
    // Monte Carlo Method
    MonteCarloImproved * MCI = new MonteCarloImproved;
   
    ofstream myfile2;
    myfile2.open ("data_MCI.txt");
    #pragma omp parallel
    for (int n = 1; n <= pow(10, 4); n++)
    {
        double* var_fp = new double[1];
        double* avg_fp = new double[1];
        var_fp[0] = 0;
        avg_fp[0] = 0;
        MCI->SolverI(n, var_fp, avg_fp);
        myfile2 << n << " " << avg_fp[0] << endl;
    }
    myfile2.close();
    
    auto finish_processor_usage = clock();
    */
    cout << (double)(finish_processor_usage - start_processor_usage)/ CLOCKS_PER_SEC << endl;
}
/*
    double * var_fp = new double [1];
    double * avg_fp = new double [1];
    MCI->SolverI(pow(10,6), var_fp, avg_fp);
    //cout << avg_fp[0] << endl;
    return 0;
}
*/