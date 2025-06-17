#include <iostream>
#include <vector>
using namespace std;
struct Node
{
    int value;
    Node *next;
};
void printReverse(Node *head)
{
    vector<int> print;
    Node *temp = head;
    while (temp)
    {
        print.push_back(temp->value);
        temp = temp->next;
    }
    for(int i = print.size() - 1; i >= 0;i--)
    {
        cout << print[i] << " ";
    }
}