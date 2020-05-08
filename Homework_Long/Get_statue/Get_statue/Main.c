#include <stdio.h>
#include <stdint.h>
#define max 10

typedef char* string;

int strlen(string str);

int stringfind(string strSrc, string strFind);

int statue(string strSrc, string strFind, char arr[]);

void main()

{
	char* data = "HTTP1.1 200 OK\r\n{\"Fan\":\"on\",\r\n\"Light\":\"off\",\r\n\"Motor\":\"on\"}\r\n";

	char a[max];

	string  find = "Fan";

	statue(data, find, a);

	printf("%s", a);

}
int  statue(string strSrc, string strFind, char arr[])
{
	{
		int i = 0;

		int j = 0;

		int index = 0;
		for (i = stringfind(strSrc, strFind) + strlen(strFind) + 3; strSrc[i] != '\"'; i++)
		{

			arr[j++] = strSrc[i];

			index = j;
		}
		while (index < max)
		{
			arr[index] = '\0';
			index++;
		}
		return 0;
		if (strSrc[i] == '\"') return -1;
	}
}
int stringfind(string strSrc, string strFind)
{
	int i = 0;
	for (i = 0; i < strlen(strSrc) - strlen(strFind); i++)
	{
		int j = 0;
		for (j = 0; j < strlen(strFind); j++)
		{
			if (strFind[j] != strSrc[i + j]) break;
		}
		if (j == strlen(strFind)) break;
	}
	if (i == strlen(strSrc) - strlen(strFind)) return -1;
	return i;
}

int strlen(string str)
{
	int i = 0;
	while (str[i++] != 0);
	return i - 1;
}

