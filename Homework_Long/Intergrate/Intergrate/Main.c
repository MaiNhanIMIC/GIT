#include <stdio.h>
#include <math.h>
#define PI 3.14
float inter(float a, float b);

int n;
void main()
{
	float up=0, down=0;

	printf("Nhap so lan chia :\r\n");

	scanf_s("%d", &n);

	printf("Nhap can duoi tich phan: \r\n"); scanf_s("%f", &down);
	up = PI / 2;
	printf("Gia tri tich phan cua sinx tu %2.2f den %2.2f = %3.2f \r\n", down, up, inter(down,up));

}
float inter(float a, float b)
{
	float h = (b - a) / n;
	float j = 0;
	float s = (sin(a) + sin(b)) / 2;
	for (int i = 1; i < n; i ++)
	{
		j =j+ sin(a + i * h);
	}
	s = (s + j) * h;
	return s;
}