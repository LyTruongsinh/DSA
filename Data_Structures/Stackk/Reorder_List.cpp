#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
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
    void reorderList(ListNode *head)
    {
        if (!head || !head->next)
            return;

        // Bước 1: Đưa tất cả các node vào stack
        stack<ListNode *> st;
        ListNode *curr = head;
        while (curr)
        {
            st.push(curr);
            curr = curr->next;
        }

        int n = st.size();
        curr = head;
        for (int i = 0; i < n / 2; ++i)
        {
            ListNode *tailNode = st.top();
            st.pop();

            tailNode->next = curr->next;
            curr->next = tailNode;
            curr = tailNode->next;
        }

        // Cut the list at the end
        if (curr)
            curr->next = nullptr;
    }
};
int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    Solution sol;
    sol.reorderList(head);

    // Print the reordered list
    ListNode *current = head;
    while (current)
    {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;

    return 0;
}