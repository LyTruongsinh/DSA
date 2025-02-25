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
    ListNode *deleteDuplicates(ListNode *head)
    {
        int index = head->val;
        ListNode *current = head->next;
        ListNode *tail = head;
        bool check = false;
        if(head == NULL) return NULL;
        while (current != NULL)
        {
            if (current->val != index)
            {
                index = current->val;
                tail->next = current;
                tail = tail->next;
                check = true;
            }
            else {
                check = false;
            }
            current = current->next;
        }
        if(check == false) {
            tail->next = NULL;
            return head;
        }
        return head;
    }
    void printList(ListNode *head)
    {
        while (head != NULL)
        {
            cout << head->val << " ";
            head = head->next;
        }
    }
};
int main()
{
    Solution s;
    ListNode *head = new ListNode(0);
    ListNode *tmp = head;
    int n = 10;
    while (n > 0)
    {
        int x;
        cout << " nhap so :";
        cin >> x;
        tmp->next = new ListNode(x);
        tmp = tmp->next;
        n--;
    }
    s.printList(s.deleteDuplicates(head->next));
}