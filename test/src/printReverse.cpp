#include <iostream>
#include <stack>
using namespace std;
struct Node
{
    int value;
    Node* next;
};
void printReverse(Node* head)
{
    stack<int> s;
    Node* temp = head;
    while(temp != NULL) {
        s.push(temp->value);
        temp = temp->next;
    }
    while(!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
}
int main() {
    Node* head = new Node();
    head->value = 1;
    head->next = new Node();
    head->next->value = 2;
    head->next->next = new Node();
    head->next->next->value = 3;
    head->next->next->next = new Node();
    head->next->next->next->value = 4;
    head->next->next->next->next = NULL;
    printReverse(head);
}