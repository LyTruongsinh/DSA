#include<iostream>
#include<list>
using namespace std;

struct Node {
	int data;
	Node*  next;
};



Node* makeNode(int x) {
	Node* tmp = new Node();
	tmp->data = x;
	tmp->next = NULL;
	return tmp;

}


bool empty(Node* a) {
	return a == NULL;
}

int size(Node* a) {
	int cnt = 0;
	while (a != NULL) {
		cnt++;
		a = a->next; // gan dia chi cua node tiep theo cho node hien tai
	}
	return cnt;
}

// them mot phan tu vao dau list

void insertFirst(Node*& a, int x) {
	Node* tmp = makeNode(x);
	if (a == NULL) {
		a = tmp;
	}
	else {
		tmp->next = a;
		a = tmp;
	}
}

// them pha tu vao cuoi node
void insertLast(Node*& a, int y) {
	Node* temp = makeNode(y);
	if (a == NULL) {
		a = temp;
	}
	else {
		Node* p = a;
		while (p->next != NULL) {
			p = p->next;
		}
		p->next = temp;
	}
}

// them phan tu vao giua node
void insertMiddle(Node*& a, int x, int pos) {
	int n = size(a);
	if (pos <= 0 || pos > n + 1) {
		cout << "NOT" << endl;
	}
	if (n == 1) {
		insertFirst(a,x);
		return;
	}
	else {
		if (n == pos) {
			insertLast(a, x);
			return;
		}
		Node* p = a;
		for (int i = 1; i < pos - 1; i++) {
			p = p->next;
		}
		Node* tp = makeNode(x);
		tp->next = p->next;
		p->next = tp;
	}
}

// xoa phan tu o dau node 
void deleteFirst(Node*& a) {
	if (a == NULL) return;
	else {
		a = a->next;
	}
}
// xoa cuoi node
void delsetaLast(Node*& a) {
	if (a == NULL) return;
	Node* truoc = NULL;
	Node* sau = a;
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
// xoa o giua node
void deleteMiddle(Node*& a, int pos) {
	if (pos <= 0 || pos > size(a)) return;
	Node* truoc = NULL;
	Node* sau = a;
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
 
void in(Node* a) {
	cout << "____________________________\n";
	while (a != NULL) {
		cout << a->data << " ";
		a = a->next;
	}
	cout << endl;
}
//void sort(Node* a) {
//	for (Node* p = a; p->next != NULL; p = p->next) {
//		Node* min = p;
//		for (Node* q = p->next; q != NULL; q = q->next) {
//			if (a->data > min->data) {
//				min = q;
//			}
//		}
//		int temp = min->data;
//		min->data = p->data;
//		p->data = temp;
//	 }
//}


//void sort(Node* a) {
//	int n = size(a);
//	Node* hientai = NULL;
//	Node* ketiep = NULL;
//	hientai = a;
//	for (int i = 1; i <= (n - 1); i++) {
//			ketiep = hientai->next;

//				while (ketiep != NULL) {
//					if (hientai->data > ketiep->data) {
//						swap(hientai->data, ketiep->data);
//					}
//					ketiep = ketiep->next;
//				}
				
//		}
//		hientai = hientai->next;
		
//	}
	
//}

void sort(Node* a) {
	for (Node* p = a; p->next != NULL; p = p->next) {
		for (Node* k = p->next; k != NULL; k = k->next) {
			if (p->data > k->data) {
				swap(p->data, k->data);
			}
		}
	}
}


int main() {
	Node* he = NULL;
	while (1) {
		cout << "-----------NENU-----------\n";
		cout << "0.EXIT\n";
		cout << "1.chen phan tu vao dau\n";
		cout << "2.chen mot phan tu vao cuoi\n";
		cout << "3.chen phan tu vao giua danh sach\n";
		cout << "4.xoa phan tu dau\n";
		cout << "5.xoa phan tu o cuoi\n";
		cout << "6.xoa phan tu o giua\n";
		cout << "7.duyet danh sach\n";
		cout << "8.sap xep danh sach tang dan\n";
		cout << "--------------------------\n";
		cout << "NHAP LUA CHON :"; 
		int lc; cin >> lc;
		if (lc == 1) {
			int x; 
			cout << "nhap gia tri chen :"; cin >> x;
			insertFirst(he, x);
		}
		else {
			if (lc == 2) {
				int x;
				cout << "nhap gia tri chen :"; cin >> x;
				insertLast(he, x);
			}
			else {
				if (lc == 3) {
					int x;
					cout << "nhap gia tri chen :"; cin >> x;
					int pos;
					cout << "nhap vi tri can chen :"; cin >> pos;
					insertMiddle(he, x, pos);
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
									in(he);
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