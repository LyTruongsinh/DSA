#include <iostream>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        if (!head || !head->next)
            return false; // Nếu danh sách rỗng hoặc chỉ có 1 node thì không thể có chu kỳ.

        ListNode *slow = head, *fast = head; // Khai báo hai con trỏ
        while (fast && fast->next)
        {                            // Duyệt danh sách đến khi gặp nullptr
            slow = slow->next;       // Con trỏ `slow` đi 1 bước
            fast = fast->next->next; // Con trỏ `fast` đi 2 bước

            if (slow == fast)
                return true; // Nếu `slow` gặp `fast` -> có chu kỳ
        }
        return false; // Nếu `fast` đến nullptr thì không có chu kỳ
    }
};
// Hàm test
int main()
{
    ListNode *head = new ListNode(3);
    ListNode *node2 = new ListNode(2);
    ListNode *node3 = new ListNode(0);
    ListNode *node4 = new ListNode(-4);

    head->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node2; // Tạo chu kỳ

    Solution solution;
    if (solution.hasCycle(head))
    {
        cout << "Có chu kỳ trong danh sách liên kết.\n";
    }
    else
    {
        cout << "Không có chu kỳ trong danh sách liên kết.\n";
    }

    return 0;
}
