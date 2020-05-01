#include<stdio.h>
#define MAX 100

void nhap(float a[], int* n);
void xuat(float a[], int n);
float trungbinhcong(float a[], int n);

int main()
{
	int n;
	float a[MAX];
	printf("====== Nhap Mang ====== \r\n");
	nhap(a, &n);
	printf("====== Xuat Mang ====== \r\n");
	xuat(a, n);
	printf("====== Trung Binh Cong ====== \r\n");
	float tb = 0;
	tb = trungbinhcong(a, n);
	printf("Gia tri trung binh cong cac phan tu trong mang la: %.2f", tb);
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

float trungbinhcong(float a[], int n)
{
	float sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += a[i];
	}
	float tbinh = 0;
	tbinh = (tbinh + sum) / n;
	return tbinh;
}