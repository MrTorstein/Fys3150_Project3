#include <iostream>
#include "GaussLaguerre.cpp"
#include "gauss-legendre.cpp"
#include "2b.cpp"

#include <GaussLaguerre.h>
#include <GaussLegendreQuadrature.h>
#include <lib.h>

using namespace std;

double int_function(double);

int main()
{   
    //Gauss-Legendre
    GaussLegendreQuadrature * GLQ = new GaussLegendreQuadrature;
    lib * Lib = new lib;

    const int N = 6;
    double * x1 = new double [N + 1];
    double * x2 = new double [N];
    double * w = new double [N + 1];
    for(int i = 1; i < N; i++)
    {
        x1[i] = 0;
        x2[i] = 0;
        w[i] = 0;
    }
    double res_1 = GLQ->Solver(N, x1, x2, w);

    Lib->sign = -1;
    for(int i = 1; i < N; i++)
    {
        x1[i] = 0;
        x2[i] = 0;
        w[i] = 0;
    }
    double res_2 = GLQ->Solver(N, x2, x1, w);

    cout << "res_1 " << res_1 << endl;
    cout << "res_2 " << res_2 << endl;
    cout << "totres " << 3 * res_1 + 3 * res_2 << endl;


    //Gauss-laguerre
    double r[N];
    double s[N];
    //gauss_laguerre(x, w, N, 2);
    integrate_gaulag()

    Lib->gauleg(-1.0, 1.0,x1,w, N);
    double pi_4 = acos(-1.0)*0.25;
    for ( int i = 0;  i < N; i++)
    {
        double xx=pi_4*(x1[i]+1.0);
        r[i]= tan(xx);
        s[i]=pi_4/(cos(xx)*cos(xx))*w[i];
    }
    double int_gausslegimproved = 0.;
    for ( int i = 0;  i < N; i++)
    {
        int_gausslegimproved += s[i]*int_function(r[i]);
    }


    for(int i = 0; i < N; i++)
    {
        cout << "x = " << x1[i] << endl;
    }
    for(int i = 0; i < N; i++){
        cout << "w = " << w[i] << endl;
    }
    //cout << "Hello World!" << endl;

    delete [] x1;
    delete [] x2;
    delete [] w;

    return 0;
}

double int_function(double x)
{
    int alpha = 2;
    
    double value = alpha; //r_1**2*r_2**2*np.sin(theta_1)*np.sin(theta_2)*np.exp(-2*alpha*(r_1+r_2));

    return value;
}
