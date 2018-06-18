#include <iostream>
#include "config.h"
#include <string>
#include <windows.h>
#include "Mylib.h"
#include "Function_TTN.h"
using namespace std;
int main()
{
//	DSSV dssv;
//	string ID, pass;
//	do
//	{
//		cout << "Nhap tai khoan: ";
//		cin >> ID;
//		cout << "Nhap mat khau: ";
//		cin >> pass;
//	}while(ID == "" || pass == "");char c;
	dslop d;
	d.n = 10;
	d.lop = new Lop[d.n];
	Themlop(d);
	PrintClassList(d);
	delete(d.lop);
	system("pause");
	return 0;
}

// string::pop_back

