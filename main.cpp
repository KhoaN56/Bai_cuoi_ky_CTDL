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
	ds.n = 5;
	ds.lop = new Lop[ds.n];
	PTRMH dsmh, result;
	PTRMH mh;
	PTRQ root = NULL, sq;
	PTRSV sv;
	PTRCT FirstMT = NULL;
//	Lop temp;
	loadWork(ds, "D15CQPU01.txt", dsmh, root, FirstMT);
//	printStudentList(ds.lop[0].Firstsv);
//	printClassList(ds);
//	system("pause");
//	system("cls");
//	cout << ds.n << endl;
//	cout << "Nhap ma lop them: ";
//	cin >> temp.MALOP;
//	cout << "Nhap ten lop: ";
//	cin >> temp.TENLOP;
//	addClass(ds, temp);
//	system("cls");
//	printClassList(ds);
//	removeAVLNode(root, 28);
//	removeAVLNode(root, 12);
//	removeAVLNode(root, 16);
//	removeAVLNode(root, 9);
//	removeAVLNode(root, 23);
//	removeAVLNode(root, 20);
//	removeAVLNode(root, 4);
//	removeAVLNode(root, 27);
//	removeAVLNode(root, 8);
//	removeAVLNode(root, 30);
//	Intrav(root, FirstMT);
//	cout << FirstMT->MAMH << endl;
//	for(int i = 0; i < FirstMT->info.n; ++i)
//		cout << FirstMT->info.id[i] << endl;
//	cout << FirstMT->next->MAMH << endl;
//	for(int i = 0; i < FirstMT->next->info.n; ++i)
//		cout << FirstMT->next->info.id[i] << endl;
//					char *rep;
//					int socauthi = 10;
//					int point = 0;
//					char *dapan;
//					char *check;
//					int *cauthi;
//					cauthi = generateTest(FirstMT->info, socauthi);
//					rep = printTest(root, cauthi, socauthi);
//					for(int i = 0; i < socauthi; ++i)
//					{
//						check = search(root, cauthi[i])->info.dapan;
//						if(check[0] == rep[i])
//							point++;
//					}
//					Normal();
//					system("cls");
//					cout << point << endl;
//					delete rep;
//					delete cauthi;
//	for(int i = 0; i < socauthi; ++i)
//		cout << dapan[i] << endl;
//									cout << point << endl;
//									delete dapan;
//									delete cauthi;
//	char *x = new char[100];
//	char *x1 = new char[100];
//
//	int check, check1, choice, choice1, choice2, choice3, ids;
//	Lop temp, *slop, *smh;
//	sinhvien temp_sv;
//	monhoc temp_mh;
//	cauhoi temp_ch;
//	char cf;
//	check = DangNhap(ds);
//	if(check == 0)
//		cout << "Cam on ban da su dung chuong trinh!!" << endl;
//	else if(check == 2)				//Giao vien
//	{
//		cout << "Dang nhap thanh cong ...!!" << endl;
//		Sleep(2000);
//		while(1)
//		{
//			choice = MenuDong(menuGV);
//			Normal();
//			system("cls");
//			if(choice == 6 || choice == 0)
//			{
//				cout << "Cam on ban da sung dung chuong trinh!" << endl;
//				break;
//			}
//			switch(choice)
//			{
//				case 1:						//Thao tac lop
//					while(1)
//					{
//						choice1 = MenuDong(menu1);
//						Normal();
//						system("cls");
//						if(choice1 == 0 || choice1 == 5)
//							break;
//						switch(choice1)
//						{
//							case 1:	
//								check1_1:			//Them lop
//								if (ds.n == MAXLOP)
//								{
//									cout << ER_FULL_LIST << endl;
//									Sleep(1500);
//									break;
//								}
//								while(1)
//								{
//									cout << "Nhap ma lop muon them: ";
//									check = NhapMa(x, 10);
//									viethoa(x);
//									if(check == ESC)
//									{
//										if (checkEsc()==CONTINUE)
//											continue;
//										if (checkEsc()==BREAK)
//											break;
//									}
//									else if(check == ENTER)
//									{
//										//Code tim kiem kiem tra ma lop da ton tai hay chua
//										slop=searchClass(ds, x);
//										if (slop==NULL)
//										{
//											strcpy(temp.MALOP,x);
//											cout << "Nhap ten lop: ";
//											check = NhapChuoi(x, 100);
//										}
//										else
//										{
//											cout<<"Ma lop da ton tai. Xin kiem tra lai!"<<endl;
//											goto check1_1;
//										}
//									}
//									if(check == ESC)
//									{
//										if (checkEsc()==CONTINUE)
//											continue;
//										if (checkEsc()==BREAK)
//											break;
//									}
//									else {
//										//check = ENTER
//										strcpy(temp.TENLOP,x);
//										cout<<"Them lop thanh cong"<<endl;
//										Sleep(1500);
//										break;
//									}
//								// ham them lop
//								
//								break;
//							case 2:				//Sua lop
//								while(1)
//								{	
//									checknull2:
//									//xoadong(wherey(),5);
//									cout << "Nhap ma lop muon sua: ";
//									check = NhapMa(x, 10);
//									viethoa(x);
//									if(check == ESC)
//									{
//										if (checkEsc()==CONTINUE)
//											continue;
//										if (checkEsc()==BREAK)
//											break;
//									}
//									else if(check == ENTER)
//									{
//										//Code tim kiem kiem tra ma lop da ton tai hay chua
//										// tim kiem ma lop
//										slop=searchClass(ds,x);
//										if (slop!=NULL)
//										{
//											strcpy(temp.MALOP,x);
//											cout << "Nhap ten lop: ";
//											check = NhapChuoi(x, 100);
//											strcpy(temp.TENLOP,x);
//											BaoLoi("Sua lop thanh cong");
//											break;
//										}
//										else 
//										{
//											cout<<"Ma lop khong ton tai. Xin kiem tra lai!";
//											goto checknull2;
//										}
//									}
//									if(check == ESC)
//									{
//										if (checkEsc()==CONTINUE)
//											continue;
//										if (checkEsc()==BREAK)
//											break;
//									}
//									else 	//check = ENTER
//										strcpy(temp.TENLOP,x);	
//								}
//								break;
//							case 3:				//Xoa lop
//								while(1)
//								{
//									checknull3:
//									//xoadong(wherey(),5);
//									cout << "Nhap ma lop muon xoa: ";
//									check = NhapMa(x, 10);
//									viethoa(x);
//									if(check == ESC)
//									{
//										if (checkEsc()==CONTINUE)
//											continue;
//										if (checkEsc()==BREAK)
//											break;
//									}
//									else if(check == ENTER)
//									{
//										//Code tim kiem kiem tra ma lop da ton tai hay chua
//										// tim kiem ma lop
//										slop=searchClass(ds,x);
//										if (slop!=NULL)
//										{
//											cout<<"Ban co muon xoa tat ca sinh vien thuoc lop nay khong?(y/n) ";
//											check=NhapMa(x,1);
//											if (x[0]=='y'||x[0]=='Y')
//												//xoa sinh vien
//												clearList(slop->Firstsv);
//											else if (x[0]=='n'||x[0]=='N')
//												break;
//											else
//											{
//												cout<<"Xac nhan khong phu hop."<<endl;
//												goto checknull3;
//											}
//										}
//										else 
//										{
//											cout<<"Ma lop khong ton tai. Xin kiem tra lai!"<<endl;
//											goto checknull3;
//										}
//									}
//								}
//								break;
//							case 4:				//Xem danh sach lop
//								printClassList(ds);
//								system("pause");
//								break;
//						}
//						}
//					}
//					break;
//				case 2:						//Dieu chinh danh sach sinh vien
//					while(1)
//					{
//						choice2 = MenuDong(menu2);
//						Normal();
//						system("cls");
//						if(choice2 == 0 || choice2 == 5)
//							break;
//						switch(choice2)
//						{
//							case 1:				//Them sinh vien
//								while(1)
//								{
//									checknull2_1:
//									//xoadong(wherey(),5);
//									cout<<" Nhap ma lop: ";
//									check= NhapMa(x1, 10);
//									viethoa(x);
//									if(check == ESC)
//									{
//										if (checkEsc()==CONTINUE)
//											continue;
//										if (checkEsc()==BREAK)
//											break;
//									}
//									else if(check == ENTER)
//									{
//										//Code tim kiem kiem tra ma lop, ma sv da ton tai hay chua
//										slop=searchClass(ds,x1);
//										if (slop==NULL)
//										{
//											cout<<"Ma lop khong ton tai, xin liem tra lai!"<<endl;
//											goto checknull2_1;
//										}
//										else 
//										{	
//											cout<<"Nhap ma sinh vien: ";
//											check=NhapMa(x, 10);
//											sv=searchStudent(slop->Firstsv, x);
//											if (sv==NULL)
//											{
//												strcpy(temp_sv.MASV, x);
//												cout<<"Nhap ho sinh vien: ";
//												check=NhapChuoi(x, 51);
//												if(check == ESC)
//												{
//														if (checkEsc()==CONTINUE)
//															continue;
//														if (checkEsc()==BREAK)
//															break;
//												}
//												else if (check==ENTER) 	//check = ENTER
//														strcpy(temp_sv.HO,x);	
//												
//												cout<<"Nhap ten sinh vien: ";
//												check=NhapChuoi(x,11);
//												if(check == ESC)
//												{
//														if (checkEsc()==CONTINUE)
//															continue;
//														if (checkEsc()==BREAK)
//															break;
//												}
//												else if (check==ENTER) 	//check = ENTER
//														strcpy(temp_sv.HO,x);	
//												
//												cout<<"Nhap pass sinh vien: ";
//												check=NhapMa(x, 8);
//												if(check == ESC)
//												{
//														if (checkEsc()==CONTINUE)
//															continue;
//														if (checkEsc()==BREAK)
//															break;
//												}
//												else if (check==ENTER) 	//check = ENTER
//														strcpy(temp_sv.password,x);	
//												
//												check_phai1:// nhap phai
//												xoadong(wherey()+1,5);
//												cout<<"Nhap phai sinh vien (Nam/Nu): ";
//												check=NhapChuoi(x,3);
//												viethoa(x);
//												if (stricmp(x,"NAM")!=0)
//												{
//													if(stricmp(x,"NU")!=0)
//													{
//														BaoLoi("Gia tri dang nhap chi chua NAM hoac NU. Xin kiem tra lai");
//														goto check_phai1;
//													}
//												}
//												if(check == ESC)
//												{
//														if (checkEsc()==CONTINUE)
//															continue;
//														else
//															break;
//												}
//												else if (check==ENTER) 	//check = ENTER
//													strcpy(temp_sv.PHAI,x);	
//												
//												insertOrder(slop->Firstsv,temp_sv);
//												cout<<"Them sinh vien thanh cong"<<endl;
//											}
//											else
//											{
//												cout<<"Ma sinh vien da ton tai, xin kiem tra lai!"<<endl;
//												goto checknull2_1;
//											}
//										}
//									}
//								}
//								break;
//							case 2:				//Sua sinh vien
//								while(1)
//								{	
//									checknull2_2:
//									//xoadong(wherey(),5);
//									cout << "Nhap ma lop: ";
//									check = NhapMa(x, 10);
//									viethoa(x);
//									if(check == ESC)
//									{
//										if (checkEsc()==CONTINUE)
//											continue;
//										if (checkEsc()==BREAK)
//											break;
//									}
//									else if(check == ENTER)
//									{
//										//Code tim kiem kiem tra ma lop da ton tai hay chua
//										// tim kiem ma lop
//										slop=searchClass(ds,x);
//										if (x==NULL)
//										{
//											cout<<"Ma lop khong ton tai. Xin kiem tra lai!";
//											goto checknull2_2;
//										}
//										else 
//										{
//											cout<<"Nhap ma sinh vien muon sua: ";
//											check=NhapMa(x, 10);
//											sv=searchStudent(slop->Firstsv, x);
//											if (sv!=NULL)
//											{
//												strcpy(temp_sv.MASV, x);
//												cout<<"Nhap ho sinh vien: ";
//												check=NhapChuoi(x,51);
//												if(check == ESC)
//												{
//													check = checkEsc();
//													if (check==CONTINUE)
//														continue;
//													if (check==BREAK)
//														break;
//												}
//												else if (check==ENTER) 	//check = ENTER
//														strcpy(temp_sv.HO,x);	
//												
//												cout<<"Nhap ten sinh vien: ";
//												check=NhapChuoi(x,11);
//												if(check == ESC)
//												{
//													check = checkEsc();
//													if (check==CONTINUE)
//														continue;
//													if (check==BREAK)
//														break;
//												}
//												else if (check==ENTER) 	//check = ENTER
//														strcpy(temp_sv.HO,x);	
//												
//												cout<<"Nhap pass sinh vien: ";
//												check=NhapMa(x, 8);
//												if(check == ESC)
//												{
//													check = checkEsc();
//													if (check==CONTINUE)
//														continue;
//													if (check==BREAK)
//														break;
//												}
//												else if (check==ENTER) 	//check = ENTER
//														strcpy(temp_sv.password,x);	
//												
//												check_phai2:// nhap phai
//												xoadong(wherey(),5);
//												cout<<"Nhap phai sinh vien (Nam/Nu): ";
//												check=NhapChuoi(x,3);
//												viethoa(x);
//												if (stricmp(x,"NAM")!=0 ||stricmp(x,"NU")!=0)
//												{
//													BaoLoi("Gia tri dang nhap chi chua NAM hoac NU. Xin kiem tra lai");
//													goto check_phai2;
//												}
//												if(check == ESC)
//												{
//													check = checkEsc();
//													if (check==CONTINUE)
//														continue;
//													if (check==BREAK)
//														break;
//												}
//												else if (check==ENTER) 	//check = ENTER
//														strcpy(temp_sv.PHAI,x);	
//												cout<<"Ban co muon luu thong tin sinh vien khong?(y/n)";
//												check=NhapMa(x,2);
//												if (x[0]=='y'||x[0]=='Y'){
//													sv->info=temp_sv;
//												}
//												else if (x[0]=='n'||x[0]=='N')
//												{
//													break;
//												}
//												else 
//												{
//													cout<<"Xac nhan khong phu hop"<<endl;
//													goto checknull2_2;
//												}
//											}
//											else
//											{
//												cout<<"Ma sinh vien nay khong ton tai. Xin kiem tra lai"<<endl;
//												goto checknull2_2;
//											}	
//										}
//									}
//								}
//								break;
//							case 3:				//Xoa sinh vien
//								while(1)
//								{	
//									checknull2_3:
//								//	xoadong(wherey(),5);
//									cout << "Nhap ma lop: ";
//									check = NhapMa(x, 10);
//									viethoa(x);
//									if(check == ESC)
//									{
//										check = checkEsc();
//										if (check==CONTINUE)
//											continue;
//										if (check==BREAK)
//											break;
//									}
//									else if(check == ENTER)
//									{
//										//Code tim kiem kiem tra ma lop da ton tai hay chua
//										// tim kiem ma lop
//										slop=searchClass(ds,x);
//										if (x==NULL)
//										{
//											cout<<"Ma lop khong ton tai. Xin kiem tra lai!";
//											goto checknull2_3;
//										}
//										else 
//										{
//											cout<<"Nhap ma sinh vien muon xoa: ";
//											check=NhapMa(x, 10);
//											deleteStudent(slop->Firstsv,x);
//											if (deleteStudent(slop->Firstsv,x)==UNDONE)
//												break;
//											else if (deleteStudent(slop->Firstsv,x)==TRUE)
//												cout<<"Ban da xoa thanh cong";
//											else if (deleteStudent(slop->Firstsv,x)==FALSE)
//											{
//												cout<<"Khong tim thay ma sinh vien. Xin kiem tra lai"<<endl;	
//												goto checknull2_3;
//											}
//										}
//									}
//								}
//								break;
//							case 4:				//Xem danh sach sinh vien
//									checknull2_4:
//								//	xoadong(wherey(),5);
//									cout << "Nhap ma lop: ";
//									check = NhapMa(x, 10);
//									viethoa(x);
//									if(check == ESC)
//									{
//										check = checkEsc();
//										if (check==CONTINUE)
//											continue;
//										if (check==BREAK)
//											break;
//									}
//									else if(check == ENTER)
//									{
//										//Code tim kiem kiem tra ma lop da ton tai hay chua
//										// tim kiem ma lop
//										slop=searchClass(ds,x);
//										if (x==NULL)
//										{
//											cout<<"Ma lop khong ton tai. Xin kiem tra lai!";
//											goto checknull2_4;
//										}
//										else 
//										{
//											printStudentList(slop->Firstsv);
//											system("pause");
//											break;
//										}
//									}
//						}
//					}
//						break;
//				case 3:						//Dieu chinh danh sach mon hoc
//					while(1)
//					{
//						choice3 = MenuDong(menu3);
//						Normal();
//						system("cls");
//						if(choice3 == 0 || choice3 == 5)
//							break;
//						switch(choice3)
//						{
//							case 1:	
//								check3_1:			//Them mon hoc
//								while(1)
//								{
//									cout << "Nhap ma mon hoc muon them: ";
//									check = NhapMa(x, 10);
//									viethoa(x);
//									if(check == ESC)
//									{
//										check = checkEsc();
//										if (check==CONTINUE)
//											continue;
//										if (check==BREAK)
//											break;
//									}
//									else if(check == ENTER)
//									{
//										//Code tim kiem kiem tra ma lop da ton tai hay chua
//										mh=searchMaMH(dsmh,x);
//										if (mh==NULL)
//										{
//											strcpy(temp_mh.MAMH,x);
//											cout << "Nhap ten mon hoc: ";
//											check = NhapChuoi(x, 100);
//											if(check == ESC)
//											{
//												check = checkEsc();
//												if (check==CONTINUE)
//													continue;
//												if (check==BREAK)
//													break;
//											}
//											else if(check == ENTER)
//											{
//												strcpy(temp_mh.TENMH,x);
//												insertFirst(dsmh,temp_mh);
//											}
//										}
//										else
//										{
//											cout<<"Ma mon hoc da ton tai. Xin kiem tra lai!"<<endl;
//											goto check3_1;
//										}
//									}
//								}
//								break;
//							case 2:				//Sua mon hoc
//								while(1)
//								{	
//									checknull3_2:
//									xoadong(wherey(),5);
//									cout << "Nhap ma mon hoc muon sua: ";
//									check = NhapMa(x, 10);
//									viethoa(x);
//									if(check == ESC)
//									{
//										check = checkEsc();
//										if (check==CONTINUE)
//											continue;
//										if (check==BREAK)
//											break;
//									}
//									else if(check == ENTER)
//									{
//										//Code tim kiem kiem tra ma lop da ton tai hay chua
//										// tim kiem ma lop
//										mh=searchMaMH(dsmh,x);
//										if (mh!=NULL)
//										{
//											
//											cout << "Nhap ten mon hoc: ";
//											check = NhapChuoi(x, 100);
//											strcpy(temp_mh.TENMH, x);
//											cout<<"Ban co muon luu thong tin mon hoc khong?(y/n)";
//												check=NhapMa(x,2);
//												if (x[0]=='y'||x[0]=='Y')
//												{
//													mh->info=temp_mh;
//												}
//												else if (x[0]=='n'||x[0]=='N')
//												{
//													break;
//												}
//												else 
//												{
//													cout<<"Xac nhan khong phu hop"<<endl;
//													goto checknull3_2;
//												}
//											
//										}
//										else 
//										{
//											cout<<"Ma mon hoc khong ton tai. Xin kiem tra lai!";
//											goto checknull3_2;
//										}
//									}
//								}
//								break;
//							case 3:				//Xoa mon hoc
//								while(1)
//								{
//									checknull3_3:
//									xoadong(wherey(),5);
//									cout << "Nhap ma mon hoc muon xoa: ";
//									check = NhapMa(x, 10);
//									viethoa(x);
//									if(check == ESC)
//									{
//										check = checkEsc();
//										if (check==CONTINUE)
//											continue;
//										if (check==BREAK)
//											break;
//									}
//									else if(check == ENTER)
//									{
//										//Code tim kiem kiem tra ma lop da ton tai hay chua
//										// tim kiem ma lop
//										mh=searchMaMH(dsmh,x);
//										if (mh!=NULL)
//										{
//											cout<<"Ban co muon xoa mon hoc nay khong?(y/n) ";
//											check=NhapMa(x,2);
//											viethoa(x);
//											if (x[0]=='y'||x[0]=='Y')
//											{
//												if(deleteSubject(dsmh,x)==TRUE)
//													BaoLoi("xoa mon hoc thanh cong");
//												if(deleteSubject(dsmh,x)==FALSE)
//												BaoLoi("Ma mon hoc khong ton tai");
//												if(deleteSubject(dsmh,x)==UNDONE)
//												break;
//											}
//											else if (x[0]=='n'||x[0]=='N')
//												break;
//											else
//											{
//												cout<<"Xac nhan khong phu hop."<<endl;
//												goto checknull3;
//											}
//										}
//										
//									}
//								}
//								break;
//							case 4:				//Xem danh mon hoc
//								printClassList(ds);
//								break;
//						}
//					}
//				
//					break;
//				case 4:						//Dieu chinh cau hoi thi trac nghiem
//					while(1)
//					{
//						check1 = MenuDong(menu4);
//						Normal();
//						system("cls");
//						if(check1 == 4 || check1 == 0)
//							break;
//						switch(check1)
//						{
//							case 1:
//								createAVLTree(root);
//								break;
//							case 2:				//Sua cau hoi
//								while(1)
//								{	
//									checknull4_2:
//									xoadong(wherey(),5);
//									cout << "Nhap id cau hoi muon sua: ";
//									check = NhapMa(x, 10);
//									ids = atoi(x);
//									if(check == ESC)
//									{
//										check = checkEsc();
//										if (check==CONTINUE)
//											continue;
//										if (check==BREAK)
//											break;
//									}
//									else if(check == ENTER)
//									{
//										// tim kiem ma lop
//										sq = search(root, ids);
//										if (sq != NULL)
//										{
//											cout<<"Nhap noi dung cau hoi: ";
//												check=NhapChuoi(x, 51);
//												if(check == ESC)
//												{
//													check = checkEsc();
//													if (check==CONTINUE)
//														continue;
//													if (check==BREAK)
//														break;
//												}
//												else if (check==ENTER) 	//check = ENTER
//													temp_ch.noidung = x;	
//												cout<<"Nhap lua chon thu nhat: ";
//												check=NhapChuoi(x,11);
//												if(check == ESC)
//												{
//													check = checkEsc();
//													if (check==CONTINUE)
//														continue;
//													if (check==BREAK)
//														break;
//												}
//												else if (check==ENTER) 	//check = ENTER
//													temp_ch.A = x;	
//												cout<<"Nhap lua chon thu hai: ";
//												check=NhapMa(x, 8);
//												if(check == ESC)
//												{
//													check = checkEsc();
//													if (check==CONTINUE)
//														continue;
//													if (check==BREAK)
//														break;
//												}
//												else if (check==ENTER) 	//check = ENTER
//													temp_ch.B = x;
//												cout<<"Nhap lua chon thu ba: ";
//												check=NhapMa(x, 8);
//												if(check == ESC)
//												{
//													check = checkEsc();
//													if (check==CONTINUE)
//														continue;
//													if (check==BREAK)
//														break;
//												}
//												else if (check==ENTER) 	//check = ENTER
//													temp_ch.C = x;
//												cout<<"Nhap lua chon thu tu: ";
//												check=NhapMa(x, 8);
//												if(check == ESC)
//												{
//													check = checkEsc();
//													if (check==CONTINUE)
//														continue;
//													if (check==BREAK)
//														break;
//												}
//												else if (check==ENTER) 	//check = ENTER
//													temp_ch.D = x;
//												cout<<"Nhap dap an: ";
//												check=NhapMa(x, 2);
//												if(check == ESC)
//												{
//													check = checkEsc();
//													if (check==CONTINUE)
//														continue;
//													if (check==BREAK)
//														break;
//												}
//												else if (check==ENTER) 	//check = ENTER
//													strcpy(temp_ch.dapan, x);
//												checknu4_3:		
//												cout<<"Ban co muon luu thay doi khong?(y/n)";
//												check=NhapMa(x,2);
//												if (x[0]=='y'||x[0]=='Y')
//												{
//													sq->info = temp_ch;
//													cout << "Ban co muon tiep tuc chinh sua khong?(y/n) ";
//													check=NhapMa(x,2);
//													if (x[0]=='y'||x[0]=='Y')
//													{
//														continue;
//													}
//													else if (x[0]=='n'||x[0]=='N')
//														break;
//													else 
//													{
//														cout<<"Xac nhan khong phu hop"<<endl;
//														goto checknu4_3;
//													}
//												}
//												else if (x[0]=='n'||x[0]=='N')
//													break;
//												else 
//												{
//													cout<<"Xac nhan khong phu hop"<<endl;
//													goto checknu4_3;
//												}
//										}
//										else 
//										{
//											cout<<"Id nhap vao khong ton tai. Xin kiem tra lai!";
//											goto checknull4_2;
//										}
//									}
//								}
//								break;
//							case 3:
//								checknull4_4:
//								xoadong(wherey(),5);
//								cout << "Nhap ID cau hoi muon xoa: ";
//								check = NhapMa(x, 10);
//								ids = atoi(x);
//								if(check == ESC)
//								{
//									check = checkEsc();
//									if (check==CONTINUE)
//										continue;
//									if (check==BREAK)
//										break;
//								}
//								else if(check == ENTER)
//								{
//									// tim kiem cau hoi
//									sq = search(root, ids);
//									if (sq != NULL)
//									{
//										cout<<"Ban co muon xoa mon hoc nay khong?(y/n) ";
//										check=NhapMa(x,2);
//										if (x[0]=='y'||x[0]=='Y')
//										{
//											removeAVL(root, ids);
//											cout << "Xoa cau hoi thanh cong!!" << endl;
//											Sleep(1500);
//											break;
//										}
//										else if (x[0]=='n'||x[0]=='N')
//											break;
//										else
//										{
//											cout<<"Xac nhan khong phu hop."<<endl;
//											goto checknull4_4;
//										}
//									}
//								}	
//						
//						}
//					}
//					break;
//				case 5:						//Thi trac nghiem
////					createAVLTree(root);
//					break;
//				case 6:
//					break;
//			}
//		}
//	}
//	else if(check == 1)				//Sinh vien
//	{
//		cout << "May muon thi khong?!" << endl;
//	}
//	delete x;
//	int time = 10;
//	do
//	{
//		Sleep(1000);
//		gotoxy(300, 2);
//		cout << time--;
//		gotoxy(300, 2);
//		cout << "  ";
//	}while(time > 0);
	clearTree(root);
	clearList(ds);
	clearList(dsmh);
	clearSubjectQuest(FirstMT);
//	system("pause");
	return 0;
}

// string::pop_back

