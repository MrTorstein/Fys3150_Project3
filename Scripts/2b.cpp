#include <cmath>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>

#include <stdlib.h>
#include <stdio.h>
#include <lib.h>

#define EPS 3.0e-14
#define MAXIT 10
#define PI 3.14159265358979

using namespace std;

void integrate_gaulag(){
/*This is a function that returns nothing, and fills a file with integration values*/
    /*Arrays of length N
    r: integration variable
    w_r: weight function array for r
    theta: integration variable
    w_theta: weight function array for theta
    phi: integration variable
    w_phi: weight function array for phi
    */
    lib * Lib = new lib;

    //Arrays for 3b
    const int N = 5;
    double* r = new double[N+1];
    double* w_r = new double[N+1];
    double* theta = new double[N];
    double* w_theta = new double[N];
    double* phi = new double[N];
    double* w_phi = new double[N];
    //Using Gauss-laguerre to fill the arrays where the integration variable goes from 0 to infinity
    //Using Gauss-legendre to fill the arrays with defined integration limits
    Lib->gauss_laguerre(r, w_r, N, 2);
    Lib->gauleg(0, PI, theta, w_theta, N);
    Lib->gauleg(0, 2*PI, phi, w_phi, N);

    //Opens file to save integration result
    ofstream myfile;
    myfile.open ("example.txt");
    
    //for-loop to calculate integral
    double integral = 0;
    for ( int i0 = 1;  i0 < N+1; i0++){
        for ( int i1 = 1;  i1 < N+1; i1++){
            for ( int i2 = 0;  i2 < N; i2++){
                for ( int i3 = 0; i3 < N; i3++){
                    for ( int i4 = 0;  i4 < N; i4++){
                        for ( int i5 = 0;  i5 < N; i5++){
                            //writes integralvalues to file
                            myfile << integral/1024 << endl;
                            double cos_beta = (cos(theta[i2])*cos(theta[i3])+sin(theta[i2])*sin(theta[i3])*cos(phi[i4]-phi[i5]));
                            //removes values where we divide by zero
                            if (abs(cos_beta - 1) < EPS)
                            {
                                integral += 0;
                            }
                            else
                            {
                                integral += w_r[i0]*w_r[i1]*w_theta[i2]*w_theta[i3]*w_phi[i4]*w_phi[i5]*
                                sin(theta[i2])*sin(theta[i3])/sqrt(r[i0]*r[i0]+r[i1]*r[i1]-2*r[i0]*r[i1]*
                                cos_beta);
                            }
                        }
                    }
                }
            }
        }
    }
    //writes in last integral-value
    myfile << integral/1024 << endl;
    myfile.close();

    //deletes arrays again
    delete[] r;
    delete[] w_r;
    delete[] theta;
    delete[] w_theta;
    delete[] phi;
    delete[] w_phi;
}
