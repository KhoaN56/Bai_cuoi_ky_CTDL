#pragma once
#include <iostream>
#include <conio.h>
#include <string>
#include <iomanip>
#include <windows.h>
#include "Mylib.h"
#include "config.h"
using namespace std;
//------Proccessing Class List-------
int Full_List(dslop ds);
int Empty_List(dslop ds);
//------Proccessing Student List------
void insertFirst(PTRSV &First, sinhvien x);
void insertAfter(PTRSV p, sinhvien x);
//------Mark Proccessing------
void insertFirst(PTRD &First, diem x);
void insertAfter(PTRD p, diem x);
//------Subject Proccessing------
void insertFirst(PTRMH &First, monhoc x);
void insertAfter(PTRMH p, monhoc x);
//------Display result------
void PrintClassList(dslop ds);
//------Save file------


int Full_List(dslop ds)
{
	return (ds.n == MAXLOP ? TRUE : FALSE);
}
int Empty_List(dslop ds)
{
	return (ds.n == 0 ? TRUE : FALSE);
}
void insertFirst(PTRSV &First, sinhvien x)
{
   PTRSV p;
   p = new nodesv;
   p->info = x;
   p->next = First;
   First = p;
}
void insertAfter(PTRSV p, sinhvien x)
{
   PTRSV q;
   if(p == NULL)
		printf("khong them phan tu vao danh sach duoc");
   else
   {
   		q = new nodesv;
    	q->info = x;
    	q->next = p->next;
    	p->next = q;
   }
}
//------Mark Proccessing------
void insertFirst(PTRD &First, diem x)
{
   PTRD p;
   p = new nodediem;
   p->info = x;
   p->next = First;
   First = p;
}
void insertAfter(PTRD p, diem x)
{
   PTRD q;
   if(p == NULL)
		printf("khong them phan tu vao danh sach duoc");
   else
   { 
    	q = new nodediem;
    	q->info = x;
      	q->next = p->next;
      	p->next = q;
   }
}
//------Subject Proccessing------
void insertFirst(PTRMH &First, monhoc x)
{
   PTRMH p;
   p = new nodeMH;
   p->info = x;
   p->next = First;
   First = p;
}
void insertAfter(PTRMH p, monhoc x)
{
   PTRMH q;
   if(p == NULL)
		printf("khong them phan tu vao danh sach duoc");
   else
   { 
    	q = new nodeMH;
    	q->info = x;
      	q->next = p->next;
      	p->next = q;
   }
}

int NhapChuoi(char *x)
{
	char c;
	int i = 0;
	//cout << "Nhap ten lop " << count + 1 << ": ";
	do
	{
		c = _getch();
		if (c == 0) c = _getch();
		else if (c == ESC)
		{
			x = "";
			break;
		}
		else if (c == ENTER)
		{
			if (strlen(x) < 1)
				return UNDONE;
			x[i] = '\0';
			cout << endl;
			break;
		}
		else if (c == BSPACE)
		{
			if (strlen(x) > 0)
			{
				--i;
				cout << c << ' ' << c;
				x[i] = NULL;
				continue;
			}
		}
		cout << c;
		x[i] = c;
		++i;
	} while (c != ENTER && c != ESC);
	if (c == ESC)
		return UNDONE;
	return COMPLETE;
}
void Themlop(dslop &ds)
{
	int i;
	char cf;
	for (i = 0; i < ds.n; ++i)
	{
		/*if (Full_List(ds) == TRUE)
		{
			cout << ER_FULL_LIST << endl;
			Sleep(1500);
			return;
		}*/
//		ds.lop[i].TENLOP = NULL;
		cout << "Nhap ten lop thu " << i + 1 << ": ";
		if (NhapChuoi(ds.lop[i].TENLOP) == UNDONE)
		{
			--i;
			break;
		}
	check:
		cout << "Nhap ma lop thu " << i + 1 << ": ";
		if (NhapChuoi(ds.lop[i].MALOP) == UNDONE)
		{
			if (strlen(ds.lop[i].TENLOP) == EMPTY)
			{
				cout << "\nBan chua nhap ma lop, ban co muon nhap lai khong?(y/n) ";
				cin >> cf;
				if (cf == 'y')
					goto check;
			}
			--i;
			break;
		}
		system("cls");
		++ds.n;
	}
	system("cls");
	ds.n = i + 1;
	//cout << ds.lop[0].TENLOP << endl;
	if (ds.n == 0)
		cout << "Ban chua them duoc lop nao!" << endl;
	else
		cout << "Ban da them thanh cong " << ds.n << " lop!!" << endl;
}

void PrintClassList(dslop ds)
{
	int x, y;
	cout << setw(5) << "STT" << setw(20) << "Ten lop" << setw(20) << "Ma lop" << endl;
	for (int i = 0; i < ds.n; ++i)
	{
		x = strlen(ds.lop[i].TENLOP);
		y = strlen(ds.lop[i].MALOP);
		cout << setw(4) << i + 1 << setw(18 + (x/2)) << ds.lop[i].TENLOP << setw(20 + (y/2)) << ds.lop[i].MALOP << endl;
	}
}
