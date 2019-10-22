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
    double FunkI(double, double, double, double, double, double);
};

#endif // LIB_H
