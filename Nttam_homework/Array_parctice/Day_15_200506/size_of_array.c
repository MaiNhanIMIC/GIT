#include <stdio.h>
#include<stdint.h>
#include <stdlib.h>

void printSizeOf(int intArray[]);
void printLenght(int intArray[]);

void main()
{
	char a[] = { 0,1,2,3,4};;
	int array[] = { 0,1,2,3,4,5,6 };
	printf("size of array: %d\r\n", (int)sizeof(array));
	printSizeOf(a);

	printf("Length of array: %d\r\n", (int)(sizeof(array) / sizeof(array[0])));
	printLenght(array);
}


void printSizeOf(int intArray[])
{
	printf("size of parameter: %d\r\n", (int)sizeof(intArray));
}


void printLenght(int intArray[])
{
	printf("lenght of parameter 1: %d\r\n", (int)sizeof(intArray));
	printf("lenght of parameter 2: %d\r\n", (int)sizeof(intArray[0]));
	printf("lenght of parameter: %d\r\n", (int)(sizeof(intArray) / sizeof(intArray[0])));
}