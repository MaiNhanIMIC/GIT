#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "stdint.h"
#include "Header.h"
#include <string.h>

void main()
{
	char buff[1024];
	int i = 0, a = 0;
	Get_Data_AWS(buff, sizeof(buff));
	char state1[max], state2[max];
	char state1_1[max];
	char state1_2[max];
	char state1_3[max];
	str find1 = "Date: ";
	str find2 = "2020 ";
	state(buff, find1, state1);
	printf("%s\r\n", state1);
	strcat(state1, " ");
	state(buff, state1, state1_1);
	printf("%s\r\n", state1_1);
	strcat(state1_1, " ");
	state(buff, state1_1, state1_2);
	printf("%s\r\n", state1_2);
	strcat(state1_2, " ");
	state(buff, state1_2, state1_3);
	printf("%s\r\n", state1_3);
	state(buff, find2, state2);
	printf("%s\r\n", state2);
	/*Put_Data_AWS("LED_ON");*/
}
