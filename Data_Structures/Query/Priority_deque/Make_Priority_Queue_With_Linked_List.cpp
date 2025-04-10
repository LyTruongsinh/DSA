#include <iostream>
using namespace std;

// Cấu trúc của một node trong priority queue
struct Node {
    int data;
    int priority;
    Node* next;
};

// Hàm tạo một node mới
Node* newNode(int d, int p) {
    Node* temp = new Node();
    temp->data = d;
    temp->priority = p;
    temp->next = nullptr;
    return temp;
}

// Hàm đẩy phần tử vào hàng đợi ưu tiên theo thứ tự ưu tiên giảm dần
void push(Node*& head, int d, int p) {
    Node* temp = newNode(d, p);

    // Nếu danh sách rỗng hoặc phần tử mới có ưu tiên cao nhất
    if (!head || p > head->priority) {
        temp->next = head;
        head = temp;
    } else {
        // Duyệt danh sách để tìm vị trí chèn
        Node* current = head;
        while (current->next && current->next->priority >= p) {
            current = current->next;
        }
        temp->next = current->next;
        current->next = temp;
    }
}

// Hàm lấy phần tử có độ ưu tiên cao nhất (ở đầu danh sách)
void pop(Node*& head) {
    if (!head) {
        cout << "Queue rỗng!\n";
        return;
    }
    Node* temp = head;
    head = head->next;
    delete temp;
}

// Hàm lấy phần tử có độ ưu tiên cao nhất mà không xóa nó
int peek(Node* head) {
    if (!head) {
        cout << "Queue rỗng!\n";
        return -1;
    }
    return head->data;
}

// Hàm kiểm tra hàng đợi có rỗng không
bool isEmpty(Node* head) {
    return head == nullptr;
}

// Hàm hiển thị hàng đợi
void display(Node* head) {
    while (head) {
        cout << "(" << head->data << ", " << head->priority << ") -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

// Hàm chính
int main() {
    Node* pq = nullptr;

    push(pq, 4, 3);
    push(pq, 5, 2);
    push(pq, 6, 4);
    push(pq, 7, 1);
    

    cout << "Priority Queue ban đầu:\n";
    display(pq);

    cout << "Phần tử có độ ưu tiên cao nhất: " << peek(pq) << endl;

    pop(pq);
    cout << "Sau khi xóa phần tử có độ ưu tiên cao nhất:\n";
    display(pq);

    return 0;
}
