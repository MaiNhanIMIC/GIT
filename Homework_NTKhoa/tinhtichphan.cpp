#include <stdio.h>
#include <math.h>

#include "tinhtichphan.hpp"
#define PI 3.14

void tinhtichphan(double (*f)(double), double a, double b, int n)
{
    double h = (b-a)/n;
    double s = (f(a) + f(b))/2;
    
    for (int i=1; i<n; i++)
        s += f(a+i*h);
    printf("result: %f\n", h*s);
}
