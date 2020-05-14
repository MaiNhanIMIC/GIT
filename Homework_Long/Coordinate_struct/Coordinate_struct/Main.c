#include <stdio.h>
// Input bai toan : Cho 2 hinh chu nhat.
//
//Output: Xac dinh phuong trinh duong thang chia hinh chu nhat tren thanh 2 phan bang nhau .
// Hint Solution:
/* Hinh chu nhat co tam cua no la tam doi xung nen moi duong thang qua tam hinh chu nhat deu chia hinh chu nhat thanh 2 phan co dien tich bang nhau .
Do do duong thang di qua duong noi tam cua 2 hinh chu nhat se la duong thang can tim./
*/
typedef struct coordinate
{
	int x;
	int y;
}Point;
int check_condition(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4);
void linear(Point arr[]);
void main()
{
	Point ar[8];
	linear(ar);

}
void linear(Point arr[])
{
	float X1 = 0, Y1 = 0;//Nhap diem tam 2 hcn ban dau
	float X2 = 0, Y2 = 0;
	int a = 0;// check status.
	do
	{
		for (int i = 0; i < 8; i++)
		{
			if (i == 0) printf("Toa do 4 diem cua hinh chu nhat thu nhat lan luot la :\r\n");
			printf("X%d=	\r\n", i + 1);
			scanf_s("%d", &arr[i].x);
			printf("Y%d=	\r\n", i + 1);
			scanf_s("%d", &arr[i].y);
			if (i == 3) printf("Toa do 4 diem cua hinh chu nhat thu hai lan luot la :\r\n");
		}
		a = check_condition(arr[0].x, arr[0].y, arr[1].x, arr[1].y, arr[2].x, arr[2].y, arr[3].x, arr[3].y) && check_condition(arr[4].x, arr[4].y, arr[5].x, arr[5].y, arr[6].x, arr[6].y, arr[7].x, arr[7].y);
		if (!a) printf(" Toa do cua hinh chu nhat khong hop le. Xin kiem tra lai:");	
	} while (!a);
	//Tinh toa do tam cua hinh chu nhat thu 1.
	for (int i = 0; i < 4; i++)
	{
		X1 += arr[i].x;
		Y1 += arr[i].y;
	}
	//Tinh toa do tam cua hinh chu nhat thu 2.
	for (int i = 4; i < 8; i++)
	{
		X2 += arr[i].x;
		Y2 += arr[i].y;
	}
	float tana = (float)(Y2 - Y1) / (X2 - X1);
	float y0 = (float)(Y1 - tana * X1);
	printf("Phuong trinh duong thang la: y=%2.2f*x+%2.2f", tana, y0);
}
int check_condition(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4)
{
	float tana = (float)((y4 - y3) / (x4 - x3));
	float tanb = (float)((y2 - y1) / (x2 - x1));
	int temp1 = (x3 - x2) * (x2 - x1);
	int temp2 = (y3 - y2) * (y2 - y1);
	if (tana == tanb && temp1 + temp2 == 0) return 1;
	else return 0;
}