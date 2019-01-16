#include<iostream>
using namespace std;
#include<fstream>
#define MAX 100

struct CANH
{
	int x, y;	//2 dinh cua canh;
};

void docFile(int a[MAX][MAX], int&);
void ghiFile(CANH L[MAX], int, int);
void Prim(int a[MAX][MAX], int);

