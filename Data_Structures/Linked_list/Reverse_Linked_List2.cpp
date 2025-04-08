#include <iostream>
using namespace std;

struct ListNode {
    int data;
    ListNode *next;
    ListNode(int x) : data(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) return head;

        ListNode dummy(0); // Node giả
        dummy.next = head;
        ListNode* prev = &dummy;

        // Di chuyển prev đến vị trí trước left
        for (int i = 0; i < left - 1; ++i) {
            prev = prev->next;
        }

        ListNode* curr = prev->next;
        ListNode* next = nullptr;
        ListNode* prevNode = nullptr;

        // Đảo ngược danh sách từ left đến right
        for (int i = 0; i <= right - left; ++i) {
            next = curr->next;
            curr->next = prevNode;
            prevNode = curr;
            curr = next;
        }

        // Nối lại danh sách sau khi đảo ngược
        prev->next->next = curr;
        prev->next = prevNode;

        return dummy.next;
    }
};

void printList(ListNode* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Solution s;

    // Tạo danh sách liên kết ban đầu: 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(6);
    head->next->next->next->next->next->next = new ListNode(7);

    cout << "Danh sách ban đầu: ";
    printList(head);

    // Đảo ngược danh sách từ vị trí 2 đến 5
    head = s.reverseBetween(head, 2, 5);

    cout << "Danh sách sau khi đảo ngược từ 2 đến 5: ";
    printList(head);

    return 0;
}
