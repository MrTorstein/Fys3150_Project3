#include <iostream>
#include "2b.cpp"

#include "GaussLegendreQuadrature.h"
#include "lib.h"

using namespace std;

int main()
{   
    lib * Lib = new lib;
    const int N = 5;

    //Gauss-Legendre
    GaussLegendreQuadrature * GLQ = new GaussLegendreQuadrature;

    //double * x1 = new double [N];
    //double * x2 = new double [N];
    //double * w1 = new double [N];

    double res_1 = GLQ->Solver(N);

    Lib->sign = -1;

    double res_2 = GLQ->Solver(N);

    cout << "res_1 " << res_1 << endl;
    //cout << "res_2 " << res_2 << endl;
    //cout << "totres " << 3 * res_1 + 3 * res_2 << endl;


    //Gauss-laguerre

    double * x = new double [N + 1];
    double * w = new double [N + 1];
    double r[N];
    double s[N];
    //gauss_laguerre(x, w, N, 2);
    integrate_gaulag();

    Lib->gauleg(-1.0, 1.0, x, w, N);
    double pi_4 = acos(-1.0)*0.25;
    for ( int i = 0;  i < N; i++)
    {
        double xx=pi_4*(x[i]+1.0);
        r[i]= tan(xx);
        s[i]=pi_4/(cos(xx)*cos(xx))*w[i];
    }
    double int_gausslegimproved = 0.;
    for ( int i = 0;  i < N; i++)
    {
        int_gausslegimproved += s[i]*Lib->int_function(r[i]);
    }


    for(int i = 0; i < N; i++)
    {
        cout << "x = " << x[i] << endl;
    }
    for(int i = 0; i < N; i++){
        cout << "w = " << w[i] << endl;
    }
    //cout << "Hello World!" << endl;

    delete [] x;
    delete [] w;
    //delete [] x1;
    //delete [] x2;
    //delete [] w1;

    return 0;
}
