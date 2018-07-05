#pragma once
using namespace std;
//------Class List Proccessing-------
int Full_List(dslop ds);
int Empty_List(dslop ds);
void Themlop(dslop &ds);
//------Student List Proccessing------
int emptyList(PTRSV First);
int countStudent(PTRSV First);
void insertFirst(PTRSV &First, sinhvien x);
void insertAfter(PTRSV p, sinhvien x, PTRD Firstdiem);
void insertOrder(PTRSV &First, sinhvien sv, PTRD Firstdiem);
PTRSV searchStudent(PTRSV First, char *masv);
void selectionSort(PTRSV &First);
char *makeString(sinhvien sv);
int deleteFirst(PTRSV &First);
int deleteAfter(PTRSV p);
int deleteStudent(PTRSV &First, sinhvien sv);
//------Mark Proccessing------
int emptyList(PTRD First);
int countMark(PTRD First);
void insertFirst(PTRD &First, diem x);
void insertAfter(PTRD p, diem x);
PTRD searchMark(PTRD First, monhoc MH);
//------Subject Proccessing------
int emptyList(PTRMH First);
int countSubject(PTRMH FirstMH);
void insertFirst(PTRMH &First, monhoc x);
void insertAfter(PTRMH p, monhoc x);
PTRMH searchMaMH(PTRMH First, char *mamh);
//------Quest tree proccessing------
PTRQ search(PTRQ root, int id);
//------Display Result------
void printString(char *x);
void printStudentList(PTRSV First);
void printSubjectList(PTRMH First);
void PrintClassList(dslop ds);
//------Save file------
void saveClassList(dslop ds, char *filename);
void saveStudentList(Lop Class, char *filename);
void saveMarkList(Lop Class, monhoc MH, char *filename);
void saveWork(dslop ds, char *filename, PTRMH FirstMH);
//------Load files------
void loadClassList(dslop &ds, char *filename);
void loadStudentList(Lop &Class, char *filename);
void loadMarkList(Lop Class, monhoc MH, char *filename);
void loadWork(dslop &ds, char *filename, PTRMH &FirstMH);
//------Clear Lists------
void clearList(PTRSV &First);
void clearList(PTRD &First);
void clearList(PTRMH &First);
void clearList(dslop &ds);



int Full_List(dslop ds)
{
	return (ds.n == MAXLOP ? TRUE : FALSE);
}
int Empty_List(dslop ds)
{
	return (ds.n == 0 ? TRUE : FALSE);
}
//------Student List Proccessing------
int emptyList(PTRSV First)
{
	return(First == NULL ? TRUE : FALSE);
}

void insertFirst(PTRSV &First, sinhvien x)
{
   PTRSV p;
   p = new nodesv;
   p->info = x;
   p->next = First;
   First = p;
}
void insertAfter(PTRSV p, sinhvien x, PTRD Firstdiem)
{
   PTRSV q;
   if(p == NULL)
		cout << "khong them phan tu vao danh sach duoc";
   else
   {
   		q = new nodesv;
    	q->info = x;
    	q->Firstdiem = Firstdiem;
    	q->next = p->next;
    	p->next = q;
   }
}

void insertOrder(PTRSV &First, sinhvien sv, PTRD Firstdiem)
{
	PTRSV after, before, p;
	p = new nodesv;
	p->info = sv;
	p->Firstdiem = Firstdiem;
	for(after = First; after != NULL && strcmp(makeString(after->info), makeString(sv)) < 0; before = after, after = after->next);
	if(after == First)
	{
		p->next = First;
		First = p;
	}
	else
	{
		p->next = after;
		before->next = p;
	}
}

PTRSV searchStudent(PTRSV First, char *masv)
{
	for(PTRSV p = First; p != NULL; p = p->next)
		if(strcmp(p->info.MASV, masv) == 0)	return p;
	return NULL;
}

void selectionSort(PTRSV &First)
{
	PTRSV p, q, pmin;
	sinhvien min;
	for(p = First; p->next != NULL; p = p->next)
	{
		min = p->info;
		pmin = p;
		for(q = p->next; q != NULL; q = q->next)
		{
			if(strcmp(makeString(q->info), makeString(min)) < 0)
			{
				min = q->info;
				pmin = q;
			}
		}
		pmin->info = p->info;
		p->info = min;
	}
}

