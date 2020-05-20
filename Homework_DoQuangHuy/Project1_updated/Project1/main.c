#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "stdint.h"
#include "Socket.h"

//typedef char* string;

int main()
{
	char buff[1024];
	memset(buff, 0, sizeof(buff));
	Get_Img_AWS(buff);
	//sprintf("LED_ON");
	/*char* data = "LED_ON";*/
	//Put_Data_AWS(data);
	/*Get_Data_AWS(buff, sizeof(buff));*/
	return 0;
}
