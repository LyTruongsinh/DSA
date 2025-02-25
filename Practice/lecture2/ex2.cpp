#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Tạo node mới
Node* makeNode(int x) {
    Node* tmp = new Node();
    tmp->data = x;
    tmp->next = NULL;
    return tmp;
}

// Kiểm tra danh sách rỗng
bool empty(Node* a) {
    return a == NULL;
}

// Đếm số phần tử
int size(Node* a) {
    int cnt = 0;
    while (a != NULL) {
        cnt++;
        a = a->next;
    }
    return cnt;
}

// Thêm vào đầu danh sách
void insertFirst(Node*& a, int x) {
    Node* tmp = makeNode(x);
    tmp->next = a;
    a = tmp;
}

// Thêm vào cuối danh sách
void insertLast(Node*& a, int y) {
    Node* temp = makeNode(y);
    if (a == NULL) {
        a = temp;
        return;
    }
    Node* p = a;
    while (p->next != NULL) {
        p = p->next;
    }
    p->next = temp;
}

// Chèn vào giữa danh sách
void insertMiddle(Node*& a, int x, int pos) {
    int n = size(a);
    if (pos < 1 || pos > n + 1) {
        cout << "NOT" << endl;
        return;
    }

    if (pos == 1 && a != NULL) {  // Chèn sau node đầu tiên nếu danh sách không rỗng
        Node* tp = makeNode(x);
        tp->next = a->next;
        a->next = tp;
        return;
    }
    if (pos == 1) {  // Nếu danh sách rỗng, thêm node đầu tiên
        insertFirst(a, x);
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

// Xóa phần tử đầu tiên
void deleteFirst(Node*& a) {
    if (a == NULL) return;
    Node* tmp = a;
    a = a->next;
    delete tmp;
}

// Xóa phần tử cuối cùng
void deleteLast(Node*& a) {
    if (a == NULL) return;
    if (a->next == NULL) {
        delete a;
        a = NULL;
        return;
    }
    Node* p = a;
    while (p->next->next != NULL) {
        p = p->next;
    }
    delete p->next;
    p->next = NULL;
}

// Xóa phần tử giữa danh sách
void deleteMiddle(Node*& a, int pos) {
    int n = size(a);
    if (pos < 1 || pos > n) return;
    if (pos == 1) {
        deleteFirst(a);
        return;
    }
    Node* p = a;
    for (int i = 1; i < pos - 1; i++) {
        p = p->next;
    }
    Node* tmp = p->next;
    p->next = tmp->next;
    delete tmp;
}

// In danh sách
void printList(Node* a) {
    cout << "____________________________\n";
    while (a != NULL) {
        cout << a->data << " ";
        a = a->next;
    }
    cout << endl;
}

int main() {
    Node* he = NULL;
    int lan;
    cin >> lan;
    for (int i = 0; i < lan; i++) {
        string s;
        cin >> s;
        if (s == "insert") {
            int pos, x;
            cin >> pos >> x;
            insertMiddle(he, x, pos + 1);

        }
        if (s == "delete") {
            int pos;
            cin >> pos;
            deleteMiddle(he, pos + 1);
        }
    }
	printList(he);
    return 0;
}
