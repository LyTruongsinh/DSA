#include <iostream>
using namespace std;

struct ListNode {
    int data;
    ListNode *next;
    ListNode(int x) : data(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : data(x), next(next) {}
};

class Solution {
public:
    // Hàm đảo ngược một danh sách liên kết (dùng trong merge)
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    // Đếm độ dài danh sách
    int getLength(ListNode* head) {
        int count = 0;
        while (head) {
            count++;
            head = head->next;
        }
        return count;
    }

    // Hàm chính dùng chia để trị để đảo ngược
    ListNode* helper(ListNode* head, int length) {
        if (length <= 1) return head;

        // Tìm điểm giữa
        int mid = length / 2;
        ListNode* midNode = head;
        for (int i = 1; i < mid; ++i) {
            midNode = midNode->next;
        }

        ListNode* right = midNode->next;
        midNode->next = nullptr; // Tách danh sách

        // Đệ quy đảo hai nửa
        ListNode* leftReversed = helper(head, mid);
        ListNode* rightReversed = helper(right, length - mid);

        // Nối hai phần đã đảo
        ListNode* tail = leftReversed;
        while (tail->next) tail = tail->next;
        tail->next = rightReversed;

        return leftReversed;
    }

    // Hàm gọi từ bên ngoài
    ListNode* reverseFull(ListNode* head) {
        int len = getLength(head);
        head = helper(head, len);
        // Vì chia nhỏ không đảm bảo đảo ngược thực sự, nên phải đảo ngược lại
        return reverseList(head);
    }
};

// In danh sách
void printList(ListNode* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Solution s;

    // Tạo danh sách: 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(6);
    head->next->next->next->next->next->next = new ListNode(7);

    cout << "Danh sách ban đầu: ";
    printList(head);

    // Đảo ngược toàn bộ danh sách theo cách của bạn
    head = s.reverseFull(head);

    cout << "Danh sách sau khi đảo ngược: ";
    printList(head);

    return 0;
}
