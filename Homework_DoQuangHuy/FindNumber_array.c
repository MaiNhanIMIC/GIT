#include<stdio.h>
#define MAX 100

void nhap(float a[], int* n);
void xuat(float a[], int n);
float tim(float a[], int n, float c);

int main()
{
	int n;
	float a[MAX];
	float c;
	printf("====== Nhap Mang ====== \r\n");
	nhap(a, &n);
	printf("====== Xuat Mang ====== \r\n");
	xuat(a, n);
	printf("====== Tim Phan Tu ====== \r\n");
	printf("Nhap ky tu can tim: \r\n");
	scanf("%f", &c);
	float vtri = 0;
	vtri = tim(a, n, c);
	printf("Phan tu %.2f o vi tri %.2f", c, vtri);
	return 0;
}

void nhap(float a[], int* n)
{
	do
	{
		printf("\nNhap so phan tu: ");
		scanf("%d", n);
		if (*n <= 0 || *n > MAX)
		{
			printf("\nSo phan tu khong hop le. Xin kiem tra lai !");
		}
	} while (*n <= 0 || *n > MAX);
	for (int i = 0; i < *n; i++)
	{
		printf("\nNhap a[%d]: ", i);
		scanf("%f", &a[i]);
	}
}

void xuat(float a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%.2f ", a[i]);
	}
	printf("\r\n");
}

float tim(float a[], int n, float c)
{
	int i = 0;
	int vitri = 0;
	for (i = 0; i < n; i++)
	{
		if (a[i] == c)
		{
			vitri = i;
			return vitri;
		}
	}
	return -1;
}