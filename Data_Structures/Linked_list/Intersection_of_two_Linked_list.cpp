#include <iostream>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        for (ListNode *a = headA; a != nullptr; a = a->next)
        {
            for (ListNode *b = headB; b != nullptr; b = b->next)
            {
                if (a == b)
                {
                    return a;
                }
            }
        }
        return nullptr;
    }
};
int main()
{
    // Danh sách chung: 8 -> 4 -> 5
    ListNode *intersect = new ListNode(8);
    intersect->next = new ListNode(4);
    intersect->next->next = new ListNode(5);

    // List A: 4 -> 1 -> [8 -> 4 -> 5]
    ListNode *headA = new ListNode(4);
    headA->next = new ListNode(1);
    headA->next->next = intersect;

    // List B: 5 -> 6 -> 1 -> [8 -> 4 -> 5]
    ListNode *headB = new ListNode(5);
    headB->next = new ListNode(6);
    headB->next->next = new ListNode(1);
    headB->next->next->next = intersect;

    Solution s;
    ListNode* result = s.getIntersectionNode(headA, headB);

    return 0;
}
