#include <iostream>
using namespace std;
struct Node {
    int value;
    Node* next;
};
Node* extractNodes(Node* head, int threshold) 
{
    Node* result = new Node();
    result->value = 0;
    result->next = NULL;
    Node* current = result;
    Node* temp = head;
    while(temp != NULL) {
        if(temp->value < threshold) {
            current->next = new Node();
            current = current->next;
            current->value = temp->value;
            current->next = NULL;
        }
        temp = temp->next;
    }
    result = result->next; // remove the extracted nodes from original list
    return result;
}
void print(Node* head) {
    Node* temp = head;
    while(temp != NULL) {
        cout << temp->value << " ";
        temp = temp->next;
    }
    cout << endl;
}
int main() {
    Node* head = new Node();
    head->value = 3;
    head->next = new Node();
    head->next->value = 2;
    head->next->next = new Node();
    head->next->next->value = 1;
    head->next->next->next = new Node();
    head->next->next->next->value = 4;
    head->next->next->next->next = NULL;
    Node* newHead = extractNodes(head, 3);
    print(newHead); // Output: 1 2 4
    return 0;
}