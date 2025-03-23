#include <iostream>
using namespace std;
struct Node
{
    int value;
    Node *next;
};
Node* convert(Node* head) {
    if(head == nullptr || head->next == nullptr) return head;
    // Tìm điểm chính giữa danh sách 
    Node* slow = head;
    Node* fast = head;
    while(fast->next != nullptr && fast->next->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }
    // Tách thành 2 thành phần
    Node* head2 = slow->next;
    slow->next = nullptr; // cắt liên kết

    // Hợp 2 danh sách 
    Node* p1 = head;
    Node* p2 = head2;
    while(p2 != nullptr) {
        Node* temp1 = p1->next;
        Node* temp2 = p2->next;
        p1->next = p2;
        if(temp1 != nullptr) {
            p2->next = temp1; 
        }
        p1 = temp1;
        p2 = temp2;
    }
    return head;
}
int main() {
    Node* head = new Node();
    head->value = 1;
    head->next = new Node();
    head->next->value = 2;
    head->next->next = new Node();
    head->next->next->value = 3;
    head->next->next->next = new Node();
    head->next->next->next->value = 4;
    head->next->next->next->next = new Node();
    head->next->next->next->next->value = 5;
    head->next->next->next->next->next = nullptr;
    Node* result = convert(head);
    while(result != nullptr) {
        cout << result->value << " ";
        result = result->next;
    }
    return 0;
}

// EXMAMPLE 1 -> 4 -> 2 -> 5 -> 3 -> 6
// Ý TƯỞNG BÀI TOÁN
// TÌM ĐIỂM CHÍNH GIỮA 
// TÁCH HAI DANH SÁCH 
// 1 -> 4 -> 2
// 5 -> 3 -> 6 
// LẤY ĐẦU DANH SÁCH NÀY TRỎ VÀO ĐẦU DANH SÁCH KIA 
// 1 -> 5 -> 3 -> 6 BƯỚC (*)
// LẤY 2 DANH SÁCH MỚI 4 -> 2 VÀ 3 -> 6 
// LẠI LẤY ĐẦU DANH SÁCH NÀY TRỎ VÀO ĐẦU DANH SÁCH KIA 
// 4 -> 3 -> 6 BƯỚC(**)

// BÀI TOÁN ĐẶT RA LÀ LÀM KIỂU GÌ ĐỂ LIÊN KẾT THÀNH 1 -> 5 -> 4 -> 3
// VẬY Ở BƯỚC (*) TA CẦN LIÊN KẾT 5 VỚI 4 TRƯỚC KIA CHO RA DANH SÁCH MỚI 1 -> 5 -> 4 -> 2
// KẾT HỢP VỚI BƯỚC (**) TA ĐƯỢC 1 -> 5 -> 4 -> 3 -> 6

// LẤY HAI DANH SÁCH MỚI LÀ 2 VÀ 6
// TRƯỚC KHI LIÊN KẾT HAI VỚI 6 CẦN TRỎ 2 VỚI 2 
// CHO 2 -> 6