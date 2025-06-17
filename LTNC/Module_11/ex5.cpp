#include <iostream>
#include <vector>
using namespace std;
struct Node
{
    int value;
    Node *next;
};
Node *concat(vector<Node *> heads)
{
    Node *newhead = new Node{0, nullptr};
    Node *rear = newhead;
    for (auto x : heads)
    {
        rear->next = x;
        while(rear->next)
        {
            rear = rear->next;
        }
    }
    return newhead->next;
}