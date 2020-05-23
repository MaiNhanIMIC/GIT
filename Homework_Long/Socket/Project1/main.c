#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "stdint.h"
#include "Socket.h"


void main()
{
	char buff[1024];
	int i = 0,a=0;
	Get_Data_AWS(buff, sizeof(buff));
	//Get_Img_AWS("image.png");
	//Put_Data_AWS("LED_ON");
}
