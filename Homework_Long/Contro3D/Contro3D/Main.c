#include <stdio.h>

void main()
{
	 unsigned char a[2][3][5];
	{
		for (int x = 0; x < 2; x++)
		{
			for (int y = 0; y < 3; y++)
			{
				for (int z = 0; z < 5; z++)
				{
					a[x][y][z] = 100 *(x + 1) + 10 * (y) + z+1;
				}
			}
		}
		for (int x = 0; x < 2; x++)
		{
			for (int y = 0; y < 3; y++)
			{
				for (int z = 0; z < 5; z++)
				{
					printf("a[%d][%d][%d] = %d\r\n", x + 1, y + 1, z + 1, a[x][y][z]);
				}
			}
		}
	}
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 5; k++)
			{
				printf("Gia tri cua mang 2 chieu dung con tro la a[%d][%d][%d]=%d \r\n",i+1, j + 1, k + 1, *(a[i][j]+k));
			}
		}
	}

	
}