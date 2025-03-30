#include <iostream>
using namespace std;

// Định nghĩa Node của danh sách liên kết
struct Node {
    int data;
    Node* next;
};

// Hàm tạo node mới
Node* createNode(int val) {
    Node* newNode = new Node;
    newNode->data = val;
    newNode->next = nullptr;
    return newNode;
}

// Hàm tìm và chuyển đổi danh sách liên kết
Node* convert(Node* head) {
    if (!head || !head->next) return head; // Nếu danh sách rỗng hoặc chỉ có 1 phần tử, trả về luôn

    // Bước 1: Tìm điểm giữa (b1)
    Node *slow = head, *fast = head;
    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Chia danh sách thành hai phần
    Node *first = head;
    Node *second = slow->next;
    slow->next = nullptr; // Cắt danh sách

    // Bước 2: Merge hai danh sách
    Node* dummy = new Node;
    Node* curr = dummy;
    
    while (first || second) {
        if (first) {
            curr->next = first;
            first = first->next;
            curr = curr->next;
        }
        if (second) {
            curr->next = second;
            second = second->next;
            curr = curr->next;
        }
    }

    return dummy->next; // Trả về danh sách đã sắp xếp
}

// Hàm in danh sách liên kết
void printList(Node* head) {
    while (head) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

// Hàm main kiểm thử
int main() {
    // Tạo danh sách liên kết: 1 -> 2 -> 3 -> 4 -> 5 -> 6
    Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);
    head->next->next->next->next->next = createNode(6);

    cout << "Danh sách ban đầu: ";
    printList(head);

    head = convert(head);

    cout << "Danh sách sau khi chuyển đổi: ";
    printList(head);

    return 0;
}
