#include <iostream>
struct Node
{
    int value;
    Node *next;
};
bool compareLists(Node* headA, Node* headB) {
    Node* curA = headA;
    Node* curB = headB;
    while (curA && curB) {
        if (curA->value!= curB->value) {
            return false;
        }
        curA = curA->next;
        curB = curB->next;
    }
    return curA == NULL && curB == NULL; 
}
int main() {
    Node* listA = new Node();
    listA->value = 1;
    listA->next = new Node();
    listA->next->value = 2;
    listA->next->next = new Node();
    listA->next->next->value = 3;
    listA->next->next->next = NULL;
}