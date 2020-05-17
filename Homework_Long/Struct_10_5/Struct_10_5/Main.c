#include <stdio.h>
#define max 5
typedef struct humanresrc
{
	char name[15];
	char date[20];
	int pay;
}Mem;
void main()

{
	Mem number[2];
	int i = 0;
	for (i = 0; i < 2; i++)
	{
		while (getchar() != '\n' && getchar != EOF);
		printf("Nhap ten nguoi dung %d:\r\n", i);
		gets_s(number[i].name, sizeof(number[i].name));
		printf("Nhap ngay sinh nguoi dung %d:\r\n", i);
		gets_s(number[i].date, sizeof(number[i].date));
		printf("Nhap luong nguoi dung %d:\r\n", i);
		scanf_s("%d", &number[i].pay);
	}
	printf(" Ten nguoi dung thu 1:%s\r\n", number[1].name);
	printf(" Ngay sinh nguoi dung thu 1:%s\r\n", number[1].date);
	printf(" Luong nguoi dung 1 la %d\r\n", number[1].pay);
	//printf("Nhap ten nguoi dung 2:\r\n");
	//fgets(number[1].ten, sizeof(number[1].ten), stdin);
	//printf(" Ten nguoi dung thu 2:%s\r\n", number[1].ten);
	//fgets(number[1].ten, sizeof(number[1].ten), stdin);
	//printf("Nhap ngay sinh nguoi dung 2:\r\n");
	//fgets(number[1].date, sizeof(number[1].date), stdin);
	//printf(" Ngay sinh nguoi dung thu 2:%s\r\n", number[1].date);
	//printf("Nhap luong nguoi dung 2:\r\n");
	//scanf_s("%d", &number[1].pay);
	//printf(" Luong nguoi dung 2 la %d\r\n", number[1].pay);



}