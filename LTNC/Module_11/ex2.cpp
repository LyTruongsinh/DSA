#include <iostream>
using namespace std;
struct Node
{
    int value;
    Node *next;
};
bool compareLists(Node *headA, Node *headB)
{
    Node *tempA = headA;
    Node *tempB = headB;
    while (tempA && tempB)
    {
        if (tempA->value != tempB->value)
        {
            return false;
        }
        tempA = tempA->next;
        tempB = tempB->next;
    }
    if ((!tempA && tempB) || (!tempB && tempA))
    {
        return false;
    }
    return true;
}
