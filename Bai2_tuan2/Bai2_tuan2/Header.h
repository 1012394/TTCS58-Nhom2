#include<iostream>
using namespace std;
#include<string>
#include<conio.h>
#include <fstream>
class LICH
{
	int ngay, thang, nam, weekday;
public:
	LICH() :ngay(8), thang(1), nam(2019) {};
	void Nhap();
	//void setNgay(int);
	//void setThang(int);
	//void setNam(int);
	int a[42] = { 0 };
	/*int getNgay();
	int getThang();
	int getTheKy();
	int getNam();*/
	
	bool kiemTraNamNhuan();
	int tinhSoNgayCuaThang();
	void taoLich();
	void Xuat();
	void Move();
	void ghichu();
};
int Zeller(int,int,int,int);

