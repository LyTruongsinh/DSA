#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
    Node(int val) : data(val), next(nullptr) {}
};
class Solution
{
  public:
    bool hasCycle(ListNode *head)
    {
        Node *slow = head;
        Node *fast = head;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
            {
                return true;
            }
        }
        return false;
    }
};
int main()
{
    Solution solution;
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = head; // Creating a cycle

    if (solution.hasCycle(head))
    {
        cout << "The linked list has a cycle." << endl;
    }
    else
    {
        cout << "The linked list does not have a cycle." << endl;
    }

    // Clean up memory (not necessary in this case due to cycle)
    return 0;
}