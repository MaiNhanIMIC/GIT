#include<stdio.h>


int main()
{
	int a[2][3][5];
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 5; k++)
			{
				a[i][j][k] = 100 * (i + 1) + 10 * j + k + 1;
			}
		}
	}
	printf("Display 3D Array: \r\n");
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 5; k++)
			{
				printf("%d%c", a[i][j][k], k == 4 ? '\n' : ' ');
			}
			printf("%c", j == 2 ? '\n' : '\b');
		}
	}
	return 0;
}