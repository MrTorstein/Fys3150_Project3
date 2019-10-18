#include <cmath>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <stdlib.h>
#include <stdio.h>
#define EPS 3.0e-14
#define MAXIT 10
#define PI 3.14159265358979

using namespace std;

int integrate_gaulag(){

//Arrays for 3b
    const int N = 5;
    double* r = new double[N+1];
    double* w_r = new double[N+1];
    double* theta = new double[N];
    double* w_theta = new double[N];
    double* phi = new double[N];
    double* w_phi = new double[N];
    //Gauss-laguerre
    gauss_laguerre(r, w_r, N, 2);
    gauss_legendre(0, PI, theta, w_theta, N);
    gauss_legendre(0, 2*PI, phi, w_phi, N);

    
    double integral = 0.;
    for ( int i0 = 1;  i0 < N+1; i0++){
        for ( int i1 = 1;  i1 < N+1; i1++){
            for ( int i2 = 0;  i2 < N; i2++){
                for ( int i3 = 0; i3 < N; i3++){
                    for ( int i4 = 0;  i4 < N; i4++){
                        for ( int i5 = 0;  i5 < N; i5++){
                            integral += w_r[i0]*w_r[i1]*w_theta[i2]*w_theta[i3]*w_phi[i4]*w_phi[i5]*
                            sin(theta[i2])*sin(theta[i3])/sqrt(r[i0]*r[i0]+r[i1]*r[i1]-2*r[i0]*r[i1]*
                            (cos(theta[i2])*cos(theta[i3])+sin(theta[i2])*sin(theta[i3])*cos(phi[i4]-phi[i5])));
                        }
                    }
                }
            }
        }
    }

    delete[] r;
    delete[] w_r;
    delete[] theta;
    delete[] w_theta;
    delete[] phi;
    delete[] w_phi;

    return integral;
}
