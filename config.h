#pragma once
#include <iostream>
#define TRUE 1
#define FALSE 0
#define EMPTY 0
#define COMPLETE 1
#define UNDONE 0
#define MAXLOP 100

using namespace std;


const int SPACE = 32;
const int ENTER = 13;
const int ESC = 27;
const int BSPACE = 8;
const string ER_FULL_LIST = "Danh sach day!!";

struct monhoc
{
	char MAMH[7];
	char TENMH[50];
};
struct nodeMH
{
	monhoc info;
	struct nodeMH *next;
};
typedef nodeMH *PTRMH;

struct diem
{
	char Mamh[9];
	float mark;	
};
struct nodediem
{
	diem info;
	struct nodediem *next;
};
typedef nodediem *PTRD;
struct sinhvien
{
	char password[32];
	char MASV[11];
	char HO[51];
	char TEN[11];
	char PHAI[5];
};
struct nodesv
{
	sinhvien info;
	nodediem *Firstdiem;
	struct nodesv *next;
};
typedef nodesv *PTRSV;
struct Lop
{
	char MALOP[11];
	char TENLOP[100];
	PTRSV Firstsv;
};
struct dslop
{
	int n;
	Lop *lop;
};

struct cauhoi
{
	string noidung;
	char mamh[7];
	string A;
	string B;
	string C;
	string D;
	char dapan;
};

struct nodecauhoi
{
	int id;
	int bf;
	cauhoi info;
	struct nodecauhoi *left, *right;
};
typedef nodecauhoi *PTRQ;

char menuGV [7][50] = {"1. Nhap lop                                      ",
					   "2. In danh sach lop                              ",
					   "3. Nhap sinh vien cua lop                        ",
					   "4. Nhap mon hoc                                  ",
					   "5. Nhap cau hoi thi                              ",
					   "6. Thi trac nghiem                               ",
					   "7. Thoat                                         "
					   };
					   
