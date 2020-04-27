#include<stdio.h>

int Strlen(char* s);

int main()
{
	char* msg = "hello world";
	int length = 0;
	length = Strlen(msg);
	printf("Do dai chuoi string la: %d", length);
	return 0;
}

int Strlen(char* s)
{
	int count = 0;
	for (int i = 0; *(s + i) != 0; i++)
	{
		count++;
	}
	return count;
}