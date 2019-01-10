#include"Header.h"
//lay thang
void LICH::Nhap()
{
	cout << "Nhap thang, nam:";
	cin >> thang >> nam;
}
//void LICH::setNgay(int _ngay)
//{
//	
//	this->ngay = _ngay;
//}
//void LICH::setThang(int _thang)
//{
//	 this->thang = _thang;
//}
//void LICH::setNam(int _nam)
//{
//	 this->nam = _nam;
//}
//int LICH::getNgay()
//{
//	return ngay;
//}
//int LICH::getThang()
//{
//	if (thang < 3) return thang + 10;
//	else return thang - 2;
//}
//
////lay the ky
//int LICH::getTheKy()
//{
//	return nam / 100 ;
//}
//
////lay nam
//int LICH::getNam()
//{
//	return nam % 100;
//}
//cong thuc zeller
int Zeller(int ngay, int thang, int nam)
{
	if (thang == 1)
	{
		thang = 13;
		nam--;
	}
	if (thang == 2)
	{
		thang = 14;
		nam--;
	}
	int q = ngay;
	int m = thang;
	int k = nam % 100;
	int j = nam / 100;	//the ky
	int h = q + 13 * (m + 1) / 5 + k + k / 4 + j / 4 + 5 * j;
	h = h % 7;

	return h;

}


//xac dinh nam nhuan
bool LICH::kiemTraNamNhuan()
{
	if ((nam % 4 == 0 &&nam %100 !=0) || nam % 400) return 1;
	else return 0;
}

//tinh so ngay trong 1 thang
int LICH::tinhSoNgayCuaThang()
{
	if (thang == 2) return (28+kiemTraNamNhuan());
	else return 31 - (thang-1) % 7 % 2;
}
void LICH::taoLich()
{
	
	//thubatdau = 0: thu 7, 1: chu nhat
	int thubatdau = Zeller(1,thang,nam);
	
	//gan gia tri ngay cho mang ngay bat dau tu vi tri cua thubatdau -1 do luc in ra lich bat dau tu chu nhat ;
	for (int i = thubatdau-1; i <thubatdau + tinhSoNgayCuaThang()-1; i++)
	{
		a[i] = i -(thubatdau-1) +1;
	
	}
	
}

void LICH::Xuat()
{
	cout << "----------------------------------------------------------------" << endl;
	string b[] = { "Jannuary","February","March","April","May","June","July","August","September","October","November","December" };
	cout << endl << "nam la: " << nam;
	cout << "\t\t"<<b[thang-1]<<" , "<<nam<<endl;
	cout << "----------------------------------------------------------------" << endl;
	cout << "S	M	T	W	T	F	S" << endl;
	for (int i = 0; i < 42; i++)
	{
		
		
		if (i % 7 == 0) cout << endl;	// sang tuan tiep theo
		if (a[i] == 0) cout<<"\t";
		else if (a[i] < 10) cout << "0" << a[i]<<"\t";
		
		else cout << a[i]<<"\t";
	}
	cout << endl;
}

//input: ki tu mui ten tu ban phim
//output: thang tiep theo hoac thang truoc
void LICH::Move()
{
	while (1)
	{
		char x = _getch();
		if (x == -32)
		{
			x = _getch();
			if (x == 75)
			{
				for (int i = 0; i < 42; i++)
				{
					a[i] = 0;
				}
				thang -= 1;
				if (thang < 1)
				{
					thang = 12;
					nam = nam -1;
				}
				taoLich();
				Xuat();
			}
			if (x == 77)
			{
				for (int i = 0; i < 42; i++)
				{
					a[i] = 0;
				}
				thang += 1;
				if (thang > 12)
				{
					thang = 1;
					nam = nam +1;
				}
				taoLich();
				Xuat();
			}
		}

	}
}

//void LICH::ghichu()
//{
//	fstream f;
//	f.open("input.dat",ios::in| ios::binary);
//	if (f.is_open())
//	{
//		
//		f.read(reinterpret_cast<int>,1);
//		f.close();
//	}
//}