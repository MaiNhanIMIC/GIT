#include <stdio.h>
#include <iostream>
#include <math.h>
#include "tinhtichphan.hpp"

#define PI 3.14

//int main(void)
//{
//    double a=0;
//    double b= PI / 2;
//    int n = 1000;
//    double h = (b-a)/n;
//    double s = (sin(a) + sin(b))/2;
//
//    for (int i=1; i<n; i++)
//        s += sin(a+i*h);
//    printf("result: %f\n", h*s);
//    return 0;
//}

int main(void)
{
    tinhtichphan(sin, 0, PI/2, 1000);
    return 0;
}
