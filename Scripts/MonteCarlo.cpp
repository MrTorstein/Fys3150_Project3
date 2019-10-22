#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <random>

#include <stdlib.h>
#include <stdio.h>
#include <MonteCarlo.h>
#include <lib.h>

using namespace std;

void MonteCarlo::Solver(int N, double * var_f, double * avg_f)
{
    lib * Lib = new lib;

    double tol = pow(10, -10);
    double lam = - log(tol) / 2;

    random_device rd;  //Will be used to obtain a seed for the random number engine
    mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    uniform_real_distribution<> dis(0, 1);

    double x1;
    double y1;
    double z1;
    double x2;
    double y2;
    double z2;
    double f;

    for(int i = 0; i <= N; i++)
    {
        x1 = (-lam + dis(gen) * 2 * lam);
        y1 = (-lam + dis(gen) * 2 * lam);
        z1 = (-lam + dis(gen) * 2 * lam);
        x2 = (-lam + dis(gen) * 2 * lam);
        y2 = (-lam + dis(gen) * 2 * lam);
        z2 = (-lam + dis(gen) * 2 * lam);
        f = Lib->Funk(x1, y1, z1, x2, y2, z2);
        avg_f[0] += f;
        var_f[0] += f * f;

        cout << f << endl;
    }
    avg_f[0] /= (double) N;
    var_f[0] = var_f[0] / (double) N - avg_f[0] * avg_f[0];

    //cout << "Variance= " << var_f << " Integral = " << avg_f << endl;

}
