#pragma once
#include <iostream>
#define TRUE 1
#define FALSE 0
#define EMPTY 0
#define COMPLETE 1
#define UNDONE 0
#define WHITE 15
#define MAXLOP 100
#define STACKSIZE 500
using namespace std;

const int dong = 2;
const int cot = 2;
const int Up = 72;
const int Down = 80;
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
	char Mamh[7];
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
	char mamh[7];
	string noidung;
	string A;
	string B;
	string C;
	string D;
	char dapan[1];
};

struct nodecauhoi
{
	int id;		//khoa
	int bf;
	cauhoi info;
	struct nodecauhoi *left, *right;
};
typedef nodecauhoi *PTRQ;

char menuGV [7][50] = {"1. Dieu chinh danh sach lop                      ",
					   "2. Dieu chinh danh sach sinh vien                ",
					   "3. Dieu chinh danh sach mon hoc                  ",
					   "4. Dieu chinh cau hoi thi trac nghiem            ",
					   "5. Nhap cau hoi thi                              ",
					   "6. Thi trac nghiem                               ",
					   "7. Thoat                                         "
					   };
char menu1_1 [5][50] = {"1. Them lop                                     ",
						"2. Sua lop                                      ",
						"3. Xoa lop                                      ",
						"4. Xem danh sach lop                            ",
						"5. Quay lai menu chinh                          ",
					   };
					   