char *makeString(sinhvien sv)
{
	char *info = new char[50];
	strcpy(info, sv.TEN);
	strcat(info, sv.HO);
	strcat(info, sv.MASV);
	return info;
}

int deleteFirst(PTRSV &First)
{
	if(First == NULL)
		return FALSE;
	else
	{
		PTRSV p = First;
		First = p->next;
		delete p;
	}
	return COMPLETE;
}

int deleteAfter(PTRSV p)
{
	if(p == NULL || p->next == NULL)
		return FALSE;
	else
	{
		PTRSV q = p->next;
		p->next = q->next;
		delete q;
	}
	return COMPLETE;
}

int deleteStudent(PTRSV &First, sinhvien sv)
{
	PTRSV p;
	if(First == NULL)
		return FALSE;
	if(strcmp(First->info.MASV,sv.MASV) == 0)
	{
		p = First;
		First = p->next;
		delete p;
		return COMPLETE;
	}
	for(p = First; p->next != NULL && strcmp(p->next->info.MASV, sv.MASV) != 0; p = p->next);
	if(p->next != NULL)
	{
		PTRSV q = p->next;
		p->next = q->next;
		delete q;
		return COMPLETE;
	}
	return FALSE;
}

void saveStudentList(Lop Class, char *filename)
{
	ofstream ofs;
	PTRSV p;
	p = new nodesv;
	ofs.open(filename, ios_base::out);
	ofs << Class.MALOP << endl;
	for(p = Class.Firstsv;p != NULL; p = p->next)
		ofs << p->info.MASV << ", " << p->info.HO << " " << p->info.TEN << ", "
		<< p->info.PHAI << ", " << p->info.password << endl;
	ofs << "#END";
	ofs.close();
}

void loadStudentList(Lop &Class, char *filename)
{
	ifstream ifs;
	PTRSV p;
	char malop[11];
	char buffer[100];
	ifs.open(filename, ios_base::in);
	if(ifs.fail() == true)
	{
		cout << "Ten file chua dung, moi nhap lai!!" << endl;
		system("pause");
	}
	ifs >> malop;
	if(strcmp(Class.MALOP, malop) == 0)
	{
		Class.Firstsv = new nodesv;
		ifs.getline(buffer, 100, ',');
		strncpy(Class.Firstsv->info.MASV, buffer, strlen(buffer));
		ifs >> Class.Firstsv->info.HO;
		ifs.getline(buffer, 100, ',');
		strncpy(Class.Firstsv->info.TEN, buffer, strlen(buffer));
		ifs.getline(buffer, 100, ',');
		strncpy(Class.Firstsv->info.PHAI, buffer, strlen(buffer));
		ifs >> Class.Firstsv->info.password;
		ifs.getline(buffer, 100, ',');
		p = Class.Firstsv->next;
		while(buffer[0] != '#')
		{
			p = new nodesv;
			strncpy(p->info.MASV, buffer, strlen(buffer));
			ifs >> p->info.HO;
			ifs.getline(buffer, 100, ',');
			strncpy(p->info.TEN, buffer, strlen(buffer));
			ifs.getline(buffer, 100, ',');
			strncpy(p->info.PHAI, buffer, strlen(buffer));
			ifs >> p->info.password;
			ifs.getline(buffer, 100, ',');
			p = p->next;
		}
		p = NULL;
	}
	else
	{
		cout << "Khong tim thay danh sach sinh vien cua lop!" << endl;
		Sleep(2000);
	}
}

int countStudent(PTRSV First)
{
	PTRSV p;
	int i = 0;
	if(First == NULL)
	{
		cout << "Danh sach rong!";
		Sleep(2000);
		return 0;
	}
	for(p = First; p != NULL; p = p->next , ++i);
	return i;
}

