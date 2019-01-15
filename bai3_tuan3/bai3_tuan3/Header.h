#include<iostream>
using namespace std;
#include<vector>
#include<fstream>
#include<string>

class KHACHHANG
{
	string makh;
	string tenkh;
	long int sodu;
public:
	KHACHHANG(): makh("kh1"), tenkh("khach hang a"), sodu(50000){};
	string getMaKH();
	string getTenKH();
	void setSoDu(long int);
	long int getSoDu();
	void docFile();
	void ghiFile();
	void Them();
	void Xuat();

};
class GIAODICH {
	string makh;
	bool loaigd; //1:gui 0: rut tien
	long int luongtien;
public:
	string getMaKH();
	int getLoaiGD();
	long int getLuongTien();
	void setMaKH(string);
	void setLoaiGD(bool);
	void setLuongTien(long int);
	bool giaoDich(string,int,int);
	void ghiFile();
	
};
void saoKe(string);
void menu();
extern vector<KHACHHANG> dskh;
extern vector<GIAODICH> dsgd;
