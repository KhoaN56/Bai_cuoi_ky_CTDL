#pragma once
using namespace std;
//------Class List Proccessing-------
int Full_List(dslop ds);
int Empty_List(dslop ds);
void Themlop(dslop &ds);
void deleteClass(dslop &ds, Lop Class);
void moveToLast(dslop &ds, int i);
//------Student List Proccessing------
int emptyList(PTRSV First);
int countStudent(PTRSV First);
void insertFirst(PTRSV &First, sinhvien x);
void insertAfter(PTRSV p, sinhvien x);
void insertOrder(PTRSV &First, sinhvien sv);
PTRSV searchStudent(PTRSV First, char *masv);
void selectionSort(PTRSV &First);
char *makeString(sinhvien sv);
int deleteFirst(PTRSV &First);
int deleteAfter(PTRSV p);
int deleteStudent(PTRSV &First, char *masv);
//------Mark Proccessing------
int emptyList(PTRD First);
int countMark(PTRD First);
void insertFirst(PTRD &First, diem x);
void insertAfter(PTRD p, diem x);
PTRD searchMark(PTRD &First, monhoc &MH);
//------Subject Proccessing------
int emptyList(PTRMH First);
int countSubject(PTRMH FirstMH);
void insertFirst(PTRMH &First, monhoc x);
void insertAfter(PTRMH p, monhoc x);
PTRMH searchMaMH(PTRMH First, char *mamh);
int deleteSubject(PTRMH &First, char *mamh);
//------Quest tree proccessing (AVL tree)------
int nodeHeight(PTRQ p);
PTRQ search(PTRQ root, int id);
PTRQ rotateLeft(PTRQ root);
PTRQ rotateRight(PTRQ ya);
void insertAVLTree(PTRQ &pavltree, int x, cauhoi a);
void balanceLeft(PTRQ &root, int lh);
void balanceRight(PTRQ &root, int rh);
void removeAVL(PTRQ &root, int x);
void removeCase3(PTRQ &r, int x, PTRQ &rp);
//------List of subject quest proccessing------
void insertAfter(PTRCT &p, char *mamh);
void addID(dscauthi &ds, int id);
void moveOut(dscauthi &ds, int i);
//------Display Result------
void printString(char *x);
void printInfo(PTRSV p);
void printStudentList(PTRSV First);
void printSubjectList(PTRMH First);
void printClassList(dslop ds);
void printMarkSubject(Lop &Class, monhoc &MH);
//------Others------
void viethoa(char *x);
void stoc(string s, char *c);
void ctos(char *c, string &s);
int checkEsc ();
int NhapChuoi(char *x);
int MenuDong(char td [][50]);
int NhapMa(char *x, int n_max);
int NhapChuoi(char *x, int n_max);
int NhapPass( char *x, int n_max);
//------Save file------
void saveClassList(dslop ds, char *filename);
void saveStudentList(Lop Class, char *filename);
void saveMarkList(Lop Class, monhoc MH, char *filename);
void saveWork(dslop ds, char *filename, PTRMH FirstMH);
//------Load files------
void loadClassList(dslop &ds, char *filename);
void loadStudentList(Lop &Class, char *filename);
void loadMarkList(Lop Class, monhoc MH, char *filename);
void loadWork(dslop &ds, char *filename, PTRMH &FirstMH, PTRQ &root, PTRCT &FirstMT);
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
void insertAfter(PTRSV p, sinhvien x)
{
   PTRSV q;
   if(p == NULL)
		cout << "khong them phan tu vao danh sach duoc";
   else
   {
   		q = new nodesv;
    	q->info = x;
    	q->next = p->next;
    	p->next = q;
   }
}