void printStudentList(PTRSV First)
{
	PTRSV p;
	int i = 1;
	if(First == NULL)
	{
		cout << "Danh sach rong!!" << endl;
		Sleep(2000);
		return;
	}
	cout << setw(4) << "STT" << setw(20) << "Ho va ten" << setw(15) << "Ma sinh vien" << endl;
	for(p = First; p != NULL; p = p->next, ++i)
	{
		cout << setw(3) << i << setw(5);
		printString(p->info.HO);
		cout << " ";
		printString(p->info.TEN);
		cout << setw(10);
		printString(p->info.MASV);
		cout << endl;
	}
}

//------Mark Proccessing------
int emptyList(PTRD First)
{
	return(First == NULL ? TRUE : FALSE);
}

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
		cout << "khong them phan tu vao danh sach duoc";
   else
   { 
    	q = new nodediem;
    	q->info = x;
      	q->next = p->next;
      	p->next = q;
   }
}

void saveMarkList(Lop Class, monhoc MH, char *filename)				//undone
{
	ofstream ofs;
	PTRSV p;
	ofs.open(filename, ios_base::out);
	ofs << Class.MALOP << endl;
	ofs << MH.MAMH << endl;
	for(p = Class.Firstsv; p != NULL; p = p -> next)
		ofs << p->info.MASV << " " << searchMark(p->Firstdiem, MH)->info.mark << endl;
	ofs << "#END";
	ofs.close();
}

void loadMarkList(Lop Class, monhoc MH, char *filename)
{
	ifstream ifs;
	PTRSV p;
	char code[11];
	char MaMH[9];
	ifs.open(filename, ios_base::in);
	if(ifs.fail() == true)
	{
		cout << "Ten file chua dung!!" << endl;
		system("pause");
	}
	ifs >> code;
	ifs >> MaMH;
	if(strcmp(Class.MALOP, code) == 0 && strcmp(MaMH, MH.MAMH) == 0)
	{
		ifs >> code;
		while(code[0] != '#')
		{
			p = searchStudent(Class.Firstsv, code);
			ifs >> searchMark(p->Firstdiem, MH)->info.mark;
			ifs >> code;
		}
	}
	else
	{
		cout << "File khong phu hop!" << endl;
		system("pause");
	}
	ifs.close();
}

PTRD searchMark(PTRD First, monhoc MH)
{
	for(PTRD p = First; p != NULL; p = p->next)
		if(strcmp(p->info.Mamh, MH.MAMH) == 0)
			return p;
	return NULL;
}

int countMark(PTRD First)
{
	PTRD p;
	int i = 0;
	if(First == NULL)
	{
		cout << "Danh sach diem rong!";
		Sleep(2000);
		return 0;
	}
	for(p = First; p !=NULL ; p = p->next, ++i);
	return i;
}

//------Subject Proccessing------
int emptyList(PTRMH First)
{
	return (First == NULL ? TRUE : FALSE);
}

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
		cout << "Khong them phan tu vao danh sach duoc!" << endl;
   else
   { 
    	q = new nodeMH;
    	q->info = x;
      	q->next = p->next;
      	p->next = q;
   }
}

PTRMH searchMaMH(PTRMH First, char *mamh)
{
	for(PTRMH p = First; p != NULL; p=p->next)
		if(strcmp(p->info.MAMH, mamh) == 0)
			return p;
	return NULL;
}

int countSubject(PTRMH FirstMH)
{
	PTRMH p;
	int i = 0;
	if(FirstMH == NULL)
	{
		cout << "Danh sach mon hoc rong!";
		Sleep(2000);
		return 0;
	}
	for(p = FirstMH; p != NULL; p = p->next , ++i);
	return i;
}

void printSubjectList(PTRMH First)
{
	PTRMH p;
	int i = 1;
	cout << setw(4) << "STT" << setw(20) << "Ten mon hoc" << setw(15) << "Ma mon hoc" << endl;
	for(p = First; p != NULL; p = p->next, ++i)
	{
		cout << setw(3) << i << setw(8);
		printString(p->info.TENMH);
		cout << setw(10);
		printString(p->info.MAMH);
		cout << endl;
	}
}

//------Quest tree proccessing------

