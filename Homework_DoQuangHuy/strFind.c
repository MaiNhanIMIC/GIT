#include<stdio.h>

typedef char* string;

int Strlen(char* s);
int strngFind(string stringSrc, string stringFind);

int main()
{
	char* strSrc = "HTTP1.1 200 OK\r\n{\"Fan\":\"ON\",\r\n\"Light\":\"off\",\r\n\"Motor\":\"on\"}\r\n";
	char* strFind = "Fan";
	printf("%s\r\n", strFind);
	int result;
	result = strngFind(strSrc, strFind);
	printf("%d\r\n", result);
	if (result == -1) {
		printf("Not found string\r\n");
	}
	else {
		printf("String at index %d", result);
	}
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

int strngFind(string stringSrc, string stringFind)
{
	int i = 0;
	for (i = 0; i < Strlen(stringSrc) - Strlen(stringFind); i++)
	{
		int j = 0;
		for (j = 0; j < Strlen(stringFind); j++)
		{
			if (stringFind[j] != stringSrc[i + j])break;
		}
		if (j == Strlen(stringFind))break;
	}
	if (i == Strlen(stringSrc) - Strlen(stringFind))return -1;
	return i;
}

char status(int index, string stringSrc, int strlen)
{
	int start = index + strlen + 3;
	while(stringSrc[start] != '\"')
	{
		printf("%c",stringSrc[start]);
		start++;
	}
	return 0;
}