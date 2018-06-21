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
	char MAMH;
	char TENMH;	
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


