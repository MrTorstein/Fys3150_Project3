#include <iostream>
#include "gauss-laguerre.cpp"
#include "gauss-legendre.cpp"
#include "2b.cpp"

using namespace std;

int main()
{   
    cout << integrate_gaulag()/(64) << endl;

    return 0;
}
