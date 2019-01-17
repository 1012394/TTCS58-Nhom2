#include"Header.h"

int main()
{
	int a[MAX][MAX] = { 0 }, n = 0;
	Nhap(a,n);
	docFile(a, n);
	Prim(a, n);
	system("pause");
}