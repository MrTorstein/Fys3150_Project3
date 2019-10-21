#ifndef LIB_H
#define LIB_H


class lib
{
public:
    double gammln(double);
    void gauss_laguerre(double *, double *, int, double);
    void gauleg(double, double, double *, double *, int);
    double Legendre(int, double);
    double Funk(double, double);
    double int_function(double);

    int sign = 1;
};

#endif // LIB_H
