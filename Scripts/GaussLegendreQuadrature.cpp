#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>

#include <stdlib.h>
#include <stdio.h>

#include "GaussLegendreQuadrature.h"
#include "lib.h"

using namespace std;

double GaussLegendreQuadrature::Solver(int N)
{
    lib * Lib = new lib;
    double tol = pow(10, -10);
    double lam = 1;//- log(tol) / 2;
    double Result = 0;

    double * x1 = new double [N];
    double * y1 = new double [N];
    double * z1 = new double [N];
    double * x2 = new double [N];
    double * y2 = new double [N];
    double * z2 = new double [N];
    double * w = new double [N];

    x1[0] = - lam; x1[N - 1] = lam;
    y1[0] = - lam; y1[N - 1] = lam;
    z1[0] = - lam; z1[N - 1] = lam;
    x2[0] = - lam; x2[N - 1] = lam;
    y2[0] = - lam; y2[N - 1] = lam;
    z2[0] = - lam; z2[N - 1] = lam;
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

    ofstream myfile;
    myfile.open ("data.txt");

    for(int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            for (int k = 0; k < N; k++)
                for (int l = 0; l < N; l++)
                    for (int m = 0; m < N; m++)
                        for (int n = 0; n < N; n++)
        {
            myfile << Result/1024 << endl;
            Result += lam * Lib->Funk(lam * (x1[i] + y1[j] + z1[k]), lam * (x2[l] + y2[m] + z2[n])) * w[i] * w[j] * w[k] * w[l] * w[m] * w[n];
        }

    myfile << Result/1024 << endl;
    myfile.close();

    return Result;
}
