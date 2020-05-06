#include<stdio.h>
#include<stdint.h>

//Average of a array
int mean_array(int array[]);

void main()
{
	// define a array
	int mang[5] = { 1,2,3,4,5 };
	printf("Average of array is %f\r\n", mean_array(mang));
}

int mean_array(int array[])
{
	int* p;
	p = array;
	int i = 0;
	int size = sizeof(array) / sizeof(array[0]);
	//printf("%d\r\n", size);
	float mean = 0;
	double sum = 0;
	for (i; i < size; i++)
	{
		sum = sum + array[i];
		//printf("%d\r\n", sum);
	}
	return sum;
	mean = sum / size;
} 