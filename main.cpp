#include <iostream>
#include <windows.h>
#include <iomanip>
#include <fstream>
#include <conio.h>
#include <stdlib.h>
#include <mylib.h>
#include "config.h"
#include "Mylib.h"
#include "Function_TTN.h"
using namespace std;
int main()
{
	dslop ds;
	ds.n = 3;
	ds.lop = new Lop[ds.n];
	PTRMH dsmh, result;
	PTRQ root = NULL;
	char *x = new char[100];
	int check, choice, choice1, choice2, choice3;
	Lop temp;
	sinhvien temp1;
	char cf;
//	int check;
//	while(1)
//	{
//		cout << "\t\tDANG NHAP" << endl;
//		cout << "\tNhap ten dang nhap: ";
//		check = NhapChuoi(mmh);
//		if(check == ESC)
//		{
//			cout << "Ban muon thoat chuong trinh?(y/n) ";
//			check = NhapChuoi(mmh);
//			if(check == ESC || mmh[0] == 'n')
//				continue;
//			if(mmh[0] == 'y')
//				break;
//		}
//		cout << "\tNhap mat khau: ";
//	}
//	cout << "Cam on ban da su dung phan mem!" << endl;
//	Sleep(2000);
//--------------------------------------------------------------------
//	DSSV dssv;
//	string ID, pass;
//	do
//	{
//		cout << "Nhap tai khoan: ";
//		cin >> ID;
//		cout << "Nhap mat khau: ";
//		cin >> pass;
//	}while(ID == "" || pass == "");char c;
	loadWork(ds, "D15CQPU01.txt", dsmh, root);
	check = DangNhap(ds);
	if(check == 0)
		cout << "Cam on ban da su dung chuong trinh!!" << endl;
	else if(check == 2)				//Giao vien
	{
		cout << "Dang nhap thanh cong ...!!" << endl;
		Sleep(2000);
		while(1)
		{
			choice = MenuDong(menuGV);
			Normal();
			system("cls");
			if(choice == 7 || choice == 0)
			{
				cout << "Cam on ban da sung dung chuong trinh!" << endl;
				break;
			}
			switch(choice)
			{
				case 1:						//Thao tac lop
					while(1)
					{
						choice1 = MenuDong(menu1_1);
						Normal();
						system("cls");
						if(choice1 == 0 || choice1 == 5)
							break;
						switch(choice1)
						{
							case 1:				//Them lop
								while(1)
								{
									cout << "Nhap ma lop muon them: ";
									check = NhapMa(x, 10);
									if(check == ESC)
									{
										check1:
										gotoxy(wherex(), wherey());
										xoadong(wherey(), 3);
										cout << "Ban muon quay lai menu?(y/n) ";
										check = NhapMa(x, 2);
										if(check == ESC)
											continue;
										else if(check == ENTER)
										{
											if(x[0] == 'y' || x[0] == 'Y')
												break;
											else if(x[0] == 'n' || x[0] == 'N')
												continue;
											else
											{
												cout << "Xac nhan khong phu hop!";          
												Sleep(1500);
												goto check1;
											}
										}
									}
									else if(check == ENTER)
									{
										//Code tim kiem kiem tra ma lop da ton tai hay chua
										temp.MALOP = x;
									}
									cout << "Nhap ten lop: ";
									check = NhapChuoi(x, 100);
									if(check == ESC)
									{
										check1:
										gotoxy(wherex(), wherey());
										xoadong(wherey(), 3);
										cout << "Ban muon quay lai menu?(y/n) ";
										check = NhapMa(x, 2);
										if(check == ESC)
											continue;
										else if(check == ENTER)
										{
											if(x[0] == 'y' || x[0] == 'Y')
												break;
											else if(x[0] == 'n' || x[0] == 'N')
												continue;
											else
											{
												cout << "Xac nhan khong phu hop!";          
												Sleep(1500);
												goto check1;
											}
										}
									}
									else 	//check = ENTER
										temp.TENLOP = x
								}
								break;
							case 2:				//Sua lop
								break;
							case 3:				//Xoa lop
								break;
							case 4:				//Xem danh sach lop
								break;
						}
					}
					break;
				case 2:						//Dieu chinh danh sach sinh vien
					break;
				case 3:						//Dieu chinh danh sach mon hoc
					break;
				case 4:						//Dieu chinh cau hoi thi trac nghiem
					break;
				case 5:						//Thi trac nghiem
					break;
				case 6:
					break;
			}
		}
	}
	else if(check == 1)				//Sinh vien
	{
		cout << "May muon thi khong?!" << endl;
	}
//	cout << ds.lop[0].Firstsv->Firstdiem->info.Mamh << endl;
//	cout << "Nhap ma mon hoc: ";
//	cin >> mmh;
//	viethoa(mmh);
//	result = searchMaMH(dsmh, mmh);
//	if(result == NULL)
//	{
//		cout << "Ma mon hoc khong dung!!" << endl;
//		Sleep(2000);
//		goto end;
//	}
//	printMarkSubject(ds.lop[0], result->info);
//	printStudentList(ds.lop[0].Firstsv);
//	printSubjectList(dsmh);
//	Themlop(ds);
//	PrintClassList(ds);
//	end:
	delete mmh;
	clearList(ds);
	system("pause");
	return 0;
}

// string::pop_back

