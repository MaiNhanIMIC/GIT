#include<stdio.h>
#include<stdint.h>

int count_str(char* msg);

void main()
{
	//Version 1

	char *msg = "Hello C progrmaming language"; // return the memory address of first char in string
	printf("the length of string%d\r\n", count_str(msg));

	/*Version 2*/
	/*char* str[123];
	printf("Please in a string :\r\n");
	scanf_s("%s", *str);
	printf("The length of string %d\r\n", count_str(str));*/
}

int count_str(char*msg)
{
	int i = 0;
	for (i; *(msg + i)!=0; i++);
	return i;
}
