#include <iostream>
using namespace std;
struct Node
{
    int value;
    Node *next;
};
Node *extractNodes(Node *head, int threshold)
{
    Node *head1 = new Node{0,nullptr};
    Node *rear = head1;
    Node*temp = head;
    while(temp)
    {
        if(temp->value < threshold)
        {
            Node * insert = new Node{temp->value, nullptr};
            rear->next = insert;
            rear = rear->next;
        }
        temp = temp->next;
    }
    rear->next = nullptr;
    return head1->next;
}