PTRQ search(PTRQ root, int id)
{
	PTRQ p = root;
	while(p != NULL && id != p->id)
		if(id < p->id)
			p = p->left;
		else
			p = p->right;
	return p;
}

void createAVLTree(PTRQ &root)
{
	int id;
	
}
//------Others------
void printString(char *x)
{
	int i = 0;
	if(x == NULL)
		return;
	while(i < strlen(x))
	{
		cout << x[i++];
	}
}
char NhapChuoi(char *x)
{
	char c;
	int i = 0;
//	cout << "Nhap ten lop " << count + 1 << ": ";
	while(1)
	{
		c = getch();
		if (c == 0) c = getch();
		else if (c == ESC)
		{
			x = "";
			break;
		}
		else if (c == ENTER)
		{
			if (strlen(x) < 1)
				return ESC;
			x[i] = '\0';
			cout << endl;
			break;
		}
		else if (c == BSPACE)
		{
			if (strlen(x) > 0)
			{
				--i;
				cout << c << " " << c;
				x[i] = NULL;
				continue;
			}
		}
		cout << c;
		x[i] = c;
		++i;
	}
	return c;
}

void saveWork(dslop ds, char *filename, PTRMH FirstMH)
{
	ofstream ofs;
	PTRSV p;
	PTRD q;
	PTRMH s;
	ofs.open(filename, ios_base::out);
	if(ofs.fail()==true)
	{
		cout << "Khong mo duoc file" << endl;
		Sleep(3000);
		return;
	}
	ofs << ds.n << endl;
	for(int i = 0; i < ds.n; ++i)
	{
		ofs << ds.lop[i].TENLOP << endl;
		ofs << ds.lop[i].MALOP << endl;
		ofs << countStudent(ds.lop[i].Firstsv) << endl;
		for(p = ds.lop[i].Firstsv; p != NULL; p=p->next)
		{
			ofs << p->info.MASV << ",";
			ofs << p->info.password << ",";
			ofs << p->info.HO << ",";
			ofs << p->info.TEN << ",";
			ofs << p->info.PHAI << ",";
			ofs << countMark(p->Firstdiem) << ",";
			for(q = p->Firstdiem; q != NULL; q=q->next)
			{
				ofs << q->info.Mamh << ",";
				if(q->next == NULL)
					ofs << q->info.mark << "." << endl;
				else
					ofs << q->info.mark << ",";
			}
		}
	}
	ofs << countSubject(FirstMH) << endl;
	for(s = FirstMH; s != NULL; s = s->next)
	{
		ofs << s->info.TENMH << ",";
		ofs << s->info.MAMH << endl;
	}
	ofs.close();
}

void loadWork(dslop &ds, char *filename, PTRMH &FirstMH)
{
	ifstream ifs;
	PTRSV p, pr;
	PTRD q, qr;
	PTRMH s, sr;
//	sinhvien x;
	
	int i, j, k, maxsv, maxdiem, maxmh;
	char buffer[100];
	ifs.open(filename, ios_base::in);
	if(ifs.fail() == true)
	{
		cout << "Khong mo duoc file" << endl;
		Sleep(3000);
		return;
	}
	ifs.getline(buffer, 100, '\n');
	ds.n = atoi(buffer);
//	ifs >> ds.n;
	for(i = 0; i < ds.n; ++i)
	{
		ifs.getline(ds.lop[i].TENLOP, 100, '\n');
		ifs.getline(ds.lop[i].MALOP, 11, '\n');
		ifs.getline(buffer, 100, '\n');
		maxsv = atoi(buffer);
		for(j = 0; j < maxsv; ++j)
		{
			p = new nodesv;
			ifs.getline(p->info.MASV, 11, ',');
			ifs.getline(p->info.password, 32, ',');
			ifs.getline(p->info.HO, 51, ',');
			ifs.getline(p->info.TEN, 11, ',');
			ifs.getline(p->info.PHAI, 5, ',');
			ifs.getline(buffer, 100, ',');
			maxdiem = atoi(buffer);
			for(k = 0; k < maxdiem; ++k)
			{
				q = new nodediem;
				ifs.getline(q->info.Mamh, 9, ',');
				if(k == maxdiem - 1)
				{
					ifs.getline(buffer, 100, '\n');
					q->info.mark = atoi(buffer);
					for(qr = p->Firstdiem; qr->next != NULL; qr = qr->next);
					qr->next = q;
					q->next = NULL;
					break;
				}
				ifs.getline(buffer, 100, ',');
				q->info.mark = atoi(buffer);
				if(k == 0)
					p->Firstdiem = q;
				else
				{
					for(qr = p->Firstdiem; qr->next != NULL; qr = qr->next);
					qr->next = q;
				}
				q->next = NULL;
			}
			if(j == 0)
				ds.lop[i].Firstsv = p;
			else
			{
				for(pr = ds.lop[i].Firstsv; pr->next != NULL; pr = pr->next);
				pr->next = p;
			}
			p->next = NULL;
		}
	}
	ifs.getline(buffer, 100, '\n');
	maxmh = atoi(buffer);
	for(i = 0; i < maxmh; ++i)
	{
		s = new nodeMH;
		ifs.getline(s->info.TENMH, 50, ',');
		ifs.getline(s->info.MAMH, 7, '\n');
		if(i == 0)
			FirstMH = s;
		else
		{
			for(sr = FirstMH; sr->next != NULL; sr = sr->next);
			sr->next = s;
		}
		s->next = NULL;
	}
	ifs.close();
}

