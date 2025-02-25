#include<iostream>
#include<list>
#include<sstream>
#include<iomanip>
using namespace std;

struct Student {
	string name,id;
	double gpa;
};

struct SV {
	Student S;
	SV* next;
};

typedef struct SV* sv;
sv makesv() {
	Student s;
	cout << "nhap thong tin sinh vien : \n";
	cout << "nhao ID :"; cin >> s.id;
	cout << "nhap ten :"; cin.ignore();
	getline(cin, s.name);
	cout << "nhap GPA :"; cin >> s.gpa;
	sv tmp = new SV();
	tmp->S = s;
	tmp->next = NULL;
	return tmp;
}

int size(sv a) {
	int cnt = 0;
	while (a != NULL) {
		cnt++;
		a = a->next; 
	}
	return cnt;
}

void insertFirst(sv & a) {
	sv tmp = makesv();
	if (a == NULL) {
		a = tmp;
	}
	else {
		tmp->next = a;
		a = tmp;
	}
}

void insertLast(sv & a) {
	sv temp = makesv();
	if (a == NULL) {
		a = temp;
	}
	else {
		sv p = a;
		while (p->next != NULL) {
			p = p->next;
		}
		p->next = temp;
	}
}

void insertMiddle(sv& a,  int pos) {
	int n = size(a);
	if (pos <= 0 || pos > n + 1) {
		cout << "NOT" << endl;
	}
	if (n == 1) {
		insertFirst(a);
		return;
	}
	else {
		if (n == pos) {
			insertLast(a);
			return;
		}
		sv p = a;
		for (int i = 1; i < pos - 1; i++) {
			p = p->next;
		}
		sv tp = makesv();
		tp->next = p->next;
		p->next = tp;
	}
}

void deleteFirst(sv& a) {
	if (a == NULL) return;
	else {
		a = a->next;
	}
}

void deleteMiddle(sv& a, int pos) {
	if (pos <= 0 || pos > size(a)) return;
	sv truoc = NULL;
	sv sau = a;
	for (int i = 1; i < pos; i++) {
		truoc = sau;
		sau = sau->next;
	}
	if (truoc == NULL) {
		a = a->next;
	}
	else {
		truoc = sau->next;
	}
}

void delsetaLast(sv& a) {
	if (a == NULL) return;
	sv truoc = NULL;
	sv sau = a;
	while (sau->next != NULL) {
		truoc = sau;
		sau = sau->next;
	}
	if (truoc == NULL) {
		a = NULL;
	}
	else {
		truoc->next = NULL;
	}
}

void in(Student s) {
	cout << "=================================\n";
	cout << "ID : " << s.id << endl;
	cout << "HOTEN : " << s.name << endl;
	cout << "GPA : " << fixed << setprecision(2) << s.gpa << endl;
	cout << "=================================\n";
}

void inds(sv a) {
	cout << "Danh sach sinh vien : \n";
	while (a != NULL) {
		in(a->S);
		a = a->next;
	}
	cout << endl;
	cout << "=================================\n";
}

void sort(sv a) {
	for (sv p = a; p->next != NULL; p = p->next) {
		for (sv k = p->next; k != NULL; k = k->next) {
			if (p->S.gpa > k->S.gpa) {
				swap(p->S.gpa, k->S.gpa);
			}
		}
	}
}

int main() {
	sv he = NULL;
	while (1) {
		cout << "-----------NENU-----------\n";
		cout << "0.EXIT\n";
		cout << "1.chen sinh vien vao dau\n";
		cout << "2.chen mot sinh vien vao cuoi\n";
		cout << "3.chen sinh vien vao giua danh sach\n";
		cout << "4.xoa sinh vien dau\n";
		cout << "5.xoa sinh vien o cuoi\n";
		cout << "6.xoa sinh vien o giua\n";
		cout << "7.duyet danh sach\n";
		cout << "8.sap xep danh sach tang dan theo gpa \n";
		cout << "--------------------------\n";
		cout << "NHAP LUA CHON :";
		int lc; cin >> lc;
		if (lc == 1) {
			int x;
			insertFirst(he);
		}
		else {
			if (lc == 2) {
				insertLast(he);
			}
			else {
				if (lc == 3) {
					int pos;
					cout << "nhap vi tri can chen :"; cin >> pos;
					insertMiddle(he, pos);
				}
				else {
					if (lc == 4) {
						deleteFirst(he);
					}
					else {
						if (lc == 5) {
							delsetaLast(he);
						}
						else {
							if (lc == 6) {
								int pos;
								cout << "nhap vi tri can xoa :"; cin >> pos;
								deleteMiddle(he, pos);
							}
							else {
								if (lc == 7) {
									inds(he);
								}
								else {
									if (lc == 8) {
										sort(he);
									}
									else {
										if (lc == 0) {
											cout << "EXIT" << endl;
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	return 0;
}
