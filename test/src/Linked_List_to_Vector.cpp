#include <iostream>
#include <vector>
using namespace std;
struct Node
{
    int value;
    Node *next;
};
vector<int> linkedListToVector(Node* head) {
    vector<int> result;
    while(head) {
        result.push_back(head->value);
        head = head->next;
    }
    return result;
}

Node* vectorToLinkedList(vector<int> values) {
    Node* head = new Node();
    head->value = values[0];
    head->next = NULL;
    Node* current = head;
    for(int i = 1; i < values.size(); i++) {
        Node* temp = new Node();
        temp->value = values[i];
        temp->next = NULL;
        current->next = temp;
        current = current->next;
    }
    return head;
}

int main() {
    vector<int> values = {1, 2, 3, 4, 5};
    Node* head = vectorToLinkedList(values);
    while (head)
    {
        cout << head->value;
        head = head->next;
    }
    cout << endl;
    vector<int> result = linkedListToVector(head);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    return 0;
}