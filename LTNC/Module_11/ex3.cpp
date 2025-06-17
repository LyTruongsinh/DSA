#include <iostream>
#include <vector>
using namespace std;
struct Node
{
    int value;
    Node *next;
};
vector<int> linkedListToVector(Node *head)
{
    vector<int> result;
    Node *temp = head;
    while (temp)
    {
        result.push_back(temp->value);
        temp = temp->next;
    }
    return result;
}
Node *vectorToLinkedList(vector<int> values)
{
    Node *head = new Node;
    head->value = 0;
    head->next = nullptr;
    Node *rear = head;
    for (auto x : values)
    {
        Node *insert = new Node{x, nullptr};
        rear->next = insert;
        rear = rear->next;
    }
    return head->next;
}