#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "stdint.h"
#include "Socket.h"

typedef char* string;

int main()
{
	char buff[1024];
	Get_Data_AWS(buff, sizeof(buff));
	string strFind = "Date";
	int length = stringLen(strFind);
	int result = strngFind(buff, strFind);
	if (result == -1) {
		printf("\nNot found string\r\n");
	}
	else {
		printf("\nString %s at index %d\r\n",strFind, result);
	}
	printf("=== noi dung chuoi string ===\r\n");
	status(result, buff, length);
	return 0;
}
