#include <iostream>
#include <windows.h>
#include <iomanip>
#include <fstream>
#include <conio.h>
#include <stdlib.h>
#include "config.h"
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
	dslop ds;
	ds.n = 3;
	ds.lop = new Lop[ds.n];
	PTRMH dsmh;
	loadWork(ds, "D15CQPU01.txt", dsmh);
//	printStudentList(ds.lop[0].Firstsv);
	printSubjectList(dsmh);
//	Themlop(ds);
//	PrintClassList(ds);
	clearList(ds);
	system("pause");
	return 0;
}

// string::pop_back

