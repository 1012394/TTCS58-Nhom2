#include"Header.h"
//lay thang
GHICHU g[31];
void LICH::Nhap()
{
	cout << "Nhap thang, nam:";
	cin >> thang >> nam;
}

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

//input: nam
//output: 1: nam nhuan 0: ko nhuan
bool LICH::kiemTraNamNhuan()
{
	if ((nam % 4) ||(nam %100 ==0) && (nam % 400)) return 0;
	else return 0;
}

//input: thang
//output :tinh so ngay trong 1 thang
int LICH::tinhSoNgayCuaThang()
{
	if (thang == 2) return (28+kiemTraNamNhuan());
	else return 31 - (thang-1) % 7 % 2;
}
void LICH::taoLich()
{
	
	//thubatdau = 0: thu 7, 1: chu nhat
	int thubatdau = Zeller(1,thang,nam);
	int k = 1;
	
	//gan gia tri ngay cho mang ngay bat dau tu vi tri cua thubatdau -1 do luc in ra lich bat dau tu chu nhat ;
	for (int i = thubatdau+6; i <thubatdau + tinhSoNgayCuaThang()+6; i++)
	{
		
		a[i] = k;
		k++;
		
	}
	
}
//input: ghichu, mang cac ngay trong thang, thang,nam
//output: xuat lich
void LICH::Xuat()
{
	//system("color 17");				//man hinh blue chu trang neu can;
	cout << endl << "----------------------------------------------------" << endl;
	string b[] = { "Jannuary","February","March","April","May","June","July","August","September","October","November","December" };
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE);	//doi mau chu xanh
	cout << "\t\t" << b[thang - 1] << " , " << nam << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); //reset mau
	cout << "----------------------------------------------------" << endl;
	cout << "S	M	T	W	T	F	S" << endl;

	for (int i = 0; i < 48; i++)
	{
		//neu trung ngay thang nam voi ghi chu thi cho ngay do mau do
		for (int j = 0; j < 31; j++)
		{
			if (g[j]._ngay == a[i] && g[j]._thang == thang && g[j]._nam == nam &&g[j]._ngay != 0)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
				break;
			}
		}

		if (i % 7 == 0) cout << endl;	// in tuan tiep theo

		if (a[i] == 0) cout << "\t";
		else if (a[i] < 10)
		{

			cout << "0" << a[i] << "\t";
		}

		else
		{

			cout << a[i] << "\t";

		}
		//reset lai mau trang cho ngay tiep theo
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	}
	cout << endl;
	cout << "----------------------------------------------------" << endl;
}


//input: ki tu  tu ban phim
//output: mui ten : thang tiep theo hoac thang truoc, 's': xem ghi chu
void LICH::Move()
{
	while (1)
	{
		char x = _getch();
		if (x == 's')
		{
			for (int j = 0; j < 31; j++)
			{
				if (g[j]._thang == thang && g[j]._nam == nam)
				{
					cout << endl << g[j]._ngay << "-" << g[j]._thang << "-" << g[j]._nam << ": " << g[j].ghichu << endl;
				}
			}
		}
		if (x == -32)
		{
			x = _getch();
			if (x == 75)//ki tu mui ten trai co ma ASCII la 75
			{
				for (int i = 0; i < 48; i++)
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
			if (x == 77)//ma mui ten phai
			{
				for (int i = 0; i < 48; i++)
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
//input: file input
//output: luu mang ghi chu
void LICH::docFile()
{
	
	fstream f;
	string s;
	f.open("input.txt",ios::in);
	int j = 0;
	while (!f.eof())
	{
		//moi dong trong file la 1 chuoi
		getline(f, s);
		int flag = 0, k = 1;	
		//doc het chieu dai cua moi chuoi
		for (int i = 0; i < s.length()+1; i++)
		{
			//truoc dau - dau tien la ngay; truoc dau - thu 2 la thang
			if (s[i] == '-')
			{
				if (k == 1) g[j]._ngay = stoi(s.substr(0, i));
				if (k == 2) g[j]._thang = stoi(s.substr(flag + 1, i - flag - 1));		
				k++;
				flag = i;
			}
			//tu flag den truoc dau : la nam
			if (s[i] == ':')
			{
				g[j]._nam=stoi(s.substr(flag + 1, i -flag- 1));
				flag = i;
			}
			
			if (s[i] == s[s.length()])
			{
				g[j].ghichu = s.substr(flag + 1, i - 1);
			}
		}
		j++;
	}
	f.close();
	
}
