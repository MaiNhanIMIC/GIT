//Chương trình nhập vào tọa độ 4 điểm của 2 hình chữ nhật.
//Viêt chương trình tìm phương trình đường thẳng y = ax + b.Sao cho chia 2 hình chữ nhật bằng 2 phần có diện tích bằng nhau

#include<stdio.h>
#include<math.h>
#pragma pack(1)
#pragma pack(show)

typedef struct {
	float x;
	float y;
}Diem;

typedef struct {
	Diem A;
	Diem B;
	Diem C;
	Diem D;
}HinhChuNhat;

void nhapdiem(Diem*);
void nhaphinhchunhat(HinhChuNhat*);
void xuathinhchunhat(HinhChuNhat);
Diem TrongTamHinhChuNhat(HinhChuNhat);
float DoDai2Diem(Diem, Diem);

int main()
{
	HinhChuNhat h1, h2;
	nhaphinhchunhat(&h1);
	nhaphinhchunhat(&h2);
	xuathinhchunhat(h1);
	xuathinhchunhat(h2);
	Diem x1 = TrongTamHinhChuNhat(h1);
	Diem x2 = TrongTamHinhChuNhat(h2);
	printf("Phuong trinh duong thang can tim co dang %.2f = a%.2f + b\r\n", (x1.x-x2.x), (x1.y-x2.y));
	return 0;
}

void nhapdiem(Diem* d)
{
	printf("nhap toa do x: \r\n");
	scanf("%f", &d->x);
	printf("nhap toa do y: \r\n");
	scanf("%f", &d->y);
}


void nhaphinhchunhat(HinhChuNhat* h)
{
	printf("Toa do dinh A: \r\n");
	nhapdiem(&h->A);
	printf("Toa do dinh B: \r\n");
	nhapdiem(&h->B);
	printf("Toa do dinh C: \r\n");
	nhapdiem(&h->C);
	printf("Toa do dinh D: \r\n");
	nhapdiem(&h->D);
}

void xuathinhchunhat(HinhChuNhat h)
{
	printf("Toa do 4 dinh hinh chu nhat da nhap la: \r\n");
	printf("Dinh A: %.2f %.2f\r\n", h.A.x, h.A.y);
	printf("Dinh B: %.2f %.2f\r\n", h.B.x, h.B.y);
	printf("Dinh C: %.2f %.2f\r\n", h.C.x, h.C.y);
	printf("Dinh D: %.2f %.2f\r\n", h.D.x, h.D.y);
}

float DoDai2Diem(Diem a, Diem b)
{
	float length = sqrt(pow((b.x - a.x), 2) + pow((b.y - a.y), 2));
	return length;
}

Diem TrongTamHinhChuNhat(HinhChuNhat h)
{
	float AB = DoDai2Diem(h.A, h.B);
	float BC = DoDai2Diem(h.B, h.C);
	float AC = sqrt(pow(AB, 2) + pow(BC, 2));
	float OA = AC / 2;
	Diem TamO;
	TamO.x = OA + h.A.x;
	TamO.y = OA + h.A.y;
	printf("Toa do tam O hinh chu nhat la: %.2f %.2f\r\n",TamO.x,TamO.y);
	return TamO;
}
