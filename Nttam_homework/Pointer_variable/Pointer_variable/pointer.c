#include<stdint.h>
#include<stdio.h>

void main()
{
	int x = 5;
	printf("Dia chi o nho cua x la: %p\r\n", &x);
	printf("Gia tri cua x la %d\r\n", x);
	
	int* p = &x;
	*p = 7;
	printf("Dia chi o nho cua *p la: %p\r\n", &*p);
	printf("Gia tri cua *p la %d\r\n", *p);

	printf("Gia tri cua x la %d\r\n", x);
}