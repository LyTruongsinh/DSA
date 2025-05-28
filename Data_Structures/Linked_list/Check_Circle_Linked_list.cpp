#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
    Node() : data(0), next(nullptr) {}
    Node(int val) : data(val), next(nullptr) {}
    Node(int val, Node *nextNode) : data(val), next(nextNode) {}
};
bool CheckCircleLinkedList(Node *head)
{
    Node *slow = head;
    Node *fast = head;
    while (fast != NULL && fast->next != NULL) // Kiểm tra fast và fast->next không NULL
    { // Đúng điều kiện
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            return true;
        }
    }
    return false;
}
int main()
{
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = head; // Tạo vòng
    if (CheckCircleLinkedList(head))
    {
        cout << "Linked List has a cycle." << endl;
    }
    else
    {
        cout << "Linked List does not have a cycle." << endl;
    }
    return 0;
}