void insertOrder(PTRSV &First, sinhvien sv)
{
	PTRSV after, before, p;
	p = new nodesv;
	p->info = sv;
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

int deleteStudent(PTRSV &First, char *masv)
{
	PTRSV p;
	char cf;
	if(First == NULL)
	{
		cout << "Danh sach rong!!" << endl;
	}
		return FALSE;
	if(strcmp(First->info.MASV,masv) == 0)
	{
		printInfo(p);
		cout << "Ban muon xoa sinh vien nay khong?(y/n) ";
		cin >> cf;
		if(cf == 'y' || cf == 'Y')
		{
			p = First;
			First = p->next;
			delete p;
			return COMPLETE;
		}
	}
	for(p = First; p->next != NULL && strcmp(p->next->info.MASV, masv) != 0; p = p->next);
	if(p->next != NULL)
	{
		printInfo(p);
		cout << "Ban muon xoa sinh vien nay khong?(y/n) ";
		cin >> cf;
		if(cf == 'y' || cf == 'Y')
		{
			PTRSV q = p->next;
			p->next = q->next;
			delete q;
			return COMPLETE;
		}
		else
			return UNDONE;
	}
	return FALSE;
}

void saveStudentList(Lop Class, char *filename)
{
	ofstream ofs;
	PTRSV p;
	p = new nodesv;
	ofs.open(filename, ios_base::out);
	ofs << Class.TENLOP << endl;
	ofs << Class.MALOP << endl;
	for(p = Class.Firstsv;p != NULL; p = p->next)
		ofs << p->info.MASV << ", " << p->info.HO << " " << p->info.TEN << ", "
		<< p->info.PHAI << ", " << p->info.password << endl;
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
	ifs.getline(malop, 11, '\n');
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
	cout << setw(4) << "STT" << setw(20) << "Ho va ten" << setw(15) << "Ma sinh vien" << setw(5) << "Phai" << endl;
	for(p = First; p != NULL; p = p->next, ++i)
	{
		cout << setw(3) << i << setw(5);
		printString(p->info.HO);
		cout << " ";
		printString(p->info.TEN);
		cout << setw(10);
		printString(p->info.MASV);
		cout << '\t';
		printString(p->info.PHAI);
		cout << endl;
	}
}

void printInfo(PTRSV p)
{
	cout << p->info.MASV << endl;
	cout << p->info.HO << " " << p->info.TEN << endl;
	cout << p->info.PHAI << endl;
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

PTRD searchMark(PTRD &First, monhoc &MH)
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

void printMarkSubject(Lop &Class, monhoc &MH)
{
	if(Class.Firstsv == NULL)
	{
		cout << "Danh sach sinh vien rong!!" << endl;
		Sleep(2000);
		return;
	}
	int i = 1;
	PTRD q;
	PTRSV p;
	cout << "\t\t\t\tDANH SACH DIEM THI MON " << MH.TENMH << " LOP " << Class.MALOP << endl << endl;
	cout << setw(4) << "STT" << setw(20) << "Ho va ten" << setw(15) << "Ma sinh vien" << setw(10) << "Diem thi" << endl;
	for(p = Class.Firstsv; p != NULL; p = p->next)
	{
		cout << setw(3) << i << setw(5);
		printString(p->info.HO);
		cout << " ";
		printString(p->info.TEN);
		cout << "\t";
		printString(p->info.MASV);
		q = searchMark(p->Firstdiem, MH);
		if(q == NULL)
			cout << "\tChua thi" << endl;
		else
			cout << "\t" << q->info.mark << endl;
	}
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
	if(First == NULL)
	{
		cout << "Danh sach rong!!" << endl;
		Sleep(1500);
		return;
	}
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

int deleteSubject(PTRMH &First, char *mamh)
{
	if(First == NULL)
	{
		cout << "Danh sach rong!!" << endl;
		Sleep(1500);
		return FALSE;
	}
	PTRMH p, q;
	char cf;
	if(strcmp(First->info.MAMH, mamh) == 0)
	{
		cout << "Ma mon hoc: " << p->info.MAMH << endl;
		cout << "Ten mon hoc: " << p->info.TENMH << endl;
		cout << "Ban co muon xoa mon hoc nay khoi danh sach khong?(y/n) ";
		cin >> cf;
		if(cf == 'y' || cf == 'Y')
		{
			p = First;
			First = p->next;
			delete p;
			return COMPLETE;
		}
	}
	for(p = First; p != NULL && strcmp(p->info.MAMH, mamh) != 0; q = p, p = p->next);
	if(p != NULL)
	{
		cout << "Ma mon hoc: " << p->info.MAMH << endl;
		cout << "Ten mon hoc: " << p->info.TENMH << endl;
		cout << "Ban co muon xoa mon hoc nay khoi danh sach khong?(y/n) ";
		cin >> cf;
		if(cf == 'y' || cf == 'Y')
		{
			q->next = p->next;
			delete p;
			return COMPLETE;
		}
		else
			return UNDONE;
	}
}

//------Quest tree proccessing------

int nodeHeight(PTRQ p)
{
	if(p == NULL)
		return 0;
	return max(nodeHeight(p->left), nodeHeight(p->right)) + 1;
}

PTRQ search(PTRQ root, int id)
{
	PTRQ p = root;
	while(p != NULL && id != p->id)
		if(id < p->id)
			p = p->left;
		else
			p = p->right;
	if(p == NULL)
	{
		cout << "Khong tim thay cau hoi co id = " << id << "!" << endl;
		Sleep(2000);
	}
	return p;
}

PTRQ rotateLeft(PTRQ root)
{
	PTRQ p;
	if(root == NULL)
	{
		cout << "Cay rong!" << endl;
		Sleep(2000);
		return 0;
	}
	else
	{
		if(root->right == NULL)
		{
			cout << "Khong the xoay trai vi cay khong co nut con ben phai!!" << endl;
			Sleep(3000);
		}
		else
		{
			p = root->right;
			root->right = p->left;
			p->left = root;
		}
	}
	return p;
}

PTRQ rotateRight(PTRQ ya)
{
	PTRQ s;
	if(ya == NULL)
	{
		cout << "Cay rong!!" << endl;
		Sleep(2000);
		return 0;
	}
	else
	{
		if(ya->left == NULL)
		{
			cout << "Khong the xoay phai vi cay khong co nut con ben trai!!" << endl;
			Sleep(3000);
		}
		else
		{
			s = ya->left;
			ya->left = s->right;
			s->right = ya;
		}
	}
	return s;
}

void insertAVLTree(PTRQ &pavltree, int x, cauhoi a)
{
   	PTRQ fp, p, q,    	// fp la nut cha cua p, q la con cua p
           fya, ya,     	/* ya la nut truoc gan nhat co the mat can bang
                           	   fya la nut cha cua ya */
           s;           	// s la nut con cua ya theo huong mat can bang
   	int imbal;           	/* imbal =  1 neu bi lech ve nhanh trai
                                 	   	  = -1 neu bi lech ve nhanh phai */
   	// Khoi dong cac gia tri
   	fp = NULL;	p = pavltree;
   	fya = NULL;	ya = p;
	// tim nut fp, ya va fya, nut moi them vao la nut la con cua nut fp
   	while(p != NULL)
   	{
      	if (x == p->id)  // bi trung khoa
         	return;
      	if (x < p->id)
	 		q = p->left;
      	else
         	q = p->right;
      	if(q != NULL)
         	if(q->bf != 0) // truong hop chi so can bang cua q la 1 hay -1
         	{ 
				fya = p;
            	ya = q;
         	}
      	fp = p;
      	p = q;
   	}
	// Them nut moi (nut la) la con cua nut fp
	q = new nodecauhoi;	// cap phat vung nho
	q->id =x;  q->info = a;  q->bf = 0;
	q->left = NULL;  q->right = NULL;
    if(x < fp->id)
    	fp->left = q;
	else
    	fp->right = q;
   	/*Hieu chinh chi so can bang cua tat ca cac nut giua ya va q, neu bi lech
      ve phia trai thi chi so can bang cua tat ca cac nut giua ya va q deu la
      1, neu bi lech ve phia phai thi chi so can bang cua tat ca cac nut giua
      ya va q deu la -1 */
   	if(x < ya->id)
      	p = ya->left;
   	else
     	p = ya->right;
   	s = p;     // s la con nut ya
   	while(p != q)
   	{ 
   		if(x < p->id)
      	{ 
			p->bf = 1;
        	p = p->left;
      	}
      	else
      	{  	
		  	p->bf = -1;
	 		p = p->right;
      	}
   	}
   	// xac dinh huong lech
   	if(x < ya->id)
    	imbal = 1;
   	else
    	imbal = -1;

   	if(ya->bf == 0)
   	{ 
   		ya->bf = imbal;
      	return;
   	}
   	if(ya->bf != imbal)
   	{ 
	   	ya->bf = 0;
      	return;
   	}

   	if(s->bf == imbal)   // Truong hop xoay don
   	{ 
	   	if(imbal == 1)    // xoay phai 
        	p = rotateRight(ya);
      	else              // xoay trai 
         	p = rotateLeft(ya);
      	ya->bf = 0;
     	s->bf = 0;
   	}
   	else                 // Truong hop xoay kep
   	{ 
	   	if(imbal == 1)    // xoay kep trai-phai 
     	{
			ya->left = rotateLeft(s);
         	p = rotateRight(ya);
      	}
      	else              // xoay kep phai-trai - 
      	{
		  	ya->right = rotateRight(s);
	 		p = rotateLeft(ya);
      	}
      	if(p->bf == 0)    // truong hop p la nut moi them vao
     	{
		 	ya->bf = 0;
         	s->bf = 0;
      	}
      	else
         	if(p->bf == imbal)
         	{
			 	ya->bf = -imbal;
            	s->bf = 0;
         	}
         	else
         	{ 
			 	ya->bf = 0;
            	s->bf = imbal;
         	}
      	p->bf = 0;
   	}
   	if(fya == NULL)
      	pavltree = p;
   	else
      	if(ya == fya->right)
         	fya->right = p;
      	else
         	fya->left = p;
}

void createAVLTree(PTRQ &root)
{
	int id;
	cauhoi x;
	char buffer[2000], cf;
	do
	{
		cout << "Nhap id cau hoi: ";
		cin >> id;
		if(id != 0)
		{
			cout << "Nhap ma mon hoc: ";
			if(NhapChuoi(x.mamh) == ESC)
			{
				cout << "Ban muon ngung nhap cau hoi thi?(y/n) ";
				cin >> cf;
				if(cf == 'y')
					return;
				else
					continue;
			}
			cout << "Nhap noi dung cau hoi: ";
			if(NhapChuoi(buffer) == ESC)
			{
				cout << "Ban muon ngung nhap cau hoi thi?(y/n) ";
				cin >> cf;
				if(cf == 'y')
					return;
				else
					continue;
			}
			else
				x.noidung = buffer;
			memset(buffer, '\0', 2000);
			cout << "Nhap noi dung lua chon A: ";
			if(NhapChuoi(buffer) == ESC)
			{
				cout << "Ban muon ngung nhap cau hoi thi?(y/n) ";
				cin >> cf;
				if(cf == 'y')
					return;
				else
					continue;
			}
			else
				x.A = buffer;
			cout << "Nhap noi dung lua chon B: ";
			if(NhapChuoi(buffer) == ESC)
			{
				cout << "Ban muon ngung nhap cau hoi thi?(y/n) ";
				cin >> cf;
				if(cf == 'y')
					return;
				else
					continue;
			}
			else
				x.B = buffer;
				cout << "Nhap noi dung lua chon C: ";
			if(NhapChuoi(buffer) == ESC)
			{
				cout << "Ban muon ngung nhap cau hoi thi?(y/n) ";
				cin >> cf;
				if(cf == 'y')
					return;
				else
					continue;
			}
			else
				x.C = buffer;
				cout << "Nhap noi dung lua chon D: ";
			if(NhapChuoi(buffer) == ESC)
			{
				cout << "Ban muon ngung nhap cau hoi thi?(y/n) ";
				cin >> cf;
				if(cf == 'y')
					return;
				else
					continue;
			}
			else
				x.D = buffer;
			cout << "Nhap dap an: ";
			if(NhapChuoi(x.dapan) == ESC)
			{
				cout << "Ban muon ngung nhap cau hoi thi?(y/n) ";
				cin >> cf;
				if(cf == 'y')
					return;
				else
					continue;
			}
			if(root == NULL)
			{
				root = new nodecauhoi;
				root->bf = 0;	root->info = x;
				root->id = id;
				root->left = NULL;	root->right = NULL;
			}
			else
				insertAVLTree(root, id, x);
		}
	}while(id != 0);
}

void removeCase3(PTRQ &r, int x, PTRQ &rp)
{
	if(r->left != NULL)
		removeCase3(r->left, x, rp);
	else
	{
		rp->id = r->id;
//		rp->bf = r->bf;
		rp->info = r->info;
		rp = r;
		r = rp->right;
	}	
}

void balanceLeft(PTRQ &root, int lh)
{
	int rh = nodeHeight(root->right);
	if (abs(lh - rh) > 1)		//Cay mat can bang
	{
		if(root->right->bf == root->bf)		//Lech phai phai
			root = rotateLeft(root->right);
		else					//Lech phai trai
		{
			root->right = rotateRight(root->right);
			root = rotateLeft(root->right);
		}
	}
	
}

void balanceRight(PTRQ &root, int rh)
{
	int lh = nodeHeight(root->left);
	if (abs(lh - rh) > 1)		//Cay mat can bang
	{
		if(root->left->bf == root->bf)		//Lech trai trai
			root = rotateRight(root->left);
		else					//Lech trai phai
		{
			root->left = rotateLeft(root->left);
			root = rotateRight(root->left);
		}
	}
	
}

void removeAVL(PTRQ &root, int x)
{
	if(root == NULL)
	{
		cout << "Khong the xoa nut rong!!";
		Sleep(2000);
		return;
	}
	else
	{
		if(x < root->id)
		{
			int ah, bh = nodeHeight(root->left);		//bh la chieu cao truoc khi xoa node
			removeAVL(root->left, x);			//ah la chieu cao sau khi xoa node
			ah = nodeHeight(root->left);
			if(ah < bh)
				balanceLeft(root, ah);
			root->bf = nodeHeight(root->left) - nodeHeight(root->right);		//cap nhat he so can bang cua node
			//code can bang cay con nhanh trai neu chieu cao cua no bi giam
		}
		else if(x > root->id)
		{
			int ah, bh = nodeHeight(root->right);
			removeAVL(root->right, x);
			ah = nodeHeight(root->right);
			if(ah < bh)
				balanceRight(root, ah);
			root->bf = nodeHeight(root->left) - nodeHeight(root->right);		//cap nhat he so can bang cua node
			//code can bang cay con nhanh phai neu chieu cao cua no bi giam
		}
		else		//x = root->id
		{
			PTRQ rp;
			rp = root;
			if(rp->right == NULL)	root = rp->left;		//root la nut la hoac la nut chi co cay con ben trai
			else if(rp->left == NULL)	root = rp->right;	//root chi co cay con ben phai
			else
			{
				removeCase3(rp->right, x, rp);			//root co 2 cay con
				removeAVL(root->right, root->id);		/*Chay vao kiem tra lai phan node 
														cuc trai bi xoa thay the de can bang lai*/
			}
			delete rp;
		}
	}
}

void Intrav(PTRQ root, PTRCT &First)
{
   	PTRQ Stack[STACKSIZE];
   	PTRQ p=root;
   	PTRCT q = First;
   	int sp=-1, check = 0;	// Khoi tao Stack rong
   	char *c;
	
   	do
   	{ 
	   	while(p != NULL)
		{	
			Stack[++sp]= p;
	 		p= p->left;
      	}
      	if (sp != -1)
      	{
			p=Stack[sp--];
			if(check == 0)
			{
				check = 1; 
				First = new nodedscauthi;
				strcpy(First->MAMH, p->info.mamh);
				First->info.id = new int[MAXCAUTHI];
				First->info.id[0] = p->id;
				q = First;
				q->info.n = 1;
			}
			else
			{
				if(strcmp(q->MAMH, p->info.mamh) != 0)
				{
					for(q = First; q->next != NULL; q = q->next);
					insertAfter(q, p->info.mamh);
					if(q != NULL)
						q->info.id[0] = p->id;
					q->info.n = 1;
				}
				else
					addID(q->info, p->id);
			}
			p=p->right;
      	}
      	else 
			break;
   }while (1);

}



//------List of subject quest proccessing------

void insertAfter(PTRCT &p, char *mamh)
{
	if(p == NULL)
	{
		cout << "Khong the them vi danh sach rong!!" << endl;
		Sleep(2000);
		return;
	}
	PTRCT q;
	q = new nodedscauthi;
	strcpy(q->MAMH, mamh);
	q->info.id = new int[MAXCAUTHI];
	q->next = p->next;
	p->next = q;
}

void addID(dscauthi &ds, int id)
{
	if(ds.n == MAXCAUTHI)
	{
		cout << "Danh sach day, khong the them duoc!!" << endl;
		Sleep(2000);
		return;
	}
	int i;
	for(i = 0; i < MAXCAUTHI && id > ds.id[i]; ++i);
	moveOut(ds, i);
	ds.id[i + 1] = id;
	++ds.n;
}

void moveOut(dscauthi &ds, int i)
{
	int x, y;
	for(int j = ds.n; j > i - 1; --j)
	{
		ds.id[j] = ds.id[j - 1];
	}
}

void clearSubjectQuest(PTRCT &First)
{
	PTRCT p;
	while(First != NULL)
	{
		p = First;
		First = p->next;
		delete p->info.id;
		delete p;
	}
}

//------Others------

int c_a_r(char td [][50])
{
	int i;
	for(i = 0; td[i][0] != NULL; ++i);
	return i;
}

void viethoa(char *x)
{
	char a;
	for (int i = 0; i < strlen(x); ++i)
	{
		a = x[i];
		if (a >= 97 && a <= 122)
		{
			x[i] = a - 32;
		}
		else
			x[i] = a;
	}
}

void ctos(char *c, string &s)
{
	int i = 0;
	while(i < strlen(c))
	{
		s[i] = c[i];
	}
}

void stoc(string s, char *c)
{
	int i = 0;
	while(i < s.length())
	{
		c[i] = s[i];
	}
}

int checkEsc ()
{
	
	int check;
	char *x=new char [2];
	check2_esc:
	gotoxy(wherex(), wherey() + 1);
	xoadong(wherey(), 3);
	cout << "Ban muon quay lai menu?(y/n) ";
	check = NhapMa(x, 2);
	if(check == ESC)
		return CONTINUE;
	else if(check == ENTER)
	{
		if(x[0] == 'y' || x[0] == 'Y')
			return BREAK;
		else if(x[0] == 'n' || x[0] == 'N')
			return CONTINUE;
		else
		{
			cout << "Xac nhan khong phu hop!";          
			Sleep(1500);
			goto check2_esc;
		}
	}
	delete x;
}

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

int NhapChuoi(char *x)
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
			return ESC;
		}
		else if (c == ENTER)
		{
			if (strlen(x) < 1)
				return ESC;
			x[i] = '\0';
			cout << endl;
			return ENTER;
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

void loadWork(dslop &ds, char *filename, PTRMH &FirstMH, PTRQ &root, PTRCT &FirstMT)
{
	ifstream ifs;
	PTRSV p, pr;
	PTRD q, qr;
	PTRMH s, sr;
	PTRCT ql;
	cauhoi quest;
	dscauthi qlist;
//	sinhvien x;
	
	int i, j, k, maxsv, maxdiem, maxmh, maxq, id;
	char buffer[2000];
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
	ifs.getline(buffer, 100, '\n');
	maxq = atoi(buffer);
	for(i = 0; i < maxq; ++i)					//Doc cay nhi phan
	{
		ifs.getline(buffer, 100, '\n');
		id = atoi(buffer);
		ifs.getline(quest.mamh, 100, '\n');
		ifs.getline(buffer, 2000, '\n');
		quest.noidung = buffer;
		ifs.getline(buffer, 2000, '\n');
		quest.A = buffer;
		ifs.getline(buffer, 2000, '\n');
		quest.B = buffer;
		ifs.getline(buffer, 2000, '\n');
		quest.C = buffer;
		ifs.getline(buffer, 2000, '\n');
		quest.D = buffer;
		ifs.getline(quest.dapan, 100, '\n');
		if(i == 0)
		{
			root = new nodecauhoi;
			root->id = id;
			root->bf = 0;
			root->info = quest;
			root->left = NULL;
			root->right = NULL;
//			FirstMT = new nodedscauthi;
//			strcpy(FirstMT->MAMH, quest.mamh);
//			FirstMT->info.id = new int[MAXCAUTHI];
//			FirstMT->info.id[0] = id;
//			FirstMT->next = NULL;
//			ql = FirstMT;
		}
		else
		{
//			cout << ql->MAMH << endl;
//			if(strcmp(ql->MAMH, quest.mamh) != 0)
//			{
//				for(ql = FirstMT; ql->next != NULL; ql = ql->next);
//				insertAfter(ql, quest.mamh);
//			}
			insertAVLTree(root, id, quest);
		}
//		addID(ql->info, id);
	}
	
	ifs.close();
}

void Normal () {
	SetColor(WHITE);
	SetBGColor(0);
}

void HighLight () {
	SetColor(15);
	SetBGColor(1);
}

int MenuDong(char td [][50]) {
	Normal();
	system("cls");
	cout << "\t\t==============THI TRAC NGHIEM==============";
	int chon =0, so_item;
	int i;
	so_item = c_a_r(td);
	for ( i=0; i< so_item ; i++) {
		gotoxy(cot, dong +i);
		cout << td[i];
	}
	HighLight();
	gotoxy(cot,dong+chon);
	cout << td[chon];
	char kytu;
	do {
		kytu = getch();
		if (kytu == 0) kytu = getch();
		switch (kytu) {
			case Up :
				if (chon+1 >1) {
					Normal();
					gotoxy(cot,dong+chon);
					cout << td[chon];
					chon --;
					HighLight();
					gotoxy(cot,dong+chon);
					cout << td[chon];

				}
				break;
			case Down :
				if (chon + 1 <so_item) {
					Normal();
					gotoxy(cot,dong+chon);
					cout << td[chon];
					chon ++;
					HighLight();
					gotoxy(cot,dong+chon);
					cout << td[chon];
				}
				break;
			case 13 :
				return chon+1;
			case 27:
				system("cls");
				return 0;
		}  // end switch
	} while (1);
}

void BaoLoi(char *S){
	int x = wherex(), y = wherey();
	int x1 = wherex(), y1 = wherey() + 5;
	gotoxy(40, y1);
	cout<<S;
	Sleep(2000);
	gotoxy(40, y1);
	cout <<"                                                                ";
	gotoxy(x + 1, y + 1);
}

int NhapMa(char *x, int n_max)
{
	char c;
	int i = 0;
	int x1 = 0,y1 = 0, x2 = 0,y2 = 0;
	char answer;
	while(1)
	{
		c = getch();
		if (c == ESC)
		{
			x = "";			
			return ESC;
		}
		else if (c == ENTER)
		{
			if (i == 0){
				cout << "Ban chua nhap chuoi, moi nhap lai!!" << endl;
				Sleep(2000);
				continue;
			}
			x[i] = '\0';
			cout << endl;
			return ENTER;
		}
		else if (c == BSPACE)
		{
			if (i == 0)	continue;
			else 
			{
				--i;
				cout << c << " " << c;
				x[i] = NULL;
				continue;
			}
		}
		else if (c == SPACE){
			BaoLoi("Chuoi can nhap khong duoc chua khoang trang. Xin kiem tra lai");
			continue;		
		}
		else if (i == n_max){
			x1 = wherex();	y1 = wherey();
			x2 = wherex() + 5;	y2 = wherey() + 5;
			gotoxy(x2, y2);
			cout<<"Chuoi can nhap chi chua toi da " << n_max << " ki tu";
			Sleep(1500);
			gotoxy(x2, y2);
			cout <<"                                                                ";
			gotoxy(x1 + 1, y1 + 1);
			continue;
		}
		else if (c < 0){
			c = getch();
			if (c >= 0)
				continue;
		}
		else 
		{
			if ((c >= 48 && c <= 57) || (c >= 65 && c <= 90) || (c >= 97 && c <= 122))// nhap chu, so
				x[i] = c;
			else 
			{
				BaoLoi("Chuoi chi chua chu hoac so. Xin kiem tra lai!");
				continue;			
			}
		}
		if(c != 0){
		x[i] = c;
		cout << x[i];
		}
		++i;
	}
}

int NhapChuoi(char *x, int n_max)
{
	char c;
	int i = 0;
	int x1 = 0,y1 = 0, x2 = 0,y2 = 0;
	while(1)
	{
		c = getch();
		if (c == ESC)
		{
			x = "";
			return ESC;
		}
		else if (c == ENTER)
		{
			if (i == 0)
			{
				BaoLoi("Ban chua nhap chuoi, moi nhap lai!!");
				continue;
			}
			x[i] = '\0';
			cout << endl;
			return ENTER;
		}
		else if (c == BSPACE)
		{
			if (i == 0)	continue;
			else 
			{
				--i;
				cout << c << " " << c;
				x[i] = NULL;
				continue;
			}
		}
		else if (i == n_max){
			x1 = wherex();	y1 = wherey();
			x2 = wherex()+5;	y2 = wherey()+5;
			gotoxy(x2,y2);
			cout<<"Chuoi can nhap chi chua toi da " << n_max << " ki tu";
			Sleep(1500);
			gotoxy(x2, y2);
			cout <<"                                                                ";
			gotoxy(x1 + 1, y1 + 1);
			continue;
		}
		else if (i == 0 && c == SPACE)
		{
			BaoLoi("Ki tu dau tien khong duoc la khoang trang. Xin kiem tra lai!");
			continue;
		}
		else if (c < 0){
			c = getch();
			if(c >= 0)
			continue;
		}
		else 
		{
			if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122) || c == SPACE)// nhap chu
				x[i] = c;
			else 
			{
				BaoLoi("Chuoi chi chua chu cai va dau cach. Xin kiem tra lai!");
				continue;			
			}
		}
		if (c != 0)
			cout<< x[i];
		++i;
	}
}

int NhapPass( char *x, int n_max){
	char c;
	int i = 0;
	int x1 = 0,y1 = 0, x2 = 0,y2 = 0;
	while(1)
	{
		c = getch();
		if (c == ESC)
		{
			x = "";
			break;
		}
	
		else if (c == ENTER)
		{
			if (i == 0){
				BaoLoi("Muc nay khong duoc de trong. Xin kiem tra lai");
				continue;
			}
			x[i] = '\0';
			cout << endl;
			break;
		}
		else if (c == BSPACE)
		{
			if (i == 0)	continue;
			else 
			{
				--i;
				cout << c << " " << c;
				x[i] = NULL;
				continue;
			}
		}
		else if (c == SPACE){
			BaoLoi("Mat khau khong duoc chua khoang trang. Xin kiem tra lai!");
			continue;		
		}
		else if (i==n_max){
			x1=wherex();	y1=wherey();
			x2=wherex()+5;	y2=wherey()+5;
			gotoxy(x2,y2);
			cout<<"Chuoi can nhap chi chua toi da " << n_max << " ki tu";
			Sleep(2000);
			gotoxy(x2,y2);
			cout <<"                                                                ";
			gotoxy(x1 + 1, y1 + 1);
			continue;
		}
		else if (c < 0)
		{
			c = getch();
			if(c >= 0)
				continue;
		}
		else 
		{
			if (c >= 33 && c <= 126)// nhap chu, so, ki tu dac biet
				x[i] = c;
			else 
			{
				BaoLoi("Chuoi chi chua chu hoac so. Xin kiem tra lai!");	
				continue;			
			}
		}
		if(c != 0)
		{
			x[i] = c;
			cout<<"*";
		}
		++i;
	}
}

int DangNhap(dslop DSlop)
{
	char *ID = new char [10];
	char *pass = new char [8];
	int i = 0;
	PTRSV p;
	while(1)
	{
		system("cls");
		cout<<"=======================DANG NHAP======================="<<endl;
		cout<<"Ten dang nhap: ";
		i = NhapMa(ID, 10);
		if(i == ESC)
		{
			xoadong(2, 2);
			cout << "Ban co muon thoat chuong trinh khong?(y/n) ";
			i = NhapMa(ID, 2);
			if(i == ESC || ID[0] == 'n' || ID[0] == 'N')
				continue;
			else if(ID[0] == 'y' || ID[0] == 'Y')
				return 0;
		}
		else if(i == ENTER)
		{
			if(strlen(ID) == 0)
			{
				cout << "Ban chua nhap ID! Moi nhap lai!" << endl;
				Sleep(2000);
				continue;
			}
			
		}
		cout<<"Nhap mat khau: ";
		i = NhapPass(pass, 8);
		if(i == ESC)
		{
			xoadong(2, 2);
			cout << "Ban co muon thoat chuong trinh khong?(y/n) ";
			i = NhapMa(ID, 2);
			if(i == ESC || ID[0] == 'n' || ID[0] == 'N')
				return 0;
			else if(ID[0] == 'y' || ID[0] == 'Y')
				break;
		}
		if(strcmp(ID, "GV") == 0 || strcmp(ID, "gv") == 0)
		{
			if(strcmp(pass, "GV") == 0 || strcmp(pass, "gv") == 0)
			{
				return 2;
			}
			else
			{
				cout << "Mat khau chua dung, moi nhap lai!!" << endl;
				Sleep(2000);
				continue;
			}
		}
		else
		{
			for(i = 0; i < DSlop.n; i++)
			{
				p = searchStudent(DSlop.lop[i].Firstsv, ID);
				if(p != NULL)	break;
			}
			if(p == NULL)
			{
				cout << "ID khong dung, moi nhap lai!!" << endl;
				Sleep(2000);
				continue;
			}
			else
				if(strcmp(pass, p->info.password) == 0)
				{
					return 1;
				}
				else
				{
					cout << "Mat khau khong dung! Moi nhap lai!" << endl;
					Sleep(2000);
					continue;
				}
		}
	}
	delete ID;
	delete pass;
}

//------Class List Proccessing-------

Lop *searchClass(dslop ds, char *x)
{
	int i;
	Lop *result;
	for(i = 0; i < ds.n && strcmp(x, ds.lop[i].MALOP) != 0; ++i);
	return (i==ds.n?result=NULL:result=&ds.lop[i]);
}

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

void printClassList(dslop ds)
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

void deleteClass(dslop &ds, Lop Class)
{
	for(int i = 0; i < ds.n; ++i)
	{
		if(strcmp(ds.lop[i].MALOP, Class.MALOP) == 0)
		{
			moveToLast(ds, i);
			break;
		}
	}
	--ds.n;
}
void moveToLast(dslop &ds, int i)
{
	Lop Class;
	for(; i < ds.n - 1; ++i)
	{
		Class = ds.lop[i];
		ds.lop[i] = ds.lop[i+1];
		ds.lop[i+1] = Class;
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
