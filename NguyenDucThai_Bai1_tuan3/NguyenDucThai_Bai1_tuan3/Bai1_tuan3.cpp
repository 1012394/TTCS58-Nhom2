#include"Header.h"

/*ham xuat ra n so ngau nhien tu 1 den m (n<m)
INPUT: so lon nhat m
OUTPUT: n so ngau nhien tu 1 den m
*/
void xuatDaySoNN()
{
	int m =0;
	cout << "Nhap vao so lon nhat cua day: "  << endl;
	cin >> m;
	int n = rand() % (m - 2) + 1;
	int a[100];
	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % (m - 1) + 1;
	}
	cout << "Day "<<n<<" so ngau nhien tu 1 den " << m << ": ";
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
}