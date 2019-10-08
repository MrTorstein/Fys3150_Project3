#include <iostream>
#include "gauss-laguerre.h"

using namespace std;

int main()
{   
    //Gauss-Legendre
    const int N = 100;
    double x[N+1];
    double w[N+1];
    //Gauss-laguerre
    double r[N];
    double s[N];
    //gauss_laguerre(x, w, N, 2);

    gauleg(-1.0, 1.0,x,w, n);
    double pi_4 = acos(-1.0)*0.25;
    for ( int i = 0;  i < n; i++){
        double xx=pi_4*(x[i]+1.0); 
        r[i]= tan(xx);
        s[i]=pi_4/(cos(xx)*cos(xx))*w[i];
    }
    double int_gausslegimproved = 0.;
    for ( int i = 0;  i < n; i++){
        int_gausslegimproved += s[i]*int_function(r[i]);     
    }
    /*
    for(int i = 0; i < N; i++){
        cout << "x = " << x[i] << endl;
    }
    for(int i = 0; i < N; i++){
        cout << "w = " << w[i] << endl;
    }
    */
    //cout << "Hello World!" << endl;
    return 0;
double int_function(double x);
{
    int alpha = 2
    
    double value = r_1**2*r_2**2*np.sin(theta_1)*np.sin(theta_2)*np.exp(-2*alpha*(r_1+r_2));
    return value;
}