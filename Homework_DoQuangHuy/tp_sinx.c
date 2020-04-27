#include<stdio.h>
#include<math.h>
#define PI 3.14

double tp(double f(double), double a, double b);

int main()
{
	double result = 0;
	result = tp(sin, 0, PI / 2);
	printf("\nTich phan ham sin(x) tren doan [0,PI/2] la: %f\r\n", result);
	return 0;
}

double tp(double f(double), double a, double b)
{
	int i = 0;
	int n = 1000;
	double s = 0;
	
	double h = (b - a)/n;
	s = (f(a) + f(b))/2;
	
	for (i = 1; i < n; i++)
	{
		s = s + f(a + i*h);
	}
	return h * s;
}