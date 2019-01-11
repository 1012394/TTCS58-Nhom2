#include<iostream>
using namespace std;
#include<string>
#include<conio.h>
#include <fstream>
#include<Windows.h>
class LICH
{
	int ngay, thang, nam, weekday;
public:
	LICH() :ngay(9), thang(9), nam(2019) {};
	void Nhap();
	int a[48] = { 0 };
	bool kiemTraNamNhuan();
	int tinhSoNgayCuaThang();
	void taoLich();
	void Xuat();
	void Move();
	void docFile();
	
};
int Zeller(int,int,int);
struct GHICHU 
{
	int _ngay, _thang, _nam;
	string ghichu;
		
};
