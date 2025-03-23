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
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (!head || !head->next)
            return head;

        // Loại bỏ các phần tử trùng ở đầu danh sách
        while (head && head->next && head->val == head->next->val)
        {
            int duplicateVal = head->val;
            while (head && head->val == duplicateVal)
            {
                head = head->next;
            }
        }

        // Nếu danh sách bị xóa hết, trả về nullptr
        if (!head)
            return nullptr;

        ListNode *current = head;

        while (current && current->next)
        {
            if (current->next->next && current->next->val == current->next->next->val)
            {
                int duplicateVal = current->next->val;
                ListNode *temp = current->next;
                while (temp && temp->val == duplicateVal)
                {
                    temp = temp->next;
                }
                current->next = temp;
            }
            else
            {
                current = current->next;
            }
        }

        return head;
    }
};
void printList(ListNode *head)
{
    while (head)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(1);
    head->next->next = new ListNode(2);
    Solution s;
    ListNode *result = s.deleteDuplicates(head);

    printList(result); // In danh sách sau khi loại bỏ phần tử trùng

    return 0;
}
