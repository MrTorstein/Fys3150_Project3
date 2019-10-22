#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <random>

#include <stdlib.h>
#include <stdio.h>
#include <MonteCarloImproved.h>
#include <lib.h>

#define PI 3.14159265358979
#define EPS 3.0e-14

using namespace std;

void MonteCarloImproved::SolverI(int N, double * var_fp, double * avg_fp)
{
    lib * Lib = new lib;

    double tol = pow(10, -10);
    //double lam = - log(tol) / 2;

    random_device rd;  //Will be used to obtain a seed for the random number engine
    mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    uniform_real_distribution<double> dis(0, 1);

    double x_1;
    double r_1;
    double theta_1;
    double phi_1;
    double x_2;
    double r_2;
    double theta_2;
    double phi_2;
    double f;

    for(int i = 0; i <= N; i++)
    {
        x_1 = dis(gen);
        r_1 = -log(1 - x_1);
        theta_1 = PI * dis(gen);
        phi_1 = 2*PI*dis(gen);
        x_2 = dis(gen);
        r_2 = -log(1 - x_1);
        theta_2 = PI * dis(gen);
        phi_2 = 2*PI*dis(gen);
        f = Lib->FunkI(r_1, r_2, theta_1, theta_2, phi_1, phi_2);
        avg_fp[0] += f;
        var_fp[0] += f * f;

    }
    avg_fp[0] *= PI*PI*PI*PI/(4*1024);
    avg_fp[0] /= (double) N;
    //cout << avg_fp[0] << endl;
    //cout << N << " " << var_fp[0] / (double) N << " " << - avg_fp[0] * avg_fp[0] << endl;
    //var_fp[0] = var_fp[0] / (double) N - avg_fp[0] * avg_fp[0];

    //cout << "Variance= " << var_f << " Integral = " << avg_f << endl;
}


