#include <iostream>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {};
    ListNode(int x) : val(x), next(nullptr) {};
    ListNode(int x, ListNode *next) : val(x), next(next) {};
};
class Solution
{
public:
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (!head || !head->next || k == 0)
            return head;
        // Bước 1: Tính độ dài danh sách
        int n = 1;
        ListNode *tail = head;
        while (tail->next)
        {
            tail = tail->next;
            n++;
        }

        // Bước 2: Giảm số lần xoay (chỉ cần xoay k % n lần)
        k = k % n;
        if (k == 0)
            return head; // Không cần xoay nếu k chia hết cho n

        // Bước 3: Nối tail với head để tạo vòng tròn
        tail->next = head;

        // Bước 4: Tìm vị trí cắt mới (n - k bước từ head)
        ListNode *newTail = head;
        for (int i = 0; i < n - k - 1; i++)
        {
            newTail = newTail->next;
        }

        // Bước 5: Cập nhật head mới và cắt vòng tròn
        head = newTail->next;
        newTail->next = nullptr;

        return head;
    }
};
int main()
{
    Solution s;
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    int k = 2;
    // Cập nhật lại head sau khi xoay
    head = s.rotateRight(head, k);
    // In danh sách sau khi xoay
    ListNode *temp = head;
    while (temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl; // Output đúng: 5 1 2 3 4

    return 0;
}
