#include <iostream>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
    {
        if (!head || !head->next)
            return head; // Nếu danh sách rỗng hoặc chỉ có 1 node, không cần đổi

        ListNode *dummy = new ListNode(0); // Node giả để dễ thao tác
        dummy->next = head;
        ListNode *prev = dummy;

        while (prev->next && prev->next->next)
        {
            ListNode *first = prev->next;   // Node thứ nhất trong cặp
            ListNode *second = first->next; // Node thứ hai trong cặp

            // Hoán đổi hai node
            first->next = second->next;
            second->next = first;
            prev->next = second;

            // Di chuyển con trỏ đến cặp tiếp theo
            prev = first;
        }

        return dummy->next; // Trả về danh sách sau khi hoán đổi
    }
    void printList(ListNode* head) {
        while (head) {
            cout << head->val << " -> ";
            head = head->next;
        }
        cout << "NULL" << endl;
    }
};
int main()
{   
    Solution s;
    // Test case
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    s.swapPairs(head);
    s.printList(head); // Output: 1 -> 2 -> 3 -> 4 -> NULL
}