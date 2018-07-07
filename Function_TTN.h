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
//------Quest tree proccessing (AVL tree)------
PTRQ search(PTRQ root, int id);
PTRQ rotateLeft(PTRQ root);
PTRQ rotateRight(PTRQ ya);
void insertAVLTree(PTRQ &pavltree, int x, cauhoi a);
//------Display Result------
void printString(char *x);
void printStudentList(PTRSV First);
void printSubjectList(PTRMH First);
void PrintClassList(dslop ds);
//------Others------
void stoc(string s, char *c);
void ctos(char *c, string &s);
int NhapChuoi(char *x);
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
				ctos(buffer, x.noidung);
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
				ctos(buffer, x.A);
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
				ctos(buffer, x.B);
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
				ctos(buffer, x.C);
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
				ctos(buffer, x.D);
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
			//code can bang cay con nhanh trai neu chieu cao cua no bi giam
		}
		else if(x > root->id)
		{
			int ah, bh = nodeHeight(root->right);
			removeAVL(root->right, x);
			ah = nodeHeight(root->right);
			if(ah < bh)
				balanceRight(root, ah);
			//code can bang cay con nhanh phai neu chieu cao cua no bi giam
		}
		else
		{
			PTRQ rp;
			rp = root;
			if(rp->right == NULL)	root = rp->left;		//p la nut la hoac la nut chi co cay con ben trai
			else if(rp->left == NULL)	root = rp->right;	//p chi co cay con ben phai
			else
				removeCase3(rp->right, x, rp);			//p co 2 cay con
			delete rp;
		}
		
	}
	
}

//------Others------

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
