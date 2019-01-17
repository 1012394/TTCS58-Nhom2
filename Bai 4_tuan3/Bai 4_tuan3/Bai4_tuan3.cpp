#include"Header.h"

//xuat thong tin ma tran ra file
void Nhap(int a[MAX][MAX], int &n)
{

	fstream f;
	f.open("input.txt", ios::out);
	n = rand() % 7 + 3;
	f << n << endl;
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == j) a[i][j] = 0;
			else if (a[i][j] == 0 && a[j][i] != 0) a[i][j] = a[j][i];
			else a[i][j] =  rand() % 100 + 1;
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			f << a[i][j]<<" ";
		}
		f << endl;
	}
}
//doc du lieu tu file
void docFile(int a[MAX][MAX], int &n)
{
	fstream f;
	f.open("input.txt", ios::in);
	f >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			f >> a[i][j];
		}
	}
	f.close();
	
}

void ghiFile(CANH L[MAX], int n, int tong)
{
	fstream f;
	f.open("output.txt", ios::out);
	f << tong<<endl;
	for (int i = 0; i < n - 1; i++)
		f << L[i].x + 1 << " - " << L[i].y + 1<<endl;
	f.close();
}

/*input: ma tran trong so a, so luong phan tu n
output: Mang cac canh , tong trong so nho nhat
*/
void Prim(int a[MAX][MAX], int n)
{
	
	int D[MAX];//mang cac dinh
	CANH L[MAX];
	int min = 10000, dem = 0, sum = 0;
	//khoi tao cac dinh chua danh dau
	for (int i = 0; i < n; i++)
	{
		D[i] = 0;
	}
	//xuat phat tu dinh dau tien chon 1 canh co trong so be nhat lien ke
	for (int i = 1; i < n; i++)
	{

		if (min > a[0][i] && a[0][i] != 0)
		{
			min = a[0][i];
			L[0].y = i;

		}
	}
		L[0].x = 0;  //canh dau tien bat dau tu dinh 0
					 //danh dau 2 dinh 
		D[0] = 1;
		
		D[L[0].y] = 1;
		sum += min;
		dem++;	//so canh tim dc =1;
	
	//tim canh nho nhat cua do thi (canh do co 1 dinh chua danh dau va 1 dinh da danh dau)
	do {
		min = 10000;
		for (int i = 0; i < n ; i++)
		{
			if (D[i] == 1)
				for (int j = 0; j < n; j++)
				{
					if (a[i][j] > 0 && min > a[i][j] && D[j] == 0)
					{
						min = a[i][j];
						L[dem].x = i;
						L[dem].y = j;
					}
				}
		}
		
		sum += min;

		D[L[dem].y] = 1; //danh dau dinh y
		dem++;
	} while (dem < n - 1);	//trong khi so canh con be hon so dinh-1
	
	ghiFile(L, n, sum);
}