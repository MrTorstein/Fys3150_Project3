#include <cmath>

#include "lib.h"

/*
 ** The function gauleg()
 ** takes the lower and upper limits of integration x1, x2, calculates
 ** and return the abcissas in x[0,...,n - 1] and the weights in w[0,...,n - 1]
 ** of length n of the Gauss--Legendre n--point quadrature formulae.
 */

void lib::gauleg(double x1, double x2, double x[], double w[], int n)
{
int         m,j,i;
double      z1,z,xm,xl,pp,p3,p2,p1;
double      const  pi = 3.14159265359;
double      *x_low, *x_high, *w_low, *w_high;

m  = (n + 1)/2;                             // roots are symmetric in the interval
xm = 0.5 * (x2 + x1);
xl = 0.5 * (x2 - x1);

x_low  = x;                                       // pointer initialization
x_high = x + n - 1;
w_low  = w;
w_high = w + n - 1;

for(i = 1; i <= m; i++) {                             // loops over desired roots
z = cos(pi * (i - 0.25)/(n + 0.5));

     /*
 ** Starting with the above approximation to the ith root
     ** we enter the mani loop of refinement bt Newtons method.
     */

do {
   p1 =1.0;
p2 =0.0;

 /*
 ** loop up recurrence relation to get the
     ** Legendre polynomial evaluated at x
     */

for(j = 1; j <= n; j++) {
  p3 = p2;
  p2 = p1;
  p1 = ((2.0 * j - 1.0) * z * p2 - (j - 1.0) * p3)/j;
}

 /*
 ** p1 is now the desired Legrendre polynomial. Next compute
     ** ppp its derivative by standard relation involving also p2,
     ** polynomial of one lower order.
     */

pp = n * (z * p1 - p2)/(z * z - 1.0);
z1 = z;
z  = z1 - p1/pp;                   // Newton's method
} while(fabs(z - z1) > 0);

    /*
** Scale the root to the desired interval and put in its symmetric
    ** counterpart. Compute the weight and its symmetric counterpart
    */

*(x_low++)  = xm - xl * z;
*(x_high--) = xm + xl * z;
*w_low      = 2.0 * xl/((1.0 - z * z) * pp * pp);
*(w_high--) = *(w_low++);
}
}
// End_ function gauleg()


// This function computes the Legendre polynomial of degree N
double lib::Legendre(int n, double x)
{
    double r, s, t;
    int m;
    r = 0; s = 1.;
    // Use recursion relation to generate p1 and p2
    for (m=0; m < n; m++ )
    {
        t = r; r = s;
        s = (2*m+1)*x*r - m*t;
        s /= (m+1);
    } // end of do loop
    return s;
}
// end of function Legendre

double lib::Funk(double x1, double x2)
{
    if(fabs(x1 - x2) < pow(10, -10))
    {
        return 0;
    }
    else
    {
        return 1 / fabs(sign * x1 - sign * x2) * exp(-2 * (x1 + x2));
    }
}
// End of function Funk
