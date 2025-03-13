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
    ListNode *partition(ListNode *head, int x)
    {
        ListNode *smallHead = new ListNode(0); // Dummy node cho danh sách nhỏ hơn x
        ListNode *bigHead = new ListNode(0);   // Dummy node cho danh sách lớn hơn hoặc bằng x
        ListNode *smaller_X = smallHead;
        ListNode *bigger_X = bigHead;
        ListNode *cur = head;

        while (cur != nullptr)
        {
            ListNode *next = cur->next; // Lưu lại node tiếp theo trước khi thay đổi liên kết
            if (cur->val < x)
            {
                smaller_X->next = cur;
                smaller_X = smaller_X->next;
            }
            else
            {
                bigger_X->next = cur;
                bigger_X = bigger_X->next;
            }
            cur = next;
        }

        bigger_X->next = nullptr;   // Đảm bảo danh sách lớn hơn kết thúc đúng
        smaller_X->next = bigHead->next; // Nối danh sách nhỏ hơn với danh sách lớn hơn

        ListNode *newHead = smallHead->next;
        delete smallHead;
        delete bigHead;

        return newHead;
    }
};

int main() {
    // Test case
    ListNode *head = new ListNode(1);
    head->next = new ListNode(4);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(2);
    head->next->next->next->next = new ListNode(5);
}