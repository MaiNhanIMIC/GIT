#include <stdio.h>
#include <string.h>
char test_key(char arr[], int n, char letter);
char boolen;//check
void main()
{
	char a[100];
	int n = 0;
	char l = 0;
	printf("Nhap vao so phan tu cua mang : \r\n"); scanf_s("%d",&n);
	printf("Nhap ki tu:\r\n"); scanf_s(" %c", &l);
	/*Nhap mang*/
	for (int i = 0; i < n; i++)
	{
		fflush(stdin);
		printf("Ki tu nhap vao cho a[%d]=\r\n ", i + 1); 
		scanf_s(" %c", &a[i]);//Phai co dau space
	}
	/*Xuat mang*/
	for (int i = 0; i < n; i++)
	{
		printf("a[%d]=%c\r\n", i + 1,a[i]);
	}
	test_key(a, n, l);
	if (boolen != -1)
	{
		printf(" ki tu nhap vao va chuoi: %c", test_key(a, n, l));

	}
	else printf("Tra ve gia tri %d", boolen);
}
char test_key(char arr[], int n, char letter)
{
	
	for (int i = 0; i < n; i++)
	{
		if (arr[i]==letter)
			return letter;
		else 
		{
			boolen = -1;
			return boolen;
		}
		
	}
}