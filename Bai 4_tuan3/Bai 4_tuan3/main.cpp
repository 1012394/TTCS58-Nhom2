#include"Header.h"

int main()
{
	int a[MAX][MAX], n = 0;
	docFile(a, n);
	Prim(a, n);
	system("pause");
}