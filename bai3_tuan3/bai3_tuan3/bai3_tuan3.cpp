#include"Header.h"

vector<KHACHHANG> dskh;
vector<GIAODICH> dsgd;
string KHACHHANG::getMaKH()
{
	return this->makh;
}
string KHACHHANG::getTenKH()
{
	return this->tenkh;
}
long int KHACHHANG::getSoDu()
{
	return this->sodu;
}
void KHACHHANG::setSoDu(long int sotien)
{
	sodu = sotien;
}
string GIAODICH::getMaKH()
{
	return this->makh;
}
int GIAODICH::getLoaiGD()
{
	return this->loaigd;
}
long int GIAODICH::getLuongTien()
{
	return this->luongtien;
}
void GIAODICH::setMaKH(string _makh)
{
	this->makh = _makh;
}
void GIAODICH::setLoaiGD(bool _loaigd)
{
	this->loaigd = _loaigd;
}
void GIAODICH::setLuongTien(long int _luongtien)
{
	this->luongtien = _luongtien;
}

void KHACHHANG::Them()
{
	fstream f;
	f.open("customer.dat", ios::in|ios::out | ios::binary);
	char luachon;
	do{
		cout << "Ban muon them khach hang? (y/n)";
		cin >> luachon;
		cin.ignore();
		if (luachon == 'y')
		{	
			cout << "Nhap vao ma kh:";
			cin >> makh;
			cin.ignore();
			cout << "nhap ten kh:";
			getline(cin, tenkh);
			
			f.seekp(0, 2);
			f.write(reinterpret_cast<char *>(this), sizeof(KHACHHANG));
		}
		dskh.push_back(*this);
	} while (luachon == 'y');
	
}

void KHACHHANG::ghiFile()
{
	fstream f;
	f.open("customer.dat", ios::out | ios::binary);

	for (int i = 0; i < dskh.size(); i++)
	{
		
		f.write(reinterpret_cast<char *>(&dskh[i]), sizeof(KHACHHANG));
	}
}
void KHACHHANG::docFile()
{
	fstream f;
	f.open("customer.dat", ios::in | ios::binary);
	if (!f.is_open())
		cout << "ko mo dc file";
	KHACHHANG *kh= new KHACHHANG;
	while (!f.eof())
	{
		f.read(reinterpret_cast<char*>(kh), sizeof(KHACHHANG));
		if (!f.eof())
		{
			dskh.push_back(*kh);
		}
	}
	f.close();
}

void KHACHHANG::Xuat()
{
	cout << "makh\t\ttenkh\t\tsotien" << endl;
	for (int i = 0; i < dskh.size(); i++)
	{
		
		cout << dskh[i].makh <<"\t\t" << dskh[i].tenkh <<"\t\t" << dskh[i].sodu << endl;
	}
}
bool GIAODICH::giaoDich(string _makh, int _luongtien,int _loaigd)
{
	if (_loaigd ==1)
	{
		
		for (int i = 0; i < dskh.size(); i++)
		{
			if (dskh[i].getMaKH() == _makh)
			{
				//cout << "loai gd" << _loaigd;
				dskh[i].setSoDu(dskh[i].getSoDu() + _luongtien);
				
				return 1;
			}
		}
		return 0;
	}
	else
	{
		for (int i = 0; i < dskh.size(); i++)
		{
			if (dskh[i].getMaKH() == _makh)
			{
				if (dskh[i].getSoDu() < _luongtien)
				{
					cout << "so tien khong du de rut!" << endl;
					return 0;
				}
				else
				{
					dskh[i].setSoDu(dskh[i].getSoDu() - _luongtien);
					
					return 1;
				}
			}
		}
		return 0;
	}
}
void GIAODICH::ghiFile()
{	
	dsgd.push_back(*this);
	fstream f;
	f.open("Tran.dat",ios::binary|ios::out|ios::in);
	if (!f.is_open()) {
		cout << "khong mo duoc file";
		return;
	}
	
	f.seekp(0,2); //0: dich 0 byte. 2: vi tri cuoi file
	f.write(reinterpret_cast<char *>(this), sizeof(GIAODICH));
	f.close();
}

void saoKe(string makh)
{
	vector<GIAODICH> dsgd1;
	fstream f;
	f.open("Tran.dat", ios::in | ios::binary);
	GIAODICH *gd = new GIAODICH() ;
	while (!f.eof())
	{
		f.read(reinterpret_cast<char *>(gd), sizeof(GIAODICH));
		if (!f.eof())
		{
			dsgd1.push_back(*gd);
		}
	}
	

	cout << endl << "Danh sach cac giao dich khach hang da thuc hien:" << endl;
	bool flag = 0;
	for (int i = 0; i < dsgd1.size(); i++)
	{
		
		if (dsgd1[i].getMaKH() == makh)
		{
			cout <<"makh:" <<dsgd1[i].getMaKH() << endl;
			cout << "loai giao dich: ";
			if (dsgd1[i].getLoaiGD() == 1) cout << "gui tien"<<endl;
			else cout << "rut tien" << endl;
			cout << "so tien: " << dsgd1[i].getLuongTien() << endl;
			flag = 1;
		}
	}
	if (flag == 0)
		cout << endl << "Khong co thong tin giao dich cua khach hang " << makh << endl;
	
}

void menu()
{
	cout << "\n\n=========================================" << endl;
	cout << "Lua chon chuc nang:" << endl;
	cout << "1. Them KH" << endl;
	cout << "2. gui tien" << endl;
	cout << "3. Rut tien" << endl;
	cout << "4. In danh sach KH" << endl;
	cout << "5. sao ke" << endl;
	cout << "6. Ket thuc" << endl;
	cout << "=========================================" << endl;
	int luachon;
	cin >> luachon;
	cin.ignore();
	cout << "=========================================" << endl;
	GIAODICH gd;
	KHACHHANG kh;

	switch (luachon)
	{
	case 1:
	{
		
		kh.Them();
		menu();
		break;
	}
	case 2:
	{
		
		string makh;
		long int luongtien;
		cout << "Nhap vao ma kh: ";
		cin >> makh;
		cout <<endl << "Nhập số tiền muốn gửi: ";
		cin >> luongtien;
		int s = gd.giaoDich(makh, luongtien, 1);
		if (s == 1) {
			cout << endl << "giao dich thanh cong" << endl;
			gd.setMaKH(makh);
			gd.setLoaiGD(1);
			gd.setLuongTien(luongtien);
			
			kh.ghiFile();
			gd.ghiFile();
		}
		else cout << endl << "giao dich that bai" << endl;
		menu();
		break;
	}
	case 3:
	{
		string makh;
		long int luongtien;
		cout << "Nhap vao ma kh: ";
		cin >> makh;
		cout << endl << "Nhap so tien muon rut: ";
		cin >> luongtien;
		int s = gd.giaoDich(makh, luongtien, 0);
		if (s == 1) {
			cout << endl << "giao dich thanh cong" << endl;
			gd.setMaKH(makh);
			gd.setLoaiGD(1);
			gd.setLuongTien(luongtien);

			kh.ghiFile();
			gd.ghiFile();
		}
		else cout << endl << "giao dich that bai" << endl;
		menu();
		break;
	}
	case 4:
	{
		kh.Xuat();
		menu();
		break;
	}
	case 5:
	{
		string makh;
		cout << endl << "nhap vao ma kh muon sao ke: ";
		cin >> makh;
		saoKe(makh);
		menu();
		break;
	}
	case 6:
	{
		return;
	}
	default:
		break;
	}

}