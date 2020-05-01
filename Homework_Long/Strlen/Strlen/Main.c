#include <stdio.h>
int strlen(char * a);
void main()
{
	char* msg = "Hello World";
	printf("Do dai chuoi la %d \r\n", strlen(msg));

}
int strlen(char *a)

{
	int count = 0;
	for (int i = 0; *(a + i) != '\0'; i++)
	{
		count = i;
	}
	
	return ++count;
}