//------Class List Proccessing-------

void Themlop(dslop &ds)
{
	int i;
	char cf;
	if (ds.n == MAXLOP)
	{
		cout << ER_FULL_LIST << endl;
		Sleep(1500);
		return;
	}
	for (i = 0; i < MAXLOP; ++i)
	{
//		ds.lop[i].TENLOP = NULL;
	check:
		cout << "Nhap ten lop thu " << i + 1 << ": ";
		if (NhapChuoi(ds.lop[i].TENLOP) == ESC)
		{
			cout << "Ban chua nhap ten lop, ban co muon nhap lai khong?(y/n) ";
			cin >> cf;
			goto check;
			--i;
			break;
		}
	check1:
		cout << "Nhap ma lop thu " << i + 1 << ": ";
		if (NhapChuoi(ds.lop[i].MALOP) == ESC)
		{
				cout << "\nBan chua nhap ma lop, ban co muon nhap lai khong?(y/n) ";
				cin >> cf;
				if (cf == 'y')
					goto check1;
			--i;
			break;
		}
		system("cls");
		if(i == ds.n - 1)
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

void saveClassList(dslop ds, char *filename)
{
	ofstream ofs;
	int i;
	ofs.open(filename, ios_base::out);
	if (ofs.fail()==true)
		cout << "Khong mo duoc file" << endl;
	ofs << ds.n << endl;
	for(i = 0; i < ds.n; ++i)
		ofs << ds.lop[i].MALOP << " " << ds.lop[i].TENLOP << endl;
	ofs.close();
}

void loadClassList(dslop &ds, char *filename)
{
	ifstream ifs;
	int i;
	ifs.open(filename, ios_base::in);
	if(ifs.fail() == true)
		cout << "Ten file chua dung" << endl;
	ifs >> ds.n;
	for(i = 0; i < ds.n; ++i)
		ifs >> ds.lop[i].MALOP >> ds.lop[i].TENLOP;
	ifs.close();
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

//------Clear Lists------
void clearList(PTRSV &First)
{
	PTRSV p;
	while(First != NULL)
	{
		p = First;
		clearList(First->Firstdiem);
		First = First->next;
		delete p;
	}
}
void clearList(PTRD &First)
{
	PTRD p;
	while(First != NULL)
	{
		p = First;
		First = First->next;
		delete p;
	}
}
void clearList(PTRMH &First)
{
	PTRMH p;
	while(First != NULL)
	{
		p = First;
		First = First->next;
		delete p;
	}
}
void clearList(dslop &ds)
{
	for(int i = 0; i < ds.n; ++i)
	{
		clearList(ds.lop[i].Firstsv);
	}
	delete ds.lop;
}
