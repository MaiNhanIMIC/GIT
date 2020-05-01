#include <stdio.h>

float average(int a[], int n);
void main()
{
	
	int n = 0;
	int arr[100];
	printf("Nhap so phan tu cua mang:\r\n",n); scanf_s("%d", &n);
	if (n < 0)
	{
		printf("Nhap lai n:");
		scanf_s("%d", &n);
	}
	/*Nhap mang */
	for (int i = 0; i < n; i++)
	{
		printf("arr[%d]=\r\n", i + 1); 
		scanf_s("%d", &arr[i]);
	}
	/* Xuat mang */
	for (int i = 0; i < n; i++)
	{
		printf("arr[%d]=%d\r\n", i + 1, arr[i]);
	}
	printf("Gia tri trung binh cua mang la %3.2f", average(arr, n));

}
float average(int a[], int n)
{
	int s = 0;
	for (int i = 0; i <n ; i++)
	{
		s += a[i];
	}
	s = s / n;
	return s;